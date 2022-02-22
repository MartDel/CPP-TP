#include "Polygon.hpp"

int main(void) {
    Point2D pt1(0,0), pt2(0,1), pt2b(0,2), pt3(1,1), pt3b(1,2), pt4(1,0), pt5(-2,1), pt6(-1,0), pt7(-2, -1);

    cout << "-- Triangle --" << endl;
    Point2D corners1[3] = {pt1, pt2, pt3};
    Polygon p1(corners1, 3);
    p1.print();

    cout << endl <<  "-- Square --" << endl;
    Point2D corners2[4] = {pt1, pt2, pt3, pt4};
    Polygon p2(corners2, 4);
    p2.print();

    cout << endl << "-- Rectangle --" << endl;
    Point2D corners3[4] = {pt1, pt2b, pt3b, pt4};
    Polygon p3(corners3, 4);
    p3.print();

    cout << endl << "-- Concave polygon --" << endl;
    Point2D corners4[7] = {pt1, pt2, pt3, pt4, pt5, pt6, pt7};
    Polygon p4(corners4, 7);
    p4.print();

    Point2D pt8(0, 0.5);
    cout << endl << "Is (O.5, 0.5) in the last polygon ? " << (p1.isPointInPolygon(pt8) ? "Yes" : "No") << endl;

    return 0;
}
