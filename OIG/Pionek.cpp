/**
 * V Olimpiada Informatyczna Gimnazjalistów
 * Zadanie: Pionek
 * Wynik 100/100
 * Wykonał: Marcin Wątroba
 * http://main.edu.pl/pl/archive/oig/5/pio
 */

#include <iostream>

using namespace std;

#define ll long long

ll euklides(ll a, ll b) {
    while (true) {
        if (a > b) {
            a = a % b;
            if (a == 0)
                return b;
        } else {
            b = b % a;
            if (b == 0)
                return a;
        }
    }
}

int main() {
    // wczytanie danych
    int n, m;
    ll x1, x2, y1, y2;
    //(x1, y1) - lewy dolny
    //(x2, y2) - prawy górny
    cin >> n >> m;
    cin >> x1 >> y1 >> x2 >> y2;
    x1--;
    x2--;
    y1--;
    y2--;
    ll nwd_poz, nwd_pion, p;
    // NWD poziome
    cin >> nwd_poz;
    for (int a = 1; a < n; a++) {
        cin >> p;
        nwd_poz = euklides(nwd_poz, p);
    }
    // NWD pionowe
    cin >> nwd_pion;
    for (int a = 1; a < m; a++) {
        cin >> p;
        nwd_pion = euklides(nwd_pion, p);
    }
    // ok

    // policzenie jaki bok pionowy
    ll dol, gora;
    // dol
    dol = y1 / nwd_pion;
    if (y1 > 0 && y1 % nwd_pion != 0)
        dol++;
    // gora
    gora = y2 / nwd_pion;
    if (y2 < 0 && y2 % nwd_pion != 0)
        gora--;

    // policzenie jaki bok poziomy
    ll lewo, prawo;
    // lewo
    lewo = x1 / nwd_poz;
    if (x1 > 0 && x1 % nwd_poz != 0)
        lewo++;
    // prawo
    prawo = x2 / nwd_poz;
    if (x2 < 0 && x2 % nwd_poz != 0)
        prawo--;

    ll b_pion, b_poz;
    b_pion = gora - dol + 1;
    b_poz = prawo - lewo + 1;

    cout << b_poz * b_pion;

    return 0;
}