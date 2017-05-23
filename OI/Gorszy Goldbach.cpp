/**
 * VIII Olimpiada Informatyczna
 * Zadanie: Gorszy Goldbach
 * Wynik 100/100
 * Wykonał: Marcin Wątroba
 * http://main.edu.pl/pl/archive/oi/8/gol
 */

#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;
#define vec vector<int>
#define vec_b vector<bool>
#define ll long long
vector<vec > rozklad(10);
vector<pair<ll, int> > przedzialy(1);// f-max, s-l_pier
vec n_primes;

void dodaj_prim() {
    n_primes.push_back(3);
    n_primes.push_back(5);
    n_primes.push_back(7);
    n_primes.push_back(11);
    n_primes.push_back(13);
    n_primes.push_back(17);
    n_primes.push_back(19);
}

bool if_prime(int l) {
    for (int a = 2; a * a <= l; a++)
        if (l % a == 0)
            return false;
    return true;
}

int next_prime() {
    int l = n_primes[n_primes.size() - 1] - 1;
    while (!if_prime(l))
        l++;
    return l;
}

int prevoius_prime(int l) {
    l--;
    while (!if_prime(l))
        l--;
    return l;
}

vec_b rozklad_bin(int l) {
    vec_b tab(n_primes.size());
    for (int a = 0; a < n_primes.size(); a++)
        tab[a] = false;
    int ind = 0;
    while (l > 0) {
        if (l % 2 == 1)
            tab[ind] = true;
        ind++;
        l /= 2;
    }
    return tab;
}

vec szukaj_rozkladu_elementarnego(int l) {
    vec w;
    vec_b pom;
    for (int a = 1; a < (int) pow(n_primes.size() + 1, 2); a++) {
        pom = rozklad_bin(a);
        int p = 0;
        for (int i = 0; i < n_primes.size(); i++)
            if (pom[i])
                p += n_primes[i];
        if (p == l) {
            for (int i = 0; i < n_primes.size(); i++)
                if (pom[i])
                    w.push_back(n_primes[i]);
            return w;
        }
    }
    return w;
}

void rozkladaj() {
    vec pp;
    bool rozklad_mozliwy = true;
    while (rozklad_mozliwy) {
        pp = szukaj_rozkladu_elementarnego(rozklad.size());
        if (pp.size() != 0)
            rozklad.push_back(pp);
        else rozklad_mozliwy = false;
    }
}

void uzupelnij_przedzialy() {
    przedzialy[0].first = rozklad.size() - 1;
    przedzialy[0].second = n_primes.back();
    while (przedzialy.back().first <= 2000000000) {
        ll pom = prevoius_prime((int) przedzialy.back().first - 8);
        przedzialy.push_back(make_pair(przedzialy.back().first + pom, pom));
    }
}

vec rozklad_liczby(int l) {
    vec pp;
    for (int licznik = przedzialy.size() - 1; licznik >= 1; licznik--) {
        if (przedzialy[licznik].first - przedzialy[licznik].second + 1 <= l) {
            pp.push_back(przedzialy[licznik].second);
            l -= przedzialy[licznik].second;
        }
    }
    for (int a = 0; a < rozklad[l].size(); a++)
        pp.push_back(rozklad[l][a]);
    sort(pp.begin(), pp.end());
    return pp;
}

int main() {
    dodaj_prim();
    rozkladaj();
    uzupelnij_przedzialy();
    int n, l;
    vec w;
    cin >> n;
    for (int a = 0; a < n; a++) {
        cin >> l;
        w = rozklad_liczby(l);
        cout << w.size() << endl;
        for (int i = 0; i < w.size(); i++)
            cout << w[i] << " ";
        cout << endl;
    }

    return 0;
}