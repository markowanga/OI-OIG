/**
 * V Olimpiada Informatyczna Gimnazjalistów
 * Zadanie: Park
 * Wynik 100/100
 * Wykonał: Marcin Wątroba
 * http://main.edu.pl/pl/archive/oig/5/par
 */

#include <cstdlib>
#include <cstdio>

using namespace std;

int mm(int a, int b) {
    if (a > b) return a;
    else return b;
}

int main(int argc, char *argv[]) {
    int n;
    scanf("%d", &n);
    int *tab = new int[n];
    int *l = new int[n];
    scanf("%d", &tab[0]);
    l[0] = tab[0];
    for (int a = 1; a < n; a++) {
        scanf("%d", &tab[a]);
        l[a] = mm(l[a - 1], tab[a]);
    }
    for (int a = n - 2; a >= 0; a--)
        if (tab[a + 1] > tab[a])tab[a] = tab[a + 1];
    for (int a = 0; a < n; a++)
        printf("%d %d\n", l[a], tab[a]);

    return EXIT_SUCCESS;
}