#include <iostream>
#include <tuple>
#include <array>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>

#define MAT_SIZE 8

using namespace std;

array<array<size_t, MAT_SIZE>, MAT_SIZE> getMat();
void printMat(const array<array<size_t, MAT_SIZE>, MAT_SIZE> &mat);

bool widthWay(const array<array<size_t, MAT_SIZE>, MAT_SIZE> &mat, const size_t& start_id, const size_t& end_id, vector<int>& preds);
size_t fordFulkerson(const array<array<size_t, MAT_SIZE>, MAT_SIZE> &mat, const size_t &start_id, const size_t &end_id);