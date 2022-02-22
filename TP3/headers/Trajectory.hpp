#include "Point3D.hpp"

class Trajectory{
    private:
        Point3D* points;
        size_t numberOfPoints;

    public:
        Trajectory(const size_t numberOfPoints);
        ~Trajectory();

        void print() const;
        float getTotalDistance() const;

        // Getters
        Point3D & getPoint(const int &n) const;
        size_t getNumberOfPoints() const;
};
