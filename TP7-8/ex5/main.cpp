#include <iostream>
#include <map>
#include <sstream>
#include <string>

using namespace std;

string convertDate(const string&, const map<string, int>&);

int main(void) {
    map<string, int> months;
    months.insert({"Janvier", 1});
    months.insert({"Février", 2});
    months.insert({"Mars", 3});
    months.insert({"Avril", 4});
    months.insert({"Mai", 5});
    months.insert({"Juin", 6});
    months.insert({"Juillet", 7});
    months.insert({"Août", 8});
    months.insert({"Septembre", 9});
    months.insert({"Octobre", 10});
    months.insert({"Novembre", 11});
    months.insert({"Décembre", 12});

    for (auto const& pair: months)
        std::cout << pair.second << " : " << pair.first << endl;

    string base("31 Décembre 2014"), final = convertDate(base, months);
    cout << endl << base << " -> " << final << endl;

    return 0;
}

string convertDate(const string& base, const map<string, int>& months) {
    stringstream stream(base);
    string str_comp, result("");
    size_t i(0);
    while (getline(stream, str_comp, ' ')) {
        switch (i) {
            case 0: result += str_comp + "/"; break;
            case 1: result += to_string(months.at(str_comp)) + "/"; break;
            case 2: result += str_comp; break;
        }
        i++;
    }
    return result;
}
