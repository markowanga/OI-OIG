/**
 * III Olimpiada Informatyczna Gimnazjalistów
 * Zadanie: Domek
 * Wynik 100/100
 * Wykonał: Marcin Wątroba
 * http://main.edu.pl/pl/archive/oig/3/dom
 */

#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

struct wezel {
    int ile_kart_max;
    int stopien;
    int il;
    vector<int> tab;
};

int w(int ilosc_max, vector<int> v1, vector<int> v2) {
    if (ilosc_max == 0)
        return 0;
    int mm = v1[0];
    for (int a = 0; a <= min(ilosc_max, v1.size() - 1); a++)
        for (int b = 0; b <= min(ilosc_max - a, v2.size() - 1); b++)
            mm = max(mm, v1[a] + v2[b]);
    return mm;
}

int main() {
    int n, k;
    cin >> n >> k;
    k /= 2;

    // utworzenie drzewa
    int wDrzewa = pow(2, (double) n);
    wezel *D = new wezel[wDrzewa];

    // wczytanie wartości drzewa
    int p1, p2;
    for (int a = 1; a < wDrzewa; a++) {
        cin >> p1 >> p2;
        D[a].il = p1 + p2;
        D[a].tab.push_back(0);
    }

    // uzupelnienie liści
    for (int a = wDrzewa / 2; a < wDrzewa; a++) {
        D[a].stopien = n;
        D[a].ile_kart_max = 1;
        D[a].tab.push_back(D[a].il);
    }

    int p = 2;
    for (int a = 1; a < wDrzewa; a++) {
        if (a == p) {
            p *= 2;
        }
    }

    // uzupelnianie kolejnych wezłów
    for (int a = wDrzewa / 4; a >= 1; a /= 2)
        for (int b = a; b < a * 2; b++) {
            //cout << "zaczynam "<<a<<" "<<b << endl;
            D[b].stopien = D[b * 2].stopien - 1;
            // ilość jaką można pozyskać z poniższych struktór
            int il1 = D[b * 2].ile_kart_max * 2 + 1;
            // ilość obliczona na podst stopnia (n) i ilości (k)
            int il2 = k - D[b].stopien + 1;
            D[b].ile_kart_max = min(il1, il2);
            for (int c = 1; c <= D[b].ile_kart_max; c++) {
                D[b].tab.push_back(w(c - 1, D[b * 2].tab, D[b * 2 + 1].tab) + D[b].il);
            }
        }
    if (D[1].tab[D[1].tab.size() - 1] > 0)
        cout << D[1].tab[D[1].tab.size() - 1] << endl;
    else cout << 0 << endl;

    return 0;
}