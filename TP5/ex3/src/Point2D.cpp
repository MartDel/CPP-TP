#include "Point2D.hpp"

float Point2D::distanceTo(const Point2D& to) const {
    return sqrt(pow(to.getX() - x, 2) + pow(to.getY() - y, 2));
}

void Point2D::print() const {
    cout << "(" << x << ";" << y << ")" << endl;
}

bool Point2D::operator==(const Point2D& p) const {
    return x == p.getX() && y == p.getY();
}
