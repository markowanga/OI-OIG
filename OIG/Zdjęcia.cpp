/**
 * II Olimpiada Informatyczna Gimnazjalistów
 * Zadanie: Zdjęcia
 * Wynik 100/100
 * Wykonał: Marcin Wątroba
 * http://main.edu.pl/pl/archive/oig/2/zdj
 */

#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

struct sk {
    int poczatek;
    int koniec;
    bool zdarzenie;
    int pole;

};

struct ss {
    int przypiete;
    int max_pod;
    int pocz;
    int kon;

    ss() {
        przypiete = 0;
        max_pod = 0;
    }
};

sk make_sk(bool zd, int pole, int pocz, int kon) {
    sk p;
    p.pole = pole;
    p.zdarzenie = zd;
    p.poczatek = pocz;
    p.koniec = kon;
    return p;
}

bool operator<(sk l1, sk l2) {
    if (l1.pole != l2.pole)
        return l1.pole > l2.pole;
    else return l1.zdarzenie;
}

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
    indeks /= 2;
    while (indeks > 0) {
        tab[indeks].max_pod = max(tab[indeks * 2].przypiete + tab[indeks * 2].max_pod,
                                  tab[indeks * 2 + 1].przypiete + tab[indeks * 2 + 1].max_pod);
        indeks /= 2;
    }
}

void dodaj_do_drzewa(ss *tab, int indeks, int ilosc, int poczatek, int koniec) {
    if (tab[indeks].pocz >= poczatek && koniec >= tab[indeks].kon) {
        tab[indeks].przypiete += ilosc;
        uzupelnij_w_gore(tab, indeks);
    } else {
        if (tab[indeks * 2].kon >= poczatek)
            dodaj_do_drzewa(tab, indeks * 2, ilosc, poczatek, koniec);
        if (tab[indeks * 2 + 1].pocz <= koniec)
            dodaj_do_drzewa(tab, indeks * 2 + 1, ilosc, poczatek, koniec);
    }
}

void przypnij(ss *tab, int poczatek, int koniec) {
    dodaj_do_drzewa(tab, 1, 1, poczatek, koniec);
}

void odepnij(ss *tab, int poczatek, int koniec) {
    dodaj_do_drzewa(tab, 1, -1, poczatek, koniec);
}

void obsluga(sk p, ss *tab) {
    if (!p.zdarzenie)
        przypnij(tab, p.poczatek, p.koniec);
    else odepnij(tab, p.poczatek, p.koniec);
}

int main() {
    int n;
    //scanf_s("%d", &n);
    cin >> n;
    int wielk = wielkosc_drzewa(400001);
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
    // wczytanie poszczegolnych zdjec i utworzenie kolejki
    priority_queue<sk> Kolejka;
    int L, D, P, G;
    for (int a = 0; a < n; a++) {
        cin >> L >> D >> P >> G;
        L += 200000;
        D += 200000;
        P += 200000;
        G += 200000;
        Kolejka.push(make_sk(false, L, D, G));
        Kolejka.push(make_sk(true, P, D, G));
    }
    int wynik = 0;
    while (!Kolejka.empty()) {
        obsluga(Kolejka.top(), tab);
        Kolejka.pop();
        wynik = max(wynik, tab[1].max_pod + tab[1].przypiete);
    }
    cout << wynik;
    system("PAUSE");
    return 0;
}