#include "Circle.hpp"

size_t Shape::nb_shapes = 0;

float Circle::pi = -1;

float Circle::getPi(){
    if (pi == -1) {
        Circle c(1);
        pi = c.get_area();
    }
    return pi;
}

float Circle::get_area() {
    size_t nb_matches = 0;
    Point2D center(radius, radius);
    for (size_t i = 0; i < NB_RAND_POINTS; i++) {
        Point2D p(rand()/(float(RAND_MAX)/radius), rand()/(float(RAND_MAX)/radius));
        if(p.distanceTo(center) <= radius)
            nb_matches++;
    }
    return ((double) nb_matches / NB_RAND_POINTS) * pow(radius*2, 2);
}

float Circle::get_perimeter() {
    return 2 * getPi() * radius;
}

void Circle::print() {
    cout << "Radius : " << radius << endl;
    cout << "Area : " << get_area() << endl;
    cout << "Perimeter : " << get_perimeter() << endl;
}
