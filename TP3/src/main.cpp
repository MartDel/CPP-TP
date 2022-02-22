#include "Trajectory.hpp"

int main() {
    srand(time(0));

    Point3D pt1;
    pt1.print();

    Point3D pt2 = Point3D(10, 11, 12);
    pt2.print();

    cout << "distance : " << pt1.distanceTo(pt2) << endl << endl;

    Trajectory traj = Trajectory(5);
    traj.print();

    cout << endl;
    cout << "The last point of the trajectory : ";
    traj.getPoint(traj.getNumberOfPoints()-1).print();

    float total_distance = traj.getTotalDistance();
    float first_to_last = traj.getPoint(0).distanceTo(traj.getPoint(traj.getNumberOfPoints()-1));
    cout << endl << "Total distance : " << total_distance << endl;
    cout << "First to last point distance : " << first_to_last << endl;

    return 0;
}
