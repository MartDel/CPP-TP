#include "Point2D.hpp"

class Line {
    private:
        float a, b;
        const Point2D p1, p2;
        bool is_vertical = false;

    public:
        Line(const Point2D& p1, const Point2D& p2);
        float getA() const { return a; }
        float getB() const { return b; }
        Point2D getP1() const { return p1; }
        Point2D getP2() const { return p2; }
        bool isVertical() const { return is_vertical; }

        Point2D* intersection(const Line&) const;
        bool isPointBetweenStartPoints(const Point2D&) const;
};
