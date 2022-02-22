#include "Polygon.hpp"

Polygon::Polygon(Point2D* _corners, const size_t& _nb_corners) : nb_corners(_nb_corners){
    corners = new Point2D[nb_corners];
    for (size_t i = 0; i < nb_corners; i++) {
        corners[i] = _corners[i];
    }
}
float Polygon::getArea() const {
    float sum = 0;
    for (size_t i = 0; i < nb_corners; i++) {
        Point2D pi = corners[i];
        Point2D pi1 = corners[i == nb_corners-1 ? 0 : i+1];
        sum += (pi.getX() * pi1.getY() - pi1.getX() * pi.getY());
    }
    return abs(sum / float(2));
}

float Polygon::getPerimeter() const {
    float perimeter = 0;
    for (size_t i = 0; i < nb_corners; i++) {
        Point2D pi = corners[i];
        Point2D pi1 = corners[i == nb_corners-1 ? 0 : i+1];
        perimeter += pi.distanceTo(pi1);
    }
    return perimeter;
}

bool Polygon::isConvex() const {
    Point2D a, b, c;
    int cross_product;
    bool neg = false, pos = false;
    for(size_t i = 0; i < nb_corners; i++){
         a = corners[i];
         b = corners[(i + 1) % nb_corners];
         c = corners[(i + 2) % nb_corners];
         cross_product = crossProduct(a, b, c);
         if(cross_product < 0) neg = true;
         else if(cross_product > 0) pos = true;
         if(neg && pos) return false;
     }
     return true;
}

bool Polygon::isPointInPolygon(const Point2D& p) const {
    // Test if 'p' is a corner
    for (size_t i = 0; i < nb_corners; i++) {
        if (corners[i] == p) return true;
    }

    // Store all of polygon sides equations
    vector<Line> polygon_sides;
    for (size_t i = 0; i < nb_corners; i++) {
        Point2D pi = corners[i];
        Point2D pi1 = corners[i == nb_corners-1 ? 0 : i+1];
        polygon_sides.push_back(Line(pi, pi1));
    }

    Line h(p, Point2D(0, p.getY()));
    size_t nb_cross(0);
    // Count intersection between polygon sides and the line y = Py
    for (size_t i = 0; i < nb_corners; i++) {
        Point2D* intersection = h.intersection(polygon_sides[i]);
        // An intersection (I) is important if it's before the checked point (P) : Ix <= Px
        if (intersection != NULL && polygon_sides[i].isPointBetweenStartPoints(*intersection) && intersection->getX() <= p.getX())
            nb_cross++;
    }

    // If the count of intersection is even, the point isn't inside the polygon
    return nb_cross % 2 != 0;
}

void Polygon::print() const {
    cout << "Points :" << endl;
    for (size_t i = 0; i < nb_corners; i++) {
        cout << "   ";
        corners[i].print();
    }
    cout << "Area : " << getArea() << endl;
    cout << "Perimeter : " << getPerimeter() << endl;
    cout << "Is convex ? " << (isConvex() ? "Yes" : "No") << endl;
}

/*
    PRIVATE METHODS
 */

int Polygon::crossProduct(const Point2D& a, const Point2D& b, const Point2D& c) const {
    int BAx = a.getX() - b.getX();
    int BAy = a.getY() - b.getY();
    int BCx = c.getX() - b.getX();
    int BCy = c.getY() - b.getY();
    return BAx * BCy - BAy * BCx;
}
