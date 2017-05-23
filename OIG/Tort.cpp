/**
 * V Olimpiada Informatyczna Gimnazjalistów
 * Zadanie: Tort
 * Wynik 100/100
 * Wykonał: Marcin Wątroba
 * http://main.edu.pl/pl/archive/oig/5/tor
 */

#include <iostream>
#include <algorithm>

using namespace std;

#define ll long long

ll ile_nie_mniejszych(ll wart, ll *poz, ll *pion, ll n) {
    ll wynik = 0;
    ll k = 0;
    for (int a = 0; a <= n; a++) {
        while (k <= n && poz[a] * pion[n - k] >= wart)
            k++;
        wynik += k;
    }
    return wynik;
}


int main() {
    ll a, b, n, pocz, pom;
    ll k;
    cin >> a >> b >> n >> k;
    ll *poz = new ll[n + 1];
    ll *pion = new ll[n + 1];

    // poz
    pocz = 0;
    for (int i = 0; i < n; i++) {
        cin >> pom;
        poz[i] = pom - pocz;
        pocz = pom;
    }
    poz[n] = a - pocz;

    // pion
    pocz = 0;
    for (int i = 0; i < n; i++) {
        cin >> pom;
        pion[i] = pom - pocz;
        pocz = pom;
    }
    pion[n] = b - pocz;

    sort(poz, poz + n + 1);
    sort(pion, pion + n + 1);

    // szukanie binarne
    ll poczatek = 1, koniec = a * b, srodek;
    while (poczatek < koniec) {
        srodek = (poczatek + koniec + 1) / 2;
        if (ile_nie_mniejszych(srodek, poz, pion, n) >= k)
            poczatek = srodek;
        else
            koniec = srodek - 1;
    }
    cout << poczatek;

    return 0;
}