#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int n;
    cout << "Enter a number : ";
    cin >> n;
    cout << endl;

    // for (size_t i = 0; i <= 10; i++) {
    //     cout << n*i << endl;
    // }

    for (size_t i = 0; i <= 10; i++) {
        cout << n << " x ";
        if (i <= 10) cout << setw(2) << i << " = ";
        else cout << i << " = ";
        if (n * i < 10) cout << setw(2) << n * i << endl;
        else cout << n * i << endl;
    }

    return 0;
}
