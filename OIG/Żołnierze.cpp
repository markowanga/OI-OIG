/**
 * II Olimpiada Informatyczna Gimnazjalistów
 * Zadanie: Żołnierze
 * Wynik 100/100
 * Wykonał: Marcin Wątroba
 * http://main.edu.pl/pl/archive/oig/2/zol
 */

#include <iostream>
#include <algorithm>

using namespace std;

bool czy_redukcja = false;

int silnia(int n) {
    int w = 1;
    for (int a = 1; a <= n; a++) {
        w *= a;
        if (w > 9999) {
            czy_redukcja = true;
            w %= 10000;
        }
    }
    return w;
}

int main() {
    int n;
    cin >> n;
    int *tab = new int[n];
    for (int a = 0; a < n; a++)
        cin >> tab[a];
    sort(tab, tab + n);
    int W = 1, l, wz, k = 0;
    for (int a = 0; a < n;) {
        k++;
        wz = tab[a];
        l = 1;
        a++;
        while (a < n) {
            if (tab[a] != wz)
                break;
            l++;
            a++;
        }
        W *= silnia(l);
        if (W > 9999) {
            czy_redukcja = true;
            W %= 10000;
        }
    }
    if (k != 1) {
        W *= 2;
        if (W > 9999) {
            czy_redukcja = true;
            W %= 10000;
        }
    }
    if (czy_redukcja == false)
        cout << W << endl;
    else {
        if (W < 10)
            cout << "000" << W << endl;
        else if (W < 100)
            cout << "00" << W << endl;
        else if (W < 1000)
            cout << "0" << W << endl;
        else cout << W << endl;
    }

    system("PAUSE");
    return 0;
}