/**
 * IX Olimpiada Informatyczna
 * Zadanie: Koleje
 * Wynik 100/100
 * Wykonał: Marcin Wątroba
 * http://main.edu.pl/pl/archive/oi/9/kol
 */

#include <iostream>

using namespace std;

struct ss {
    int jedzie;
    int max_pod;
    int pocz;
    int kon;

    ss() {
        jedzie = 0;
        max_pod = 0;
    }
};

int wielkosc_drzewa(int n) {
    n--;
    int l = 1;
    while (l < n)
        l *= 2;
    return l;
}

int max(int a, int b) {
    if (a > b)
        return a;
    return b;
}

void uzupelnij_w_gore(ss *tab, int indeks) {
    int pom;
    while (indeks != 1) {
        pom = tab[indeks].jedzie + tab[indeks].max_pod;
        if (tab[indeks / 2].max_pod < pom)
            tab[indeks / 2].max_pod = pom;
        else return;
        indeks /= 2;
    }
}

void dodaj_pasarzerow(ss *tab, int indeks, int ilosc, int poczatek, int koniec) {
    if (tab[indeks].pocz >= poczatek && koniec >= tab[indeks].kon) {
        tab[indeks].jedzie += ilosc;
        uzupelnij_w_gore(tab, indeks);
    } else {
        if (tab[indeks * 2].kon >= poczatek)
            dodaj_pasarzerow(tab, indeks * 2, ilosc, poczatek, koniec);
        if (tab[indeks * 2 + 1].pocz <= koniec)
            dodaj_pasarzerow(tab, indeks * 2 + 1, ilosc, poczatek, koniec);
    }
}

int ilosc_max_pasarzerow_na_trasie(ss *tab, int poczatek, int koniec, int w_drzewa) {
    if (poczatek <= tab[w_drzewa].pocz && tab[w_drzewa].kon <= koniec)
        return tab[w_drzewa].jedzie + tab[w_drzewa].max_pod;
    int lewa = 0, prawa = 0;
    if (poczatek <= tab[w_drzewa * 2].kon)
        lewa = ilosc_max_pasarzerow_na_trasie(tab, poczatek, koniec, w_drzewa * 2);
    if (tab[w_drzewa * 2 + 1].pocz <= koniec)
        prawa = ilosc_max_pasarzerow_na_trasie(tab, poczatek, koniec, w_drzewa * 2 + 1);
    return tab[w_drzewa].jedzie + max(lewa, prawa);
}

int main() {
    int n, m, z; // il miast, miejsc, zapytan
    //cin >> n >> m >> z;
    scanf("%d%d%d", &n, &m, &z);
    int wielk = wielkosc_drzewa(n);
    ss *tab = new ss[wielk * 2];
    // ustalenie zakresu lisci
    for (int a = 0; a < wielk; a++) {
        tab[wielk + a].pocz = a;
        tab[wielk + a].kon = a;
    }
    // ustalenie zakresu wezlow i korzenia
    for (int p = wielk / 2; p > 0; p /= 2)
        for (int a = p; a < p * 2; a++) {
            tab[a].pocz = tab[a * 2].pocz;
            tab[a].kon = tab[a * 2 + 1].kon;
        }

    int pocz, kon, il;
    for (int a = 0; a < z; a++) {
        scanf("%d%d%d", &pocz, &kon, &il);
        kon -= 2;
        pocz--;
        if (ilosc_max_pasarzerow_na_trasie(tab, pocz, kon, 1) + il <= m) {
            printf("T\n");
            dodaj_pasarzerow(tab, 1, il, pocz, kon);
        } else
            printf("N\n");
    }

    return 0;
}