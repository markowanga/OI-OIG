/**
 * IV Olimpiada Informatyczna Gimnazjalistów
 * Zadanie: Kosmiczny pościg
 * Wynik 100/100
 * Wykonał: Marcin Wątroba
 * http://main.edu.pl/pl/archive/oig/4/kos
 */

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <utility>

using namespace std;
#define ll long long

int main() {
    int n;
    scanf("%d", &n);
    ll v, a, v1, a1;
    scanf("%lld%lld", &a, &v);
    pair<ll, int> *tab = new pair<ll, int>[n];
    for (int i = 0; i < n; i++) {
        tab[i].second = i + 1;
        scanf("%lld%lld", &a1, &v1);
        a1 = a - a1;
        v1 -= v;
        if (v1 * a1 <= 0)
            tab[i].first = 1000000000000LL;
        else {
            tab[i].first = a1 / v1;
            if (a1 % v1 != 0)
                tab[i].first++;
        }
    }
    sort(tab, tab + n);
    bool czy_ok = true;
    for (int i = 0; i < n; i++)
        if (tab[i].first <= i) {
            czy_ok = false;
            break;
        }
    if (!czy_ok)
        printf("GAME OVER\n");
    else
        for (int i = 0; i < n; i++)
            printf("%d ", tab[i].second);

    system("PAUSE");
    return 0;
}