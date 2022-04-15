#include "../headers/header.hpp"

int main() {
    srand(time(NULL));

    for (size_t i = 1; i <= 12; i++) {
        cout << "------------------ TOUR " << i << "------------------" << endl;
        array<array<size_t, MAT_SIZE>, MAT_SIZE> mat = getMat();

        printMat(mat);
        cout << endl;

        cout << "Flot max : " << fordFulkerson(mat, 0, MAT_SIZE - 1) << endl << endl;
    }

    return 0;
}
