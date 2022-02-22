#include <iostream>
#include <vector>
#include <map>
#include <tuple>
#include <array>
#include <cmath>

using namespace std;

constexpr int codeASCIIde_a = 97;
constexpr int codeASCIIde_A = 65;
constexpr int nombreDeLettres = 26;
constexpr int tailleMinNomVille = 4;
constexpr int tailleMaxNomVille = 12;
constexpr int grainePourLeRand = 1;
constexpr int nombreDeVilles = 3;
constexpr int nombreCombinaisons = 24;
constexpr int tailleCoteCarte = 100;

char chooseRandomLetter();

void toutesLesPermutations(vector<string>& villes, int debut, int fin);

double calculTotalDistanceTournee(
    const vector<string>& cities,
    const array<array<double, nombreDeVilles>, nombreDeVilles>& DIST,
    const map<string, tuple<int, int, int>>& data
);