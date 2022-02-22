#include "Fraction.hpp"

int main(void) {

    Fraction<int> f1, f2;
    cin >> f1;
    cin >> f2;

    cout << "f1 + f2 : " << f1 + f2 << endl;
    f1 += f2;
    cout << "f1 = f1 + f2" << endl;
    cout << "f1 = " << f1 << endl << endl;

    cout << "f2 - f1 : " << f2 - f1 << endl;
    f2 -= f1;
    cout << "f2 = f1 - f2" << endl;
    cout << "f2 = " << f2 << endl << endl;

    cout << "f1 * f2 : " << f1 * f2 << endl;
    f1 *= f2;
    cout << "f1 = f1 * f2" << endl;
    cout << "f1 = " << f1 << endl << endl;

    cout << "f1 / f2 : " << f1 / f2 << endl;
    f1 /= f2;
    cout << "f1 = f1 / f2" << endl;
    cout << "f1 = " << f1 << endl << endl;

    cout << "f2 (int) = " << int(f2) << endl;
    cout << "f2 (float) = " << float(f2) << endl;
    cout << "f2 (double) = " << double(f2) << endl << endl;

    cout << "f1 == f2 : " << (f1 == f2 ? "Yes" : "No") << endl;
    cout << "f1 != f2 : " << (f1 != f2 ? "Yes" : "No") << endl;
    cout << "f1 < f2 : " << (f1 < f2 ? "Yes" : "No") << endl;
    cout << "f1 <= f2 : " << (f1 <= f2 ? "Yes" : "No") << endl;
    cout << "f1 > f2 : " << (f1 > f2 ? "Yes" : "No") << endl;
    cout << "f1 >= f2 : " << (f1 >= f2 ? "Yes" : "No") << endl;

    return 0;
}
