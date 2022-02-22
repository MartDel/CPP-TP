#include <iostream>
#include <set>

using namespace std;

int main(){
    int a[] = {7, 4, 9, 1, 3, 4, 8, 2, 7, 5, 3, 6, 10, 4, 8, 10, 1, 2}; // Init a static array with some numeric values

    cout << "With a multiset :" << endl;
    multiset<int> s1(&a[0], &a[17]); // Init a multiset from the static array
    multiset<int>::iterator p1 = s1.begin(); // Init a multiset iterator to loop into the created multiset
    while (p1 != s1.end()) cout << *p1++ << " "; // Print each value from the multiset
    cout << endl << endl;

    cout << "With a set :" << endl;
    set<int> s2(&a[0], &a[17]); // Init a multiset from the static array
    set<int>::iterator p2 = s2.begin(); // Init a multiset iterator to loop into the created multiset
    while (p2 != s2.end()) cout << *p2++ << " "; // Print each value from the multiset

    return 0;
}
