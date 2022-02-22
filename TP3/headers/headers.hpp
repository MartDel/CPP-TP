#include <chrono>
#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <list>
#include <queue>

using namespace std;
using namespace std::chrono;

constexpr int N = 1000;
constexpr int nb_round = 3;

/**
 * @brief Check if a number is prime, only divisible by 1 and itself
 * @param n The number to check
 * @return true n is prime
 * @return false n isn't prime
 */
bool is_prime(const int& n);

/**
 * @brief Get all prime numbers between 0 and n
 * @param n The max number to check
 * @return vector<int> All the prime numbers
 */
vector<int> getAllPrime(const int n);