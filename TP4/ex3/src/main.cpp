#include "Vecteur.hpp"

int main(void) {
    Point2D pt0(0, 0), pt1(3, 4), pt2(5, 8);
    Vecteur v0(pt0, pt2), v1(pt1, pt2);
    v0.print("v0");
    v1.print("v1");
    cout << "v1 == (0,0) : " << (v1 == Vecteur(pt1, pt2) ? "Yes" : "No") << endl;
    (v0 + v1).print("v0 + v1");
    (v0 * 2).print("v0 * 2");

    return 0;
}
