/**
 * V Olimpiada Informatyczna Gimnazjalistów
 * Zadanie: Obwarzanki
 * Wynik 100/100
 * Wykonał: Marcin Wątroba
 * http://main.edu.pl/pl/archive/oig/5/obw
 */

#include <iostream>
#include <cstdio>
#include <utility>

using namespace std;

int min(int a, int b) {
    if (a > b)
        return b;
    return a;
}

int max(int a, int b) {
    if (a < b)
        return b;
    return a;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    m--;
    pair<int, int> *tab = new pair<int, int>[n];
    for (int a = 0; a < n; a++)
        scanf("%d%d", &tab[a].first, &tab[a].second);
    //sprawdzanie od obwarzaka m do 0
    int lewo = 0;
    pair<int, int> pom = tab[m];
    for (int a = m - 1; a >= 0; a--)
        if (!(tab[a].second <= pom.first || tab[a].first >= pom.second)) {
            lewo++;
            pom.first = min(pom.first, tab[a].first);
            pom.second = max(pom.second, tab[a].second);
        }
    //sprawdzenie prawo
    int prawo = 0;
    pom = tab[m];
    for (int a = m + 1; a < n; a++)
        if (!(tab[a].second <= pom.first || tab[a].first >= pom.second)) {
            prawo++;
            pom.first = min(pom.first, tab[a].first);
            pom.second = max(pom.second, tab[a].second);
        }

    printf("%d", min(lewo, prawo));

    return 0;
}