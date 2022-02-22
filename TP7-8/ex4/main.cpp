#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

#define ARRAY_SIZE 7

void print(const vector<int>&);

int main(void) {
    int arr[ARRAY_SIZE] = {1, 2, 3, -3, -2, -1, 0};
    vector<int> numbers(arr, arr + ARRAY_SIZE);
    auto is_pos = [](int n){ return n >= 0; };
    auto is_neg = [](int n){ return n < 0; };

    cout << "Base container :" << endl;
    print(numbers);
    cout << endl;

    cout << "Numbers >= 0 :" << endl;
    copy_if(
        numbers.begin(), numbers.end(),
        ostream_iterator<int>(cout, " "),
        is_pos
    );
    cout << endl << endl;

    auto first_neg = find_if(numbers.begin(), numbers.end(), is_neg);
    auto last_neg = find_if(numbers.rbegin(), numbers.rend(), is_neg);
    if (first_neg != end(numbers)) {
        cout << "The first negative value is " << *first_neg << endl;
        cout << "The last negative value is " << *last_neg << endl << endl;
    } else cout << "The container doesn't contain negative value..." << endl;

    if (all_of(numbers.cbegin(), numbers.cend(), is_pos))
        cout << "All numbers are >= 0" << endl;
    else cout << "All numbers are not >= 0" << endl;

    cout << "Replacing negative number by 0..." << endl;
    replace_if(numbers.begin(), numbers.end(), is_neg, 0);

    if (all_of(numbers.cbegin(), numbers.cend(), is_pos))
        cout << "All numbers are >= 0" << endl;
    else cout << "All numbers are not >= 0" << endl;

    cout << endl << "Final container :" << endl;
    print(numbers);

    return 0;
}

void print(const vector<int>& numbers) {
    ostream_iterator<int> out_it (cout, " ");
    copy(numbers.begin(), numbers.end(), out_it);
    cout << endl;
}
