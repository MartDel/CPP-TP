#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

class Point3D {
    // private attributes
    private:

        float x,y,z;

    public:

        // constuctors
        Point3D(); // fill X Y Z with random values (from 0 to 100)
        Point3D(const float &newx, const float &newy, const float &newz); // fill XYZ values

        // Setters and getters
        void setXYZ(const float &newx, const float &newy, const float &newz);
        void setX(const float &newx);
        void setY(const float &newy);
        void setZ(const float &newz);
        float getX() const;
        float getY() const;
        float getZ() const;

        // other methods
        void print() const;
        // prints the coordinates of the point
        float distanceTo(const Point3D &otherPoint3D) const;
};
