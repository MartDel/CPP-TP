#include "ListOfShapes.hpp"

ListOfShapes::ListOfShapes() : numberOfShapes(0) {
    vector<Shape*> tmp;
    shapes = tmp;
}

void ListOfShapes::push(Shape* shape) {
    shapes.push_back(shape);
    numberOfShapes++;
}

void ListOfShapes::printShapeTypes() const {
    cout << "Shape types :" << endl;
    for (size_t i = 0; i < numberOfShapes; i++) {
        cout << "   - " << shapes.at(i)->getType() << endl;
    }
}

float ListOfShapes::getTotalSurface() const {
    float surface = 0;
    for (size_t i = 0; i < numberOfShapes; i++) {
        surface += shapes.at(i)->getArea();
    }
    return surface;
}

float ListOfShapes::getTotalSurfaceByType(const string& type) const {
    float surface = 0;
    for (size_t i = 0; i < numberOfShapes; i++) {
        Shape* current = shapes.at(i);
        if (current->getType() == type)
            surface += current->getArea();
    }
    return surface;
}

float ListOfShapes::getTotalPerimeter() const {
    float perimeter = 0;
    for (size_t i = 0; i < numberOfShapes; i++) {
        perimeter += shapes.at(i)->getPerimeter();
    }
    return perimeter;
}
