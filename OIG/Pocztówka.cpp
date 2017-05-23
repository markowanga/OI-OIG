/**
 * III Olimpiada Informatyczna Gimnazjalistów
 * Zadanie: Pocztówka
 * Wynik 100/100
 * Wykonał: Marcin Wątroba
 * http://main.edu.pl/pl/archive/oig/3/poc
 */

#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int *tab = new int[n];
    for (int a = 0; a < n; a++)
        cin >> tab[a];
    int *ost = new int[n];

    int l = -1;
    for (int a = n - 1; a >= 0; a--) {
        if (tab[a] >= m)
            l = a;
        ost[a] = l;
    }

    long long W = 0;
    for (int a = 0; a < n; a++) {
        if (ost[a] == -1)
            break;
        W += n - 1 - ost[a] + 1;
    }
    cout << W << endl;

    system("PAUSE");
    return 0;
}