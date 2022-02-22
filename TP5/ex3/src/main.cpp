#include "ListOfShapes.hpp"

int main(void) {
    Point2D p0(0,0), p1(1,0), p2(0,1), p3(1,1), p4(2, 0), p5(2, 1);
    ListOfShapes shapes;

    Point2D corners1[4] = {p0, p1, p3, p2};
    Square* square = new Square(corners1);
    square->print();
    shapes.push(square);
    cout << endl;

    Point2D corners2[4] = {p0, p4, p5, p2};
    Rectangle* rectangle = new Rectangle(corners2);
    rectangle->print();
    shapes.push(rectangle);
    cout << endl;

    Circle* circle = new Circle(5);
    circle->print();
    shapes.push(circle);
    cout << endl;

    shapes.printShapeTypes();
    cout << "Total surface : " << shapes.getTotalSurface() << endl;
    cout << "Total square surface : " << shapes.getTotalSurfaceByType("Square") << endl;
    cout << "Total perimeter : " << shapes.getTotalPerimeter() << endl;

    return 0;
}
