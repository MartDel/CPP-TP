#include "Rectangle.hpp"

class ListOfShapes {
    private:
        vector<Shape*> shapes;
        size_t numberOfShapes;

    public:
        ListOfShapes();
        ListOfShapes(vector<Shape*> _shapes) : shapes(_shapes) {}
        size_t getNumberOfShapes() const { return numberOfShapes; }

        void push(Shape* shape);
        void printShapeTypes() const;
        float getTotalSurface() const;
        float getTotalSurfaceByType(const string& type) const;
        float getTotalPerimeter() const;
};
