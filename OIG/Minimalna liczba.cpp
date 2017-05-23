/**
 * II Olimpiada Informatyczna Gimnazjalistów
 * Zadanie: Minimalna liczba
 * Wynik 100/100
 * Wykonał: Marcin Wątroba
 * http://main.edu.pl/pl/archive/oig/2/min
 */

#include <iostream>
#include <algorithm>

using namespace std;
#define ll long long

int main() {
    ll n, k;
    cin >> n >> k;
    ll *tab = new ll[n];
    for (int a = 0; a < n; a++)
        cin >> tab[a];
    sort(tab, tab + n);
    ll wiel = k;

    bool czy_wynik = false;
    for (int a = 0; a < n; a++) {
        while (wiel <= tab[a]) {
            if (tab[a] != wiel)
                break;
            wiel += k;
        }
    }
    cout << wiel;

    return 0;
}