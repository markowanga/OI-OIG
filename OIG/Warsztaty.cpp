/**
 * IV Olimpiada Informatyczna Gimnazjalistów
 * Zadanie: Warsztaty
 * Wynik 100/100
 * Wykonał: Marcin Wątroba
 * http://main.edu.pl/pl/archive/oig/4/war
 */

#include <iostream>
#include <cstdio>
#include <utility>

using namespace std;

int main() {
    int n, m, k;
    //cin >> n >> m >> k;
    scanf("%d%d%d", &n, &m, &k);
    int *samochody = new int[n];
    for (int a = 0; a < n; a++)
        //cin >> samochody[a];
        scanf("%d", &samochody[a]);
    int *kol = new int[k + 1];
    for (int a = 1; a < k + 1; a++)
        kol[a] = a;

    pair<int, int> *pom = new pair<int, int>[m];
    for (int a = 0; a < m; a++)
        //cin >> pom[a].first >> pom[a].second;
        scanf("%d%d", &pom[a].first, &pom[a].second);

    for (int a = m - 1; a >= 0; a--)
        kol[pom[a].first] = kol[pom[a].second];

    for (int a = 0; a < n; a++)
        //cout << kol[samochody[a]] << " ";
        printf("%d ", kol[samochody[a]]);

    system("PAUSE");
    return 0;
}