#include <iostream>
#include <algorithm>
#include <sstream>
#include <set>
#include <string>
#include <cmath>
#include <fstream>

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

        static Fraction<T> getTotalSum(const set<Fraction<T>> fracs);
        static Fraction<T> getMin(const set<Fraction<T>> fracs);
        static Fraction<T> getMax(const set<Fraction<T>> fracs);

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
        bool operator>=(const Fraction<T>&) const;
        bool operator>=(const T&) const;
        bool operator<(const Fraction<T>&) const;
        bool operator<=(const Fraction<T>&) const;
        bool operator<=(const T&) const;

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

template<typename T> Fraction<T> Fraction<T>::getTotalSum(const set<Fraction<T>> fracs) {
    Fraction<T> sum;
    set<Fraction<float>>::iterator it = fracs.begin();
    while (it != fracs.end()) sum += *it++;
    return sum;
}

template<typename T> Fraction<T> Fraction<T>::getMin(const set<Fraction<T>> fracs) {
    Fraction<float> min;
    if (!fracs.empty())
        min = *fracs.begin();
    return min;
}

template<typename T> Fraction<T> Fraction<T>::getMax(const set<Fraction<T>> fracs) {
    Fraction<T> max;
    if (!fracs.empty())
        max = *(fracs.rbegin());
    return max;
}

template<typename T> Fraction<T> Fraction<T>::operator+(const Fraction<T>& frac) {
    return Fraction(this->n * frac.getDenumerator() + frac.getNumerator() * this->d, this->d * frac.getDenumerator());
}

template<typename T> Fraction<T> Fraction<T>::operator+=(const Fraction<T>& frac) {
    this->n = this->n * frac.getDenumerator() + frac.getNumerator() * this->d;
    this->d = this->d * frac.getDenumerator();
    return Fraction(this->n * frac.getDenumerator() + frac.getNumerator() * this->d, this->d * frac.getDenumerator());
}

template<typename T> Fraction<T> Fraction<T>::operator-(const Fraction<T>& frac) {
    return Fraction(this->n * frac.getDenumerator() - frac.getNumerator() * this->d, this->d * frac.getDenumerator());
}

template<typename T> Fraction<T> Fraction<T>::operator-=(const Fraction<T>& frac) {
    this->n = this->n * frac.getDenumerator() - frac.getNumerator() * this->d;
    this->d = this->d * frac.getDenumerator();
    return Fraction(this->n * frac.getDenumerator() - frac.getNumerator() * this->d, this->d * frac.getDenumerator());
}

template<typename T> Fraction<T> Fraction<T>::operator*(const Fraction<T>& frac) {
    return Fraction(this->n * frac.getNumerator(), this->d * frac.getDenumerator());
}

template<typename T> Fraction<T> Fraction<T>::operator*=(const Fraction<T>& frac) {
    this->n = this->n * frac.getNumerator();
    this->d = this->d * frac.getDenumerator();
    return Fraction(this->n * frac.getNumerator(), this->d * frac.getDenumerator());
}

template<typename T> Fraction<T> Fraction<T>::operator/(const Fraction<T>& frac) {
    return Fraction(this->n * frac.getDenumerator(), this->d * frac.getNumerator());
}

template<typename T> Fraction<T> Fraction<T>::operator/=(const Fraction<T>& frac) {
    this->n = this->n * frac.getDenumerator();
    this->d = this->d * frac.getNumerator();
    return Fraction(this->n * frac.getDenumerator(), this->d * frac.getNumerator());
}

template<typename T> bool Fraction<T>::operator==(const Fraction<T> &frac){
    return (this->n * frac.getDenumerator() == this->d * frac.getNumerator());
}

template<typename T> bool Fraction<T>::operator!=(const Fraction<T>& frac) {
    return !(*this == frac);
}

template<typename T> bool Fraction<T>::operator>(const Fraction<T>& frac)  {
    return this->n / this->d > frac.getNumerator() / frac.getDenumerator();
}

template<typename T> bool Fraction<T>::operator>=(const Fraction<T>& frac) const {
    return this->n / this->d >= frac.getNumerator() / frac.getDenumerator();
}
template<typename T> bool Fraction<T>::operator>=(const T& n) const {
    return this->n / this->d >= n;
}

template<typename T> bool Fraction<T>::operator<(const Fraction<T>& frac) const {
    return this->n / this->d < frac.getNumerator() / frac.getDenumerator();
}

template<typename T> bool Fraction<T>::operator<=(const Fraction<T>& frac) const {
    return this->n / this->d <= frac.getNumerator() / frac.getDenumerator();
}
template<typename T> bool Fraction<T>::operator<=(const T& n) const {
    return this->n / this->d <= n;
}
