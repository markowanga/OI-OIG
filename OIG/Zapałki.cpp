/**
 * V Olimpiada Informatyczna Gimnazjalistów
 * Zadanie: Zapałki
 * Wynik 100/100
 * Wykonał: Marcin Wątroba
 * http://main.edu.pl/pl/archive/oig/5/zap
 */

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, p, licznik = 0, wynik;
    cin >> n;
    bool *tab = new bool[n];
    for (int a = 0; a < n; a++) {
        cin >> p;
        if (p == 0)
            tab[a] = true; //siarka gołe
        else {
            tab[a] = false; // gołe siarka
            licznik++;
        }
    }
    wynik = licznik;
    for (int a = 0; a < n; a++) {
        if (tab[a])
            licznik++;
        else licznik--;
        wynik = min(wynik, licznik);
    }
    cout << wynik;

    return 0;
}