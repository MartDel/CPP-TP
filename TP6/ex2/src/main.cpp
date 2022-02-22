#include "Point.hpp"

int main(void) {

    Point p1, p2;
    cin >> p1;
    cout << endl;
    cin >> p2;
    cout << endl;

    cout << "p1 + p2 : " << p1 + p2 << endl;
    cout << "p1 * 3 : " << p1 * 3 << endl;
    cout << "3 * p1 : " << 3 * p1 << endl;
    cout << "Point médian entre p1 et p2 : " << (p1 | p2) << endl << endl;

    fstream file;
    file.open("points.txt", ios::in);
    if (file.is_open()) {
        string line;
        bool first_comp;
        vector<Point> points;
        while (getline(file, line)) {
            stringstream stream(line);
            string str_comp;
            Point p;
            first_comp = true;
            while (getline(stream, str_comp, SEPARATOR)) {
                if (first_comp) {
                    p.setX(stof(str_comp));
                    first_comp = false;
                } else p.setY(stof(str_comp));
            }
            points.push_back(p);
        }

        Point center = Point::getCenterOfGravity(points);
        cout << "The center of gravity of all file points :" << endl;
        cout << center << endl;

        file.close();
    } else {
        cout << "File 'points.txt' doesn't exist..." << endl;
        cout << "Please create a file named 'points.txt' with this pattern :" << endl;
        cout << "1;3" << endl;
        cout << "4;6" << endl;
        cout << "-7.1;32" << endl;
        cout << "..." << endl;
        cout << "You can find an example in the root directory." << endl;
    }

    return 0;
}
