#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <map>

#define FILENAME "ex3.txt"

using namespace std;

int main() {
    int nb_lines(0), nb_words(0), nb_letters(0);
    string current_line, current_word;
    char current_char;
    // size_t alpha[26] = {0};
    map<char, size_t> alpha;
    for (char i = 65; i < 91; i++) {
        alpha[i] = 0;
    }

    // Open a Lorem Ipsum file
    ifstream file(FILENAME);

    if (file.is_open()) {
        // Read the opened file line by line
        while (file) {
            getline(file, current_line);
            nb_lines++;

            // Get all the line words
            stringstream current_line_stream(current_line);
            vector<string> line_words;
            while (current_line_stream >> current_word){
                size_t const word_length = current_word.length();
                nb_letters += word_length;
                line_words.push_back(current_word);

                // Loop through the current word
                for (size_t i = 0; i < word_length; i++) {
                    current_char = current_word[i];
                    if (isalpha(current_char)) {
                        current_char = toupper(current_char);
                        if (alpha.count(current_char) > 0)
                            alpha[current_char]++;
                    }
                }
            }
            nb_words += line_words.size();
        }
        file.close();
    } else cout << "The file can't be opened..." << endl;

    cout << endl << "Number of lines : " << nb_lines << endl;
    cout << "Number of words : " << nb_words << endl;
    cout << "Number of letters : " << nb_letters << endl << endl;

    cout << "Occurrence of letters :" << endl;
    map<char, size_t>::iterator it;
    for(it = alpha.begin(); it != alpha.end(); ++it)
        cout << it->first << " -> " << it->second << endl;

    return 0;
}
