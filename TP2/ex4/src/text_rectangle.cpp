#include "ex4.hpp"

TextRectangle::TextRectangle(const int tmp_width, const int tmp_height){
    setWidth(tmp_width); setHeight(tmp_height);
}

int TextRectangle::getArea() const {
    return width * height;
}

int TextRectangle::getPerimeter() const {
    return (2*width) + (2*height);
}

void TextRectangle::print() const {
    cout << "Size : " << (int) width << "x" << (int) height << endl;
    cout << "Area : " << getArea() << endl;
    cout << "Perimeter : " << getPerimeter() << endl;
}

void TextRectangle::drawArea(const char& pattern) const {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++)
            printf("%2c", pattern);
        printf("\n");
    }
}

void TextRectangle::drawPerimeter(const char& pattern) const {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if((x == 0 || x == width-1) || (y == 0 || y == height-1))
                printf("%2c", pattern);
            else
                printf("  ");
        }
        printf("\n");
    }
}

/*
    GETTERS and SETTERS
 */

int TextRectangle::getWidth() const { return width; }
void TextRectangle::setWidth(const int tmp_width){
    width = tmp_width < 1 ? 1 : tmp_width;
    width = width > 10 ? 10 : width;
}

int TextRectangle::getHeight() const { return height; }
void TextRectangle::setHeight(const int tmp_height){
    height = tmp_height < 1 ? 1 : tmp_height;
    height = height > 10 ? 10 : height;
}
