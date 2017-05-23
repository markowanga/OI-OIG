/**
 * VIII Olimpiada Informatyczna
 * Zadanie: Mapa gęstości
 * Wynik 100/100
 * Wykonał: Marcin Wątroba
 * http://main.edu.pl/pl/archive/oi/8/map
 */

#include <cstdio>

using namespace std;
#define sh short

sh max(sh a, sh b) {
    if (a > b)
        return a;
    return b;
}

sh min(sh a, sh b) {
    if (a < b)
        return a;
    return b;
}

int main() {
    sh n, r, p;
    scanf("%hd%hd", &n, &r);
    sh **tab = new sh *[n + 1];
    for (sh a = 0; a <= n; a++)
        tab[a] = new sh[n + 1];
    for (sh a = 0; a < n + 1; a++) {
        tab[a][0] = 0;
        tab[0][a] = 0;
    }
    //uzupelnienie macierzy sum
    for (sh a = 1; a < n + 1; a++)
        for (sh b = 1; b < n + 1; b++) {
            scanf("%hd", &p);
            tab[a][b] = p + tab[a - 1][b] + tab[a][b - 1] - tab[a - 1][b - 1];
        }

    // wyswietlenie wyniku
    for (sh a = 1; a < n + 1; a++) {
        for (sh b = 1; b < n + 1; b++)
            printf("%hd ", tab[min(a + r, n)][min(b + r, n)] + tab[max(a - r - 1, 0)][max(b - r - 1, 0)]
                           - tab[max(a - r - 1, 0)][min(b + r, n)] - tab[min(a + r, n)][max(b - r - 1, 0)]);
        printf("\n");
    }

    return 0;
}