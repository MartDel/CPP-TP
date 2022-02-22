#include "Point2D.hpp"

class Shape {
    private:
        static size_t nb_shapes;
        const size_t id;

    protected:
        int color;
        int getId() const { return id; };

    public:
        Shape() : id(nb_shapes) { nb_shapes++; }
        int get_color() const { return color; }
        void set_color(const int& _color) { color = _color; }

        virtual float getArea() = 0;
        virtual float getPerimeter() = 0;
        virtual void print() = 0;
        virtual string getType() = 0;
};
