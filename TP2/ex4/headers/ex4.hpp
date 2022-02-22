#include <iostream>

using namespace std;

class TextRectangle {
    public:

        TextRectangle(const int tmp_width, const int tmp_height);

        int getArea() const;
        int getPerimeter() const;

        void print() const;

        void drawArea(const char& pattern) const;
        void drawPerimeter(const char& pattern) const;

        int getWidth() const;
        void setWidth(const int tmp_width);
        int getHeight() const;
        void setHeight(const int tmp_height);

    private:

        int width;
        int height;
};
