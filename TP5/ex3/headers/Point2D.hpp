#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

class Point2D {
    private:
        float x;
        float y;

    public:
        Point2D() : x(0), y(0) {};
        Point2D(const float _x, const float _y) : x(_x), y(_y) {}
        float getX() const { return x; }
        void setX(const float& _x) { x = _x; }
        float getY() const { return y; }
        void setY(const float& _y) { y = _y; }

        float distanceTo(const Point2D&) const;
        void print() const;

        bool operator==(const Point2D&) const;
};
