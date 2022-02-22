#include "Fraction.hpp"

#define SEPARATOR '/'

int main(void) {
    fstream file;
    set<Fraction<float>> fracs;
    file.open("fracs.txt", ios::in);
    if (file.is_open()) {
        string line;
        bool first_comp;
        while (getline(file, line)) {
            stringstream stream(line);
            string str_comp;
            Fraction<float> f;
            first_comp = true;
            while (getline(stream, str_comp, SEPARATOR)) {
                if (first_comp) {
                    f.setNumerator(stof(str_comp));
                    first_comp = false;
                } else f.setDenumerator(stof(str_comp));
            }
            if (f >= 0.f) fracs.insert(f);
        }
        file.close();
        Fraction<float>
            min = Fraction<float>::getMin(fracs),
            max = Fraction<float>::getMax(fracs);

        set<Fraction<float>>::iterator it = fracs.begin();
        while (it != fracs.end()) cout << *it++ << endl;

        cout << "Total sum : " << Fraction<float>::getTotalSum(fracs) << endl;
        cout << "Minimal : " << min << endl;
        cout << "Maximal : " << max << endl;
    } else {
        cout << "File 'fracs.txt' doesn't exist..." << endl;
        cout << "Please create a file named 'fracs.txt' with this pattern :" << endl;
        cout << "1/3" << endl;
        cout << "4/6" << endl;
        cout << "-7.1/32" << endl;
        cout << "..." << endl;
        cout << "You can find an example in the root directory." << endl;
    }

    return 0;
}
