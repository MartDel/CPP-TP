#include "Point3D.hpp"

/*
    CONSTRUCTORS
 */

Point3D::Point3D(){
    x = rand() % 100;
    y = rand() % 100;
    z = rand() % 100;
}
Point3D::Point3D(const float &newx, const float &newy, const float &newz) :
x(newx), y(newy), z(newz) {}

/*
    METHODS
 */

void Point3D::print() const{
    cout << "(" << x << "," << y << "," << z << ")" << endl;
}

float Point3D::distanceTo(const Point3D &otherPoint3D) const{
    return sqrt(pow(otherPoint3D.getX() - x, 2) + pow(otherPoint3D.getY() - y, 2) + pow(otherPoint3D.getZ() - z, 2));
}

/*
    GETTERS AND SETTERS
 */

void Point3D::setXYZ(const float &newx, const float &newy, const float &newz) {
    x = newx; y = newy; z = newz;
}

float Point3D::getX() const { return x; }
void Point3D::setX(const float &newx){ x = newx; }
float Point3D::getY() const { return y; }
void Point3D::setY(const float &newy){ y = newy; }
float Point3D::getZ() const { return z; }
void Point3D::setZ(const float &newz){ z = newz; }
