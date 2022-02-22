#include "Point2D.hpp"

Point2D::Point2D(){
    x = rand() % 100;
    y = rand() % 100;
}

float Point2D::distanceTo(const Point2D& to) const {
    return sqrt(pow(to.getX() - x, 2) + pow(to.getY() - y, 2));
}

void Point2D::print() const {
    cout << "(" << x << ";" << y << ")" << endl;
}
