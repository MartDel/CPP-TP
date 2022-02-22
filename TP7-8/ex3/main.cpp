#include <iostream>
#include <set>

using namespace std;

template<typename Iter>
typename Iter::value_type
partial_dot(Iter first1, Iter last1, Iter first2, Iter last2) {
    typename Iter::value_type sum(0);
    while (first1 != last1 && first2 != last2)
        sum += (*first1++) * (*first2++);
    return sum;
}

int main(void) {
    int a[3] = {7, 4, 9};
    int b[2] = {2, 2};

    multiset<int> s1(&a[0], &a[3]);
    multiset<int>::iterator p1 = s1.begin();
    while (p1 != s1.end()) cout << *p1++ << " ";
    cout << endl;

    multiset<int> s2(&b[0], &b[2]);
    multiset<int>::iterator p2 = s2.begin();
    while (p2 != s2.end()) cout << *p2++ << " ";
    cout << endl << endl;

    int dot = partial_dot(s1.begin(), s1.end(), s2.begin(), s2.end());
    cout << "Partial dot : " << dot << endl;

    return 0;
}
