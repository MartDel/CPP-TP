#include "Line.hpp"

Line::Line(const Point2D& _p1, const Point2D& _p2) : p1(_p1), p2(_p2) {
    if (_p1.getX() == _p2.getX()) {
        is_vertical = true;
        a = _p1.getX();
        b = 0;
    } else {
        a = (_p2.getY() - _p1.getY()) / (_p2.getX() - _p1.getX());
        b = _p1.getY() - (a * _p1.getX());
    }
}

Point2D* Line::intersection(const Line& l) const {
    if ((is_vertical && l.isVertical()) || (!is_vertical && !l.isVertical() && a == l.getA())) return NULL;
    float x, y;
    if (is_vertical) x = a;
    else if (l.isVertical()) x = l.getA();
    else x = (l.getB() - b) / (a - l.getA());
    y = a * x + b;
    return new Point2D(x, y);
}

bool Line::isPointBetweenStartPoints(const Point2D& p) const {
    // 'p' must be on the line
    if (!is_vertical && a * p.getX() + b != p.getY()) return false;
    return (p.getX() >= min(p1.getX(), p2.getX()) && p.getX() <= max(p1.getX(), p2.getX()));
        // && (p.getY() >= min(p1.getY(), p2.getY()) && p.getY() <= max(p1.getY(), p2.getY()));
}
