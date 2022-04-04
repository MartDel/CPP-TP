#include "header.hpp"

int main() {
    array<array<size_t, MAT_SIZE>, MAT_SIZE> mat = getMat();

    printMat(mat);

    cout << endl;

    cout << fordFulkerson(mat, 0, MAT_SIZE-1);

    return 0;
}
