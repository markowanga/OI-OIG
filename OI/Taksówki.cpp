/**
 * XX Olimpiada Informatyczna
 * Zadanie: Taksówki
 * Wynik 100/100
 * Wykonał: Marcin Wątroba
 * http://main.edu.pl/pl/archive/oi/20/tak
 */

#include <iostream>
#include <algorithm>

using namespace std;

#define ll long long

int il_taksowek(ll d, ll m, ll n, ll *tab) {
    if (d + m <= tab[n - 1])
        return 1;
    // jeśli taksówka o najdłuższym zasięgu do radę obrócić sama
    ll odl_ost = m - d;
    int ind = n - 1;
    // najmniejsza taksówka która może pojechać z bazy
    // szukanie wspomnianej taksówki
    while (odl_ost <= tab[ind]) {
        ind--;
        if (ind == -1) break;
    }
    ind++;

    if (ind == n)
        return 0;
    // jeśli żadna taksówka nie jest w stanie pojechać z bazy to kurs nieosiągalny
    ll odl_gl = 0;
    int licznik = 0;
    for (int a = n - 1; a >= 0; a--) {
        if (a != ind) {
            tab[a] -= d - odl_gl;
            if (tab[a] <= 0)
                return 0;
            odl_gl += tab[a];
            licznik++;
            if (odl_gl >= m)
                return licznik;
            if (odl_gl >= d)
                return licznik + 1;
            if ((d - odl_gl) * 2 + odl_ost <= tab[ind])
                return licznik + 1;
        }
    }
    return 0;
}

int main() {
    ll d, m, n;
    cin >> m >> d >> n;
    ll *tab = new ll[n];
    for (int a = 0; a < n; a++)
        cin >> tab[a];
    sort(tab, tab + n);
    cout << il_taksowek(d, m, n, tab);

    return 0;
}