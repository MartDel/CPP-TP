#include <iostream>
#include <cmath>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#define SEPARATOR ';'

using namespace std;

class Point {
    private:
        float x, y;

    public:
        Point() : x(0), y(0) {}
        Point(const float& _x, const float& _y) : x(_x), y(_y) {}
        float getX() const { return x; }
        void setX(const float& _x) { x = _x; }
        float getY() const { return y; }
        void setY(const float& _y) { y = _y; }

        float distanceTo(const Point&) const;
        void print() const;

        Point operator+(const Point&);
        Point operator*(const float&);
        Point operator|(const Point&);

        friend ostream& operator<<(ostream&, const Point&);
        friend istream& operator>>(istream&, Point&);
        friend Point operator*(const float&, const Point&);

        static Point getCenterOfGravity(vector<Point>);
};
