#include "Point.hpp"

float Point::distanceTo(const Point& to) const {
    return sqrt(pow(to.getX() - x, 2) + pow(to.getY() - y, 2));
}

Point Point::operator+(const Point& p) {
    return Point(x + p.getX(), y + p.getY());
}

Point Point::operator*(const float& n) {
    return Point(x * n, y * n);
}

Point Point::operator|(const Point& p) {
    return (*this + p) * (float(1) / 2);
}

ostream& operator<<(ostream& stream, const Point& p) {
    stream << "(" << p.getX() << SEPARATOR << p.getY() << ")";
    return stream;
}

istream& operator>>(istream& stream, Point& p) {
    float x, y;
    cout << "x : ";
    stream >> x;
    cout << "y : ";
    stream >> y;
    p.setX(x);
    p.setY(y);
    cout << p << endl;
    return stream;
}

Point operator*(const float& n, const Point& p) {
    return Point(p.getX() * n, p.getY() * n);
}

Point Point::getCenterOfGravity(vector<Point> points) {
    float x_average(0), y_average(0);
    Point current_point;

    for (size_t i = 0; i < points.size(); i++) {
        current_point = points.at(i);
        x_average += current_point.getX();
        y_average += current_point.getY();
    }

    return Point(x_average / points.size(), y_average / points.size());
}
