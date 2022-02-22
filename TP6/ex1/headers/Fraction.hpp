#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

template <typename T>
class Fraction {
    private:
        T n, d;

    public:
        Fraction(const T& _n = 0, const T& _d = 1);
        T getNumerator() const { return n; }
        void setNumerator(const T& _n) { n = _n; }
        T getDenumerator() const { return d; }
        void setDenumerator(const T& _d) { d = _d == 0 ? 1 : _d; }

        Fraction<T> operator+(const Fraction<T>&);
        Fraction<T> operator+=(const Fraction<T>&);
        Fraction<T> operator-(const Fraction<T>&);
        Fraction<T> operator-=(const Fraction<T>&);
        Fraction<T> operator*(const Fraction<T>&);
        Fraction<T> operator*=(const Fraction<T>&);
        Fraction<T> operator/(const Fraction<T>&);
        Fraction<T> operator/=(const Fraction<T>&);

        bool operator==(const Fraction<T>&);
        bool operator!=(const Fraction<T>&);
        bool operator>(const Fraction<T>&);
        bool operator>=(const Fraction<T>&);
        bool operator<(const Fraction<T>&);
        bool operator<=(const Fraction<T>&);

        operator int() { return int(n)/d; }
        operator float() { return float(n)/d; }
        operator double() { return double(n)/d; }

        friend ostream& operator<<(ostream& stream, const Fraction<T>& frac) {
            stream << frac.getNumerator() << '/' << frac.getDenumerator();
            return stream;
        }
        friend istream& operator>>(istream& is, Fraction<T>& frac) {
            T n, d;
            cout << "Num : ";
            is >> n;
            cout << "Den : ";
            is >> d;
            frac.setNumerator(n);
            frac.setDenumerator(d);
            cout << frac << endl;
            return is;
        }

};

template<typename T> Fraction<T>::Fraction(const T& _n, const T& _d) {
    n = _n;
    d = _d == 0 ? 1 : _d;
}

template<typename T> Fraction<T> Fraction<T>::operator+(const Fraction<T>& frac) {
    return Fraction(n * frac.getDenumerator() + frac.getNumerator() * d, d * frac.getDenumerator());
}

template<typename T> Fraction<T> Fraction<T>::operator+=(const Fraction<T>& frac) {
    n = n * frac.getDenumerator() + frac.getNumerator() * d;
    d = d * frac.getDenumerator();
    return Fraction(n * frac.getDenumerator() + frac.getNumerator() * d, d * frac.getDenumerator());
}

template<typename T> Fraction<T> Fraction<T>::operator-(const Fraction<T>& frac) {
    return Fraction(n * frac.getDenumerator() - frac.getNumerator() * d, d * frac.getDenumerator());
}

template<typename T> Fraction<T> Fraction<T>::operator-=(const Fraction<T>& frac) {
    n = n * frac.getDenumerator() - frac.getNumerator() * d;
    d = d * frac.getDenumerator();
    return Fraction(n * frac.getDenumerator() - frac.getNumerator() * d, d * frac.getDenumerator());
}

template<typename T> Fraction<T> Fraction<T>::operator*(const Fraction<T>& frac) {
    return Fraction(n * frac.getNumerator(), d * frac.getDenumerator());
}

template<typename T> Fraction<T> Fraction<T>::operator*=(const Fraction<T>& frac) {
    n = n * frac.getNumerator();
    d = d * frac.getDenumerator();
    return Fraction(n * frac.getNumerator(), d * frac.getDenumerator());
}

template<typename T> Fraction<T> Fraction<T>::operator/(const Fraction<T>& frac) {
    return Fraction(n * frac.getDenumerator(), d * frac.getNumerator());
}

template<typename T> Fraction<T> Fraction<T>::operator/=(const Fraction<T>& frac) {
    n = n * frac.getDenumerator();
    d = d * frac.getNumerator();
    return Fraction(n * frac.getDenumerator(), d * frac.getNumerator());
}

template<typename T> bool Fraction<T>::operator==(const Fraction<T> &frac){
    return (n * frac.getDenumerator() == d * frac.getNumerator());
}

template<typename T> bool Fraction<T>::operator!=(const Fraction<T>& frac) {
    return !(*this == frac);
}

template<typename T> bool Fraction<T>::operator>(const Fraction<T>& frac) {
    return n / d > frac.getNumerator() / frac.getDenumerator();
}

template<typename T> bool Fraction<T>::operator>=(const Fraction<T>& frac) {
    return n / d >= frac.getNumerator() / frac.getDenumerator();
}

template<typename T> bool Fraction<T>::operator<(const Fraction<T>& frac) {
    return n / d < frac.getNumerator() / frac.getDenumerator();
}

template<typename T> bool Fraction<T>::operator<=(const Fraction<T>& frac) {
    return n / d <= frac.getNumerator() / frac.getDenumerator();
}
