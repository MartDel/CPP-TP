#include "Trajectory.hpp"

Trajectory::Trajectory(const size_t nb_points) {
    numberOfPoints = nb_points;
    points = new Point3D[numberOfPoints];
    for (size_t i = 0; i < numberOfPoints; i++) {
        points[i] = Point3D();
    }
}

Trajectory::~Trajectory(){
    delete points;
}

void Trajectory::print() const {
    for (size_t i = 0; i < numberOfPoints; i++)
        points[i].print();
}

float Trajectory::getTotalDistance() const {
    float d = 0;
    for (size_t i = 1; i < numberOfPoints; i++) {
        Point3D& previous = getPoint(i-1);
        Point3D& next = getPoint(i);
        d += previous.distanceTo(next);
    }
    return d;
}

/*
    GETTERS
 */

Point3D& Trajectory::getPoint(const int &n) const { return points[n]; }
size_t Trajectory::getNumberOfPoints() const { return numberOfPoints; }
