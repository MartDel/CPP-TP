#include "Circle.hpp"

class Rectangle : public Shape {
    private:
        float l, L;

    protected:
        Point2D corners[4];

    public:
        Rectangle(Point2D* c);
        float getLength() const { return l; }
        float getWidth() const { return L; }

        float getArea();
        float getPerimeter();
        void print();
        string getType() { return "Rectangle"; }
};

class Square : public Rectangle {
    private:
        float side_length;

    public:
        Square(Point2D* c);
        float getSideLength() const { return side_length; }

        float getArea();
        float getPerimeter();
        void print();
        string getType() {return "Square"; }
};
