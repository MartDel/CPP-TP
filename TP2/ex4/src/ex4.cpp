#include "ex4.hpp"

int main(void) {
    int width, height;
    char pattern;

    cout << "Enter the rectangle width : ";
    cin >> width;
    cout << "Enter the rectangle height : ";
    cin >> height;
    cout << "Enter the rectangle pattern : ";
    cin >> pattern;
    cout << endl;

    TextRectangle tr = TextRectangle(width, height);
    tr.print();

    cout << endl;
    tr.drawArea(pattern);

    cout << endl;
    tr.drawPerimeter(pattern);

    return 0;
}
