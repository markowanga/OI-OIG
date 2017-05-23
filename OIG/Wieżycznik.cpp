/**
 * IV Olimpiada Informatyczna Gimnazjalistów
 * Zadanie: Wieżycznik
 * Wynik 100/100
 * Wykonał: Marcin Wątroba
 * http://main.edu.pl/pl/archive/oig/4/wie
 */

#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

long long suma(int *v, int poczatek, int koniec) {
    long long s = 0;
    for (poczatek; poczatek < koniec; poczatek++)
        s += v[poczatek];
    return s;
}

bool comp(pair<int, int *> v1, pair<int, int *> v2) {
    if (v1.first > v2.first)
        return true;
    return false;
}

int main() {
    // wczytanie danych
    int n, il, dl;
    // cin >> n;
    scanf("%d", &n);
    pair<int, int *> *tab = new pair<int, int *>[n];
    for (int a = 0; a < n; a++) {
        // cin >> tab[a].first;
        scanf("%d", &tab[a].first);
        tab[a].second = new int[tab[a].first];
        for (int b = 0; b < tab[a].first; b++)
            // cin >> tab[a].second[b];
            scanf("%d", &tab[a].second[b]);
    }

    // sortowanie wież od największej do najmniejszej
    sort(tab, tab + n, comp);

    // szukanie warstwami
    long long max_nad_maksami, max_przedz, calk = 0, pom;
    int ind_odliczania = n - 1, poczatek, koniec = 0;
    bool czy_pierwsze;
    bool pierwszy_przedz = true;
    while (ind_odliczania != -1) {
        poczatek = koniec;
        koniec = tab[ind_odliczania].first;
        czy_pierwsze = true;
        for (int a = ind_odliczania; a >= 0; a--) {
            if (ind_odliczania == a && koniec == tab[a].first)
                ind_odliczania--;
            pom = suma(tab[a].second, poczatek, koniec);
            if (czy_pierwsze) {
                max_przedz = pom;
                czy_pierwsze = false;
            } else if (max_przedz < pom)
                max_przedz = pom;
        }
        calk += max_przedz;
        if (pierwszy_przedz) {
            pierwszy_przedz = false;
            max_nad_maksami = calk;
        } else if (max_nad_maksami < calk)
            max_nad_maksami = calk;
    }
    // cout << max_nad_maksami << endl;
    printf("%lld\n", max_nad_maksami);

    system("PAUSE");
    return 0;
}