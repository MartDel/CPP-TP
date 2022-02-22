#include <algorithm>
#include <chrono>
#include <cstddef>
#include <iostream>
#include <map>

using namespace std;
using namespace std::chrono;

constexpr int SIZE(10);
#define MAX_VALUE 1000
#define SEARCHING 334

#define PART2_3
#define PART4_5

#ifdef PART2_3
#include <array>

/**
 * @brief Print an array
 * @param a The array to print
 */
void printArray(const array<int, SIZE>& a);

/**
 * @brief Search for a value in the given array
 * @param value The value to search
 * @param a The given array
 * @return int The element position in the array (-1 if doesn't exist)
 */
int searchInArray(const int& value, const array<int, SIZE>& a);
#endif

#ifdef PART4_5
#include <vector>

/**
 * @brief Print a vector
 * @param v The vector to print
 */
void printVector(const vector<int>& v);

/**
 * @brief Search for a value in the given vector
 * @param value The value to search
 * @param v The given vector
 * @return int The element position in the vector (-1 if doesn't exist)
 */
vector<int>::iterator searchInVector(const int& value, vector<int>& v);
#endif