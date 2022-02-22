#include "Shape.hpp"

#define NB_RAND_POINTS 100000

class Circle : public Shape {
    private:
        float radius;
        static float pi;

    public:
        Circle(const float& r) : radius(r) {}
        float get_radius() const { return radius; }
        void set_radius(const float& r) { radius = r; }

        float getArea();
        float getPerimeter();
        void print();
        string getType() { return "Circle"; }

        static float getPi();
};
