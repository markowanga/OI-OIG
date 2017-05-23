/**
 * VIII Olimpiada Informatyczna
 * Zadanie: Przedziały
 * Wynik 100/100
 * Wykonał: Marcin Wątroba
 * http://main.edu.pl/pl/archive/oi/8/prz
 */

#include <cstdio>
#include <utility>
#include <algorithm>

using namespace std;
#define ss pair<int, int>

int max(int a, int b) {
    if (a > b)
        return a;
    return b;
}

int main() {
    int n;
    scanf("%d", &n);
    ss *tab = new ss[n];
    for (int a = 0; a < n; a++)
        scanf("%d%d", &tab[a].first, &tab[a].second);
    sort(tab, tab + n);

    ss pom = tab[0];
    for (int a = 1; a < n; a++) {
        if (pom.second < tab[a].first) {
            printf("%d %d\n", pom.first, pom.second);
            pom = tab[a];
        } else {
            pom.second = max(tab[a].second, pom.second);
        }
    }
    printf("%d %d\n", pom.first, pom.second);

    return 0;
}