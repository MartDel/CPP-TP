#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * @brief Get the next letter in the current alphabet
 * @param letter The current letter
 * @return char The next letter
 */
char succ(const char& letter);

/**
 * @brief Print a word
 * @param word The word to print
 */
void printWord(const vector<char>& word);

/**
 * @brief Get the next word in the lexicographical order
 * @param word The current word
 * @return vector<char> The next word
 */
vector<char> next(const vector<char>& word);

/**
 * @brief Print all of possible word with the current alphabet
 */
void generator();