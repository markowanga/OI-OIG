/**
 * VI Olimpiada Informatyczna Gimnazjalistów
 * Zadanie: Dwa słowa
 * Wynik 100/100
 * Wykonał: Marcin Wątroba
 * http://main.edu.pl/pl/archive/oig/6/dwa
 */

#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

struct zn {
    char z1;
    char z2;
    int por;
};

int rt(int n) {
    int w = 1;
    while (w < n)w *= 2;
    return w;
}

int por(char a, char b) {
    if ((int) a > (int) b) return 1;
    else if ((int) a < (int) b) return 2;
    else return 0;
}

void zam(char tab[2][1000000], int zz1, int zz2) {
    char p = tab[0][zz1];
    tab[0][zz1] = tab[1][zz2];
    tab[1][zz2] = p;
}

void uzu(zn tab[], int rtab, int n) {
    for (int b = (n + rtab) / 2; b > 0; b /= 2) {
        if (tab[b + b].por != 0) {
            if (tab[b].por == tab[b + b].por)return;
            tab[b].por = tab[b + b].por;
        } else {
            if (tab[b].por == tab[b + b + 1].por)return;
            tab[b].por = tab[b + b + 1].por;
        }
    }
    return;
}

int main(int argc, char *argv[]) {
    int n;
    scanf("%d", &n);
    int rtab = rt(n);
    zn *tab = new zn[rtab * 2];
    char t[2][1000000];
    scanf("%s%s", &t[0], &t[1]);
    for (int a = rtab + n; a < rtab * 2; a++) tab[a].por = 0;
    for (int a = rtab; a < rtab + n; a++) tab[a].por = por(t[0][a - rtab], t[1][a - rtab]);
    //UZUPELNIENIE WEZLOW
    for (int a = rtab / 2; a > 0; a /= 2)
        for (int b = a; b < a + a; b++) {
            if (tab[b + b].por != 0)
                tab[b].por = tab[b + b].por;
            else tab[b].por = tab[b + b + 1].por;
        }
    int j;
    scanf("%d", &j);
    int zz1, zz2;
    for (int i = 0; i < j; i++) {
        scanf("%d%d", &zz1, &zz2);
        if (t[0][zz1] != t[1][zz2]) {
            zam(t, zz1, zz2);
            tab[zz1 + rtab].por = por(t[0][zz1], t[1][zz1]);
            tab[zz2 + rtab].por = por(t[0][zz2], t[1][zz2]);
            uzu(tab, rtab, zz1);
            if (zz1 != zz2)uzu(tab, rtab, zz2);
        }
        printf("%d\n", tab[1].por);
    }

    return EXIT_SUCCESS;
}