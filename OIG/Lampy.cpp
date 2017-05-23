/**
 * VI Olimpiada Informatyczna Gimnazjalistów
 * Zadanie: Lampy
 * Wynik 100/100
 * Wykonał: Marcin Wątroba
 * http://main.edu.pl/pl/archive/oig/6/lam
 */

#include <cstdlib>
#include <iostream>
#include <math.h>
#include<iomanip>

using namespace std;

struct pkt {
    long double odpoc;
    int ilcz;
    long double rpol;
    long double pole;
    long double polealt;
    int nr;
};

int zroz(int a) {
    int w = 2;
    while (a > w)
        w *= 2;
    return w;
}

int main(int argc, char *argv[]) {
    int N, K, D;
    cin >> N >> K >> D;
    int rtab = zroz(N - 1);
    pkt *tab = new pkt[2 * rtab];
    long double tt[N];
    for (int a = 0; a < N; a++)
        cin >> tt[a];
    for (int a = 0; a < N - 1; a++) {
        tab[rtab + a].odpoc = tt[a + 1] - tt[a];
        tab[rtab + a].nr = a + rtab;
        tab[rtab + a].ilcz = 1;
        tab[rtab + a].pole =
                ((tab[rtab + a].odpoc / tab[rtab + a].ilcz) * (tab[rtab + a].odpoc / tab[rtab + a].ilcz) / 4) *
                tab[rtab + a].ilcz;
        tab[rtab + a].polealt =
                ((tab[rtab + a].odpoc / (tab[rtab + a].ilcz + 1)) * (tab[rtab + a].odpoc / (tab[rtab + a].ilcz + 1)) /
                 4) * (tab[rtab + a].ilcz + 1);
        tab[rtab + a].rpol = tab[rtab + a].pole - tab[rtab + a].polealt;
        //cout<<"rpol"<<tab[rtab+a].rpol<<endl;
    }
    for (int a = N - 1; a < rtab; a++) {
        tab[rtab + a].rpol = 0;
        tab[rtab + a].odpoc = 0;
        tab[rtab + a].nr = a + rtab;
    }
    //UZUPEŁNIANIE TABLICY
    for (int a = rtab / 2; a > 0; a /= 2) {
        for (int b = a; b < a + a; b++) {
            if (tab[tab[b + b].nr].rpol > tab[tab[b + b + 1].nr].rpol) {
                tab[b].nr = tab[b + b].nr;
            } else {
                tab[b].nr = tab[b + b + 1].nr;
            }
        }
    }
    if (N > 2) {
        //WYKONYWANIE ZADANIA
        for (int i = 0; i < K; i++) {
            tab[tab[1].nr].ilcz++;
            tab[tab[1].nr].pole = tab[tab[1].nr].polealt;
            tab[tab[1].nr].polealt = ((tab[tab[1].nr].odpoc / (tab[tab[1].nr].ilcz + 1)) *
                                      (tab[tab[1].nr].odpoc / (tab[tab[1].nr].ilcz + 1)) / 4) *
                                     (tab[tab[1].nr].ilcz + 1);
            tab[tab[1].nr].rpol = tab[tab[1].nr].pole - tab[tab[1].nr].polealt;
            for (int b = tab[1].nr / 2; b > 0; b /= 2) {
                if (tab[tab[b + b].nr].rpol > tab[tab[b + b + 1].nr].rpol) {
                    tab[b].nr = tab[b + b].nr;
                } else {
                    tab[b].nr = tab[b + b + 1].nr;
                }
            }
        }
        long double suma = 0;
        for (int a = 0; a < N - 1; a++) {
            suma = suma + tab[a + rtab].pole;
        }
        cout << fixed << setprecision(9) << suma;
    } else
        cout << fixed << setprecision(9) << (((long double) D / (K + 1)) * ((long double) D / (K + 1)) / 4) * (K + 1);
    system("pause");
    return EXIT_SUCCESS;
}