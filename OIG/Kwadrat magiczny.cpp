/**
 * IV Olimpiada Informatyczna Gimnazjalistów
 * Zadanie: Kwadrat magiczny
 * Wynik 100/100
 * Wykonał: Marcin Wątroba
 * http://main.edu.pl/pl/archive/oig/4/kwa
 */

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <utility>

using namespace std;
#define ll long long

void sumy_przekatnych(ll **tab, int n, ll &d1, ll &d2) {
    d1 = 0;
    d2 = 0;
    ll pom;
    for (int a = 0; a < n; a++) {
        pom = d1;
        d1 += tab[a][a];
        if (pom > d1) {
            d1 = pom;
            break;
        }
    }
    for (int a = 0; a < n; a++) {
        pom = d2;
        d2 += tab[a][n - a - 1];
        if (pom > d2) {
            d2 = pom;
            break;
        }
    }
}

void wys(ll **tab, int n) {
    for (int a = 0; a < n; a++) {
        for (int b = 0; b < n; b++)
            //cout << tab[a][b] << " ";
            printf("%lld ", tab[a][b]);
        //cout << endl;
        printf("\n");
    }
}

void uzupelnij(ll **tab, pair<int, ll> *pom, int n, ll suma_magiczna) {
    for (int a = 0; a < n; a++)
        tab[a][pom[a].first] = suma_magiczna - pom[a].second;
}

bool czy_magiczny(ll **tab, int n) {
    int S1 = 0, S2;
    for (int a = 0; a < n; a++)
        S1 += tab[0][a];
    for (int a = 0; a < n; a++) {
        S2 = 0;
        for (int b = 0; b < n; b++)
            S2 += tab[a][b];
        if (S1 != S2)
            return false;
    }

    S2 = 0;
    for (int a = 0; a < n; a++)
        S2 += tab[a][a];
    if (S1 != S2)
        return false;

    S2 = 0;
    for (int a = 0; a < n; a++)
        S2 += tab[a][n - a - 1];
    if (S1 != S2)
        return false;

    return true;
}

int main() {
    int n;
    //cin >> n;
    scanf("%d", &n);
    ll **tab = new ll *[n];
    pair<int, ll> *pom = new pair<int, ll>[n];
    ll max = 1, d1, d2, suma_magiczna, pocz, kon;
    for (int a = 0; a < n; a++) {
        tab[a] = new ll[n];
        pom[a].second = 0;
        for (int b = 0; b < n; b++) {
            //cin >> tab[a][b];
            scanf("%lld", &tab[a][b]);
            pom[a].second += tab[a][b];
            if (tab[a][b] == 0)
                pom[a].first = b;
        }
        if (max < pom[a].second)
            max = pom[a].second;
    }

    int il_d1 = 0, il_d2 = 0;
    for (int a = 0; a < n; a++)
        if (tab[a][a] == 0)
            il_d1++;
    for (int a = 0; a < n; a++)
        if (tab[a][n - a - 1] == 0)
            il_d2++;

    // kolejne przypadki
    if (n == 1)
        tab[0][0] = 1;
    else if (il_d1 == 0 || il_d2 == 0) {
        sumy_przekatnych(tab, n, d1, d2);
        if (d1 > d2) suma_magiczna = d1;
        else suma_magiczna = d2;
        uzupelnij(tab, pom, n, suma_magiczna);
    } else if (il_d1 == 1 && il_d2 == 1) {
        vector<ll> Z;
        for (int a = 0; a < n; a++)
            for (int b = 0; b < n; b++)
                Z.push_back(tab[a][b]);
        sort(Z.begin(), Z.end());
        suma_magiczna = max;
        bool w = false;
        while (w == false) {
            w = true;
            suma_magiczna++;
            for (int a = 0; a < n; a++) {
                if (binary_search(Z.begin(), Z.end(), suma_magiczna - pom[a].second) == true) {
                    w = false;
                    break;
                }
                tab[a][pom[a].first] = suma_magiczna - pom[a].second;
            }
        }
    } else {
        pocz = max + 1;
        kon = 2000000000000000000LL;
        while (pocz < kon) {
            //cout << pocz << " -- " << kon << endl;
            suma_magiczna = (pocz + kon) / 2;
            uzupelnij(tab, pom, n, suma_magiczna);
            sumy_przekatnych(tab, n, d1, d2);
            //cout << "SM: " << suma_magiczna << endl;
            //cout << "D1: " << d1 << endl;
            //cout << "D2: " << d2 << endl;
            if (d1 < suma_magiczna || d2 < suma_magiczna) {
                pocz = suma_magiczna + 1;
                //cout << "GORA" << endl;
            } else {
                kon = suma_magiczna;
                //cout << "DOL" << endl;
            }
        }
        suma_magiczna = pocz;
        uzupelnij(tab, pom, n, suma_magiczna);
        //sumy_przekatnych(tab, n, d1, d2);
        //cout << "SM: " << suma_magiczna << endl;
        //cout << "D1: " << d1 << endl;
        //cout << "D2: " << d2 << endl << endl;
    }

    //if (czy_magiczny(tab, n) == true)
    //	cout << "KWADRAT MAGICZNY" << endl;
    //else cout << "LIPA" << endl;
    wys(tab, n);

//	system("PAUSE");
    return 0;
}