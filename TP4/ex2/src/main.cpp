#include "Circle.hpp"

int main(void) {
    srand(time(0));

    Circle c(5);
    c.print();
    cout << "PI = " << Circle::getPi() << endl;

    return 0;
}
