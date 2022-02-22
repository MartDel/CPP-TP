#include "headers.hpp"

int main() {
    // Seed
    srand(grainePourLeRand);

    // Generate cities
    vector<string> cities;
    map<string, tuple<int, int, int>> my_map;
    for (int i = 0; i < nombreDeVilles; i++) {
        // Choose a length
        int city_name_length = rand() % (tailleMaxNomVille - tailleMinNomVille + 1);
        city_name_length += tailleMinNomVille;

        // Generate the city name
        string city_name = "";
        for (int j = 0; j < city_name_length; j++) {
            char letter = chooseRandomLetter();
            letter += (j == 0 ? codeASCIIde_A : codeASCIIde_a);
            city_name += letter;
        }
        cities.push_back(city_name);

        // Generate position
        int X = rand() % tailleCoteCarte, Y = rand() % tailleCoteCarte;
        auto city_data = make_tuple(i, X, Y);
        my_map.insert(my_map.begin(), pair<string, tuple<int, int, int>>(city_name, city_data));
    }
    
    // Calcul distances
    array<array<double, nombreDeVilles>, nombreDeVilles> distances;
    for (auto& line : distances)
        line.fill(0);
    map<string, tuple<int, int, int>>::iterator map_it1;
    for (map_it1 = my_map.begin(); map_it1 != my_map.end(); map_it1++) {
        map<string, tuple<int, int, int>>::iterator map_it2;
        for (map_it2 = my_map.begin(); map_it2 != my_map.end(); map_it2++) {
            double d = distances[get<0>(map_it2->second)][get<0>(map_it1->second)];
            if (d == 0) {
                d = sqrt(
                    pow(get<1>(map_it1->second) - get<1>(map_it2->second), 2) +
                    pow(get<2>(map_it1->second) - get<2>(map_it2->second), 2)
                );
            }
            distances[get<0>(map_it1->second)][get<0>(map_it2->second)] = d;
        }
    }

    // Display
    map<string, tuple<int, int, int>>::iterator map_it;
    for (map_it = my_map.begin(); map_it != my_map.end(); map_it++) {
        cout << map_it->first;
        cout << " [" << get<0>(map_it->second) << "] ";
        cout << " (" << get<1>(map_it->second) << ", " << get<2>(map_it->second) << ")" << endl;
    }
    cout << endl;
    for (size_t i = 0; i < nombreDeVilles; i++) {
        for (size_t j = 0; j < nombreDeVilles; j++) {
            cout << distances[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    toutesLesPermutations(cities, 0, cities.size() - 1);

    cout << endl;
    cout << calculTotalDistanceTournee(cities, distances, my_map) << endl;
    return 0;
}

char chooseRandomLetter() {
    return rand() % nombreDeLettres;
}

void toutesLesPermutations(vector<string>& villes, int debut, int fin) {
    if (debut == fin) {
        for (const string& city : villes)
            cout << city << endl;
        cout << endl;
    } else {
        // Permutations made
        for (int i = debut; i <= fin; i++) {
            // echange des deux lettres
            swap(villes[debut], villes[i]);
            // Appel Recursif
            toutesLesPermutations(villes, debut + 1, fin);
            // On revient à la situation précédente
            swap(villes[debut], villes[i]);
        }
    }
}

double calculTotalDistanceTournee(
    const vector<string>& cities,
    const array<array<double, nombreDeVilles>, nombreDeVilles>& DIST,
    const map<string, tuple<int, int, int>>& data
) {
    double d = 0;

    for (size_t i = 0; i < cities.size(); i++) {
        int city1_id = get<0>(data.at(cities.at(i)));
        int city2_id = get<0>(data.at(cities.at(i + 1 == cities.size() ? 0 : i + 1)));
        d += DIST[city1_id][city2_id];
    }

    return d;
}