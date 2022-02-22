#include <iostream>

using namespace std;

class A {
    protected:
        int x;
    public:
        A() { x = 0; cout << "1"; }
        A(int px) { x = px; cout << "2"; }
        A(const A& pa) { x = pa.x; cout << "3"; }

};

class B {
    protected:
        A a;
        int y;
    public:
        B(const A& pa = A()) : a(pa) { cout << "4"; }
        B(const A& pa, int py) { a = pa; y = py; cout << "5"; }

};

class C : public B {
    protected:
        A a;
        int z;
    public:
        C(int pz = 1) { z = pz; cout << "6"; }
        C(A pa) : B(pa) { z = 0; cout << "7"; }
        C(const B& pb) : B(pb), a(1) { z = 0; cout << "8"; }

};

int main() {
    cout << "-- A --\n";

    A a0; cout << endl; // Constructeur n°1 de la classe A => "1"
    A a1(3); cout << endl; // Constructeur n°2 de la classe A => "2"
    A a2(a1); cout << endl; // Constructeur n°3 de la classe A => "3"
    A a3 = a2; cout << endl; // Constructeur n°3 de la classe A => "3"
    a3 = a1; cout << endl; // Copie des attributs de a1 dans a3 (écrase les données pré-éxistantes)

    cout << "-- B --\n";

    // Constructeur n°1 de la classe A => "1"
    // (appelé avec `a = pa;`) [l.21]
    // + Constructeur n°2 de la classe B => "5"
    B b0(a0, 3); cout << endl;
    // Constructeur n°3 de la classe A => "3"
    // (appelé avec `a(pa)`) [l.20]
    // + Constructeur n°1 de la classe B => "4"
    B b1(a1); cout << endl;
    // Constructeur n°1 de la classe A => "1"
    // (appelé avec `const A& pa = A()`) [l.20]
    // + Constructeur n°3 de la classe A => "3"
    // (appelé avec `a(pa)`) [l.20]
    // + Constructeur n°1 de la classe B => "4"
    B b2; cout << endl;

    cout << "\n-- C --\n";

    // "134" => voir ligne 60
    // + Constructeur n°1 de la classe A => "1"
    // (appelé à cause de l'attribut `A a;`) [l.27]
    // + Constructeur n°1 de la classe C => "6"
    C c0; cout << endl;
    // Constreur n°3 de la classe A => "3"
    // + Constructeur n°1 de la classe B => "4"
    // (via `B(pa)` [l.31] + `a(pa)` [l.20])
    // + Constructeur n°1 de la classe A => "1"
    // (via `A a;` [l.27])
    // + Constructeur n°2 de la classe C => "7"
    C c1(a1); cout << endl;
    // Constreur n°3 de la classe A => "3"
    // (copie de `b2` via `B(pb)` [l.32] donc copie de sa propriété `a`)
    // + Constreur n°2 de la classe A => "2"
    // (via `a(1)` [l.32])
    // + Constreur n°3 de la classe C => "8"
    C c2(b2); cout << endl;

    return EXIT_SUCCESS;
}
