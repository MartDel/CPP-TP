#include "Line.hpp"

class Polygon {
    private:
        Point2D* corners;
        size_t nb_corners;

        int crossProduct(const Point2D&, const Point2D&, const Point2D&) const;

    public:
        Polygon(Point2D* _corners, const size_t& _nb_corners);
        ~Polygon() { delete [] corners; }
        size_t getNbCorners() const { return nb_corners; }

        float getArea() const;
        float getPerimeter() const;
        bool isConvex() const;
        bool isPointInPolygon(const Point2D&) const;
        void print() const;
};
