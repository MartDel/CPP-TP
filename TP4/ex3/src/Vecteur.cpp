#include "Vecteur.hpp"

Vecteur::Vecteur(const Point2D& a, const Point2D& b){
    x = b.getX() - a.getX();
    y = b.getY() - a.getY();
}

void Vecteur::print(const string& name) const {
    cout << name << " : (" << x << "," << y << ")" << endl;
}

bool Vecteur::operator==(const Vecteur& v) const{
    return x == v.getX() && y == v.getY();
}

Vecteur Vecteur::operator+(const Vecteur& v) const{
    Point2D from(0, 0), to(x+v.getX(), y+v.getY());
    return Vecteur(from, to);
}

Vecteur Vecteur::operator*(const float& a) const{
    Point2D from(0, 0), to(x * a, y * a);
    return Vecteur(from, to);
}
