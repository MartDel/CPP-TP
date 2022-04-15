#include <cstddef>
#include <cstdlib>
#include <iostream>

#include "../headers/header.hpp"

#define ECART 10

size_t sum_aleat(int val) {
    size_t val1 = val - ECART;
    size_t val2 = val + ECART;
    return (rand() % ((val2 - val1) + 1)) + val1;
}

size_t mult_aleat(int val) {
    size_t val2 = val + ECART;
    return (rand() % ((val2 - val) + 1)) + val;
}

array<array<size_t, MAT_SIZE>, MAT_SIZE> getMat() {
    array<array<size_t, MAT_SIZE>, MAT_SIZE> mat;
    for (size_t i = 0; i < MAT_SIZE; i++) {
        for (size_t j = 0; j < MAT_SIZE; j++) {
            mat[i][j] = 0;
        }
    }

    size_t INFINITY = numeric_limits<size_t>::max();

    // Partie 2 (MAT_SIZE = 7)
    // mat[0][1] = 50;
    // mat[0][2] = 70;
    // mat[0][3] = 40;
    // mat[1][4] = 60;
    // mat[2][4] = 40;
    // mat[2][5] = 50;
    // mat[3][5] = 30;
    // mat[4][6] = 80;
    // mat[5][6] = 70;

    // Partie 3, Étape 1 (MAT_SIZE = 5)
    // mat[0][1] = INFINITY;
    // mat[0][2] = INFINITY;
    // mat[0][3] = INFINITY;
    // mat[1][4] = 19;
    // mat[2][4] = 7;
    // mat[3][4] = 5;

    // Partie 3, Étape 2 (MAT_SIZE = 5)
    // mat[0][1] = 25;
    // mat[0][2] = 10;
    // mat[0][3] = 8;
    // mat[1][4] = 19;
    // mat[2][4] = 7;
    // mat[3][4] = 5;

    // Partie 3, Étape 3 (MAT_SIZE = 5)
    // mat[0][1] = 25;
    // mat[0][2] = 10;
    // mat[0][3] = 3;
    // mat[1][2] = 8;
    // mat[2][1] = 8;
    // mat[2][3] = 3;
    // mat[3][2] = 3;
    // mat[1][4] = 30;
    // mat[2][4] = 7;
    // mat[3][4] = 3;
    // mat[1][3] = 8;
    // mat[3][1] = 8;

    // Partie 3, Étape 4 (MAT_SIZE = 8)
    // mat[0][1] = 25;
    // mat[1][2] = 15;
    // mat[0][2] = 15;
    // mat[1][7] = 14;
    // mat[2][7] = 19;
    // mat[0][3] = 10;
    // mat[0][4] = 5;
    // mat[3][4] = 8;
    // mat[3][7] = 3;
    // mat[4][7] = 10;
    // mat[0][5] = 5;
    // mat[0][6] = 8;
    // mat[5][6] = 7;
    // mat[5][7] = 7;
    // mat[6][7] = 5;

    // Partie 3, Étape 5 (MAT_SIZE = 8)
    cout << "Ecart max (plus ou moins par rapport à la valeur de base) : " << ECART << endl;
    mat[0][1] = 25;
    mat[1][2] = 15;
    mat[0][2] = 15;
    mat[1][7] = sum_aleat(14);
    cout << "Demande entre 2.1 et 5 (valeur de base : 14) : " << mat[1][7] << endl;
    mat[2][7] = sum_aleat(19);
    cout << "Demande entre 2.2 et 5 (valeur de base : 19) : " << mat[2][7] << endl;
    mat[0][3] = 10;
    mat[0][4] = 5;
    mat[3][4] = 8;
    mat[3][7] = sum_aleat(3);
    cout << "Demande entre 3.1 et 5 (valeur de base : 3) : " << mat[3][7] << endl;
    mat[4][7] = sum_aleat(10);
    cout << "Demande entre 3.2 et 5 (valeur de base : 10) : " << mat[4][7] << endl;
    mat[0][5] = 5;
    mat[0][6] = 8;
    mat[5][6] = 7;
    mat[5][7] = sum_aleat(7);
    cout << "Demande entre 4.1 et 5 (valeur de base : 7) : " << mat[5][7] << endl;
    mat[6][7] = sum_aleat(5);
    cout << "Demande entre 4.2 et 5 (valeur de base : 5) : " << mat[6][7] << endl << endl;

    return mat;
}

/**
 * @brief Print matrix
 *
 * @param mat Matrix to display
 */
void printMat(const array<array<size_t, MAT_SIZE>, MAT_SIZE> &mat) {
    for (size_t i = 0; i < MAT_SIZE; i++) {
        for (size_t j = 0; j < MAT_SIZE; j++) {
            cout << mat[i][j] << " " << (mat[i][j] == 0 ? " " : "");
        }
        cout << endl;
    }
}

bool widthWay(const array<array<size_t, MAT_SIZE>, MAT_SIZE> &mat,
              const size_t &start_id, const size_t &end_id,
              vector<int> &preds) {
    bool visited_corners[MAT_SIZE] = {0};
    queue<size_t> file;

    // Reset preds
    for (size_t i = 0; i < MAT_SIZE; i++) preds[i] = -1;

    file.push(start_id);
    visited_corners[start_id] = true;

    while (!file.empty()) {
        size_t u = file.front();
        file.pop();

        for (size_t v = 0; v < MAT_SIZE; v++) {
            if (!visited_corners[v] && mat[u][v] != 0) {
                file.push(v);
                preds[v] = u;
                visited_corners[v] = true;
            }
        }
    }

    // Determine if a path exists
    int current_pred = end_id;
    while (preds[current_pred] != -1) current_pred = preds[current_pred];

    return current_pred == start_id;
}

size_t fordFulkerson(const array<array<size_t, MAT_SIZE>, MAT_SIZE> &mat,
                     const size_t &start_id, const size_t &end_id) {
    int u, v;

    array<array<size_t, MAT_SIZE>, MAT_SIZE> graph;
    for (size_t i = 0; i < MAT_SIZE; i++)
        for (size_t j = 0; j < MAT_SIZE; j++) graph[i][j] = mat[i][j];

    vector<int> preds;
    for (size_t i = 0; i < MAT_SIZE; i++) preds.push_back(-1);

    size_t max_flow(0);

    size_t i(0);
    while (widthWay(graph, start_id, end_id, preds)) {
        size_t flow = numeric_limits<size_t>::max();

        v = end_id;
        while (v != start_id) {
            u = preds[v];
            flow = min(flow, graph[u][v]);
            v = preds[v];
        }

        v = end_id;
        while (v != start_id) {
            u = preds[v];
            graph[u][v] -= flow;
            graph[v][u] += flow;
            v = preds[v];
        }

        max_flow += flow;
    }

    return max_flow;
}