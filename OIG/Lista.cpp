/**
 * II Olimpiada Informatyczna Gimnazjalistów
 * Zadanie: Lista
 * Wynik 100/100
 * Wykonał: Marcin Wątroba
 * http://main.edu.pl/pl/archive/oig/2/lis
 */

#include <iostream>

using namespace std;
#define ll long long

struct przedzial {
    ll pp;
    ll pk;
    ll z1;
    ll z2;
};

ll suma(ll a, ll b) {
    return (ll) ((float) (a + b) / 2 * (b - a + 1));
}

int main() {
    int n, k, i, j;
    cin >> n >> k >> i >> j;
    przedzial p1, p2;

    p1.pp = 1;
    p1.z1 = n - k + 1;
    p1.pk = k;
    p1.z2 = n;

    p2.pp = k + 1;
    p2.z1 = 1;
    p2.pk = n;
    p2.z2 = n - k;

    ll wynik = 0;

    // pierwszy przedział
    if (i <= p1.pk) {
        if (j >= p1.pk)
            wynik += suma(p1.z1 + i - 1, p1.z2);
        else
            wynik += suma(p1.z1 + i - 1, p1.z1 + j - 1);
    }

    // drugi przedział
    if (j >= p2.pp) {
        if (p2.pp >= i)
            wynik += suma(p2.z1, p2.z1 + j - p2.pp);
        else
            wynik += suma(p2.z1 + i - p2.pp, p2.z1 + j - p2.pp);
    }
    cout << wynik << endl;

    system("PAUSE");
    return 0;
}