#include "Rectangle.hpp"

Rectangle::Rectangle(Point2D* c) {
    // Get corners
    for (size_t i = 0; i < 4; i++) {
        corners[i] = c[i];
    }

    // Get sides
    float tmp1 = c[0].distanceTo(c[1]);
    float tmp2 = c[1].distanceTo(c[2]);
    l = max(tmp1, tmp2);
    L = min(tmp1, tmp2);
}

float Rectangle::getArea() {
    return l * L;
}

float Rectangle::getPerimeter() {
    return l*2 + L*2;
}

void Rectangle::print() {
    cout << "-- Rectangle --" << endl;
    cout << "Points :" << endl;
    for (size_t i = 0; i < 4; i++) {
        cout << "   ";
        corners[i].print();
    }
    cout << "Length : " << l << endl;
    cout << "Width : " << L << endl;
    cout << "Area : " << getArea() << endl;
    cout << "Perimeter : " << getPerimeter() << endl;
}

Square::Square(Point2D* c) : Rectangle(c) {
    side_length = c[0].distanceTo(c[1]);
}

float Square::getArea() {
    return pow(side_length, 2);
}

float Square::getPerimeter() {
    return 4*side_length;
}

void Square::print() {
    cout << "-- Square --" << endl;
    cout << "Points :" << endl;
    for (size_t i = 0; i < 4; i++) {
        cout << "   ";
        corners[i].print();
    }
    cout << "Side : " << side_length << endl;
    cout << "Area : " << getArea() << endl;
    cout << "Perimeter : " << getPerimeter() << endl;
}
