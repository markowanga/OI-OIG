/**
 * III Olimpiada Informatyczna Gimnazjalistów
 * Zadanie: Taśma
 * Wynik 100/100
 * Wykonał: Marcin Wątroba
 * http://main.edu.pl/pl/archive/oig/3/tas
 */

#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int m, n;
    //cin >> m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        //cin >> n;
        scanf("%d", &n);
        int *tab = new int[n];
        for (int a = 0; a < n; a++)
            //cin >> tab[a];
            scanf("%d", &tab[a]);
        int r1 = 0, r2 = 0;
        for (int a = 0; a < n; a++)
            if (tab[a] != tab[n - 1]) {
                r1 = n - a - 1;
                break;
            }
        for (int a = n - 1; a >= 0; a--)
            if (tab[a] != tab[0]) {
                r2 = a;
                break;
            }
        if (r1 < r2)
            swap(r1, r2);
        if (r1 == 0)
            //cout << "BRAK" << endl;
            printf("BRAK\n");
        else //cout << r1;
            printf("%d\n", r1);
    }

    system("PAUSE");
    return 0;
}