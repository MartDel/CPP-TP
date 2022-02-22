#include "header.hpp"

vector<char> alphabet, first_word, last_word;
size_t k = 0;
char first_letter, last_letter;

int main(void) {
    // Ask the alphabet
    string tmp_alphabet;
    bool has_occurence(false);
    do {
        cout << "Please enter a word : ";
        cin >> tmp_alphabet;
        alphabet.clear();

        // Check if there isn't any occurence
        string::iterator it = tmp_alphabet.begin();
        has_occurence = false;
        while (it != tmp_alphabet.end() && !has_occurence) {
            if (count(alphabet.begin(), alphabet.end(), tolower(*it)))
                has_occurence = true;
            else {
                alphabet.push_back(tolower(*it));
                it++;
            }
        }

        if (has_occurence) cout << "There is some occurence in your word, please try again" << endl;
    } while (has_occurence);

    // Sort the alphabet
    sort(alphabet.begin(), alphabet.end());

    // Update globals variables
    k = alphabet.size();
    first_letter = alphabet.at(0);
    last_letter = alphabet.at(alphabet.size() - 1);
    for (size_t i = 0; i < alphabet.size(); i++)
        first_word.push_back(first_letter);
    for (size_t i = 0; i < alphabet.size(); i++)
        last_word.push_back(last_letter);

    // Print the alphabet
    cout << endl << "Here there is your alphabet :" << endl;
    for (char& current_char : alphabet)
        cout << current_char << endl;

    generator();

    return 0;
}

char succ(const char& letter) {
    return *(++find(alphabet.begin(), alphabet.end(), letter));
}

void printWord(const vector<char> &word) {
    cout << ">> ";

    for (const char& current_char : word)
        cout << current_char;
    
    cout << endl;
}

vector<char> next(const vector<char> &word) {
    vector<char> result;

    if (word != last_word) {
        result = word;

        size_t i = k-1;
        while (result.at(i) == last_letter) {
            result.at(i) = first_letter;
            i--;
        }

        result.at(i) = succ(result.at(i));
    } else result = first_word;

    return result;
}

void generator() {
    cout << endl;
    vector<char> word = first_word;

    while (word != last_word) {
        printWord(word);
        word = next(word);
    }

    printWord(word);
}