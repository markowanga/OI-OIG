/**
 * I Olimpiada Informatyczna Gimnazjalistów
 * Zadanie: Bierki
 * Wynik 100/100
 * Wykonał: Marcin Wątroba
 * http://main.edu.pl/pl/archive/oig/1/bie
 */

#include <iostream>
#include <algorithm>

using namespace std;

int max(int a, int b) {
    if (a > b)
        return a;
    return b;
}

int main() {
    int n;
    cin >> n;
    int *tab = new int[n];
    for (int a = 0; a < n; a++)
        cin >> tab[a];
    sort(tab, tab + n);
    // poruszanie gonsienicą
    int pocz = 0, kon = 2, w = 0;
    for (pocz = 0; pocz < n - 2; pocz++) {
        while (true) {
            if (kon == n) {
                kon--;
                break;
            } else if (tab[pocz] + tab[pocz + 1] > tab[kon])
                kon++;
            else {
                kon--;
                break;
            }
        }
        w = max(w, kon - pocz + 1);
    }
    cout << w << endl;

    return 0;
}