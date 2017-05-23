/**
 * II Olimpiada Informatyczna Gimnazjalistów
 * Zadanie: Ostatnie cyfry
 * Wynik 100/100
 * Wykonał: Marcin Wątroba
 * http://main.edu.pl/pl/archive/oig/2/ost
 */

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;
#define ll long long

struct ss {
    ll l;
    int dl;
};

bool porownanie(ss A, ss B) {
    if (A.l < B.l)
        return true;
    return false;
}

int dlugosc(ss l) {
    if (l.l == 0)
        return 1;
    int w = 0;
    while (l.l != 0) {
        w++;
        l.l /= 10;
    }
    return w;
}

ll skrac(ll l, int k) {
    ll m = 1;
    ll w;
    w = 0;
    for (int a = 0; a < k; a++) {
        w += l % 10 * m;
        m *= 10;
        l /= 10;
    }
    return w;
}

ll POT(ss l, int k, int a) {
    ss w = l;
    for (int i = 1; i < a; i++) {
        w.l *= l.l;
        w.l = skrac(w.l, k);
    }
    return w.l;
}


int main() {
    int k, a, dl;
    ll pom, i;
    ss p;
    cin >> k >> a;
    vector<ss> tab;
    queue<ss> K;
    p.dl = 1;
    for (ll i = 0; i < 10; i++) {
        p.l = i;
        K.push(p);
    }
    while (!K.empty()) {
        pom = POT(K.front(), k, a);
        if (K.front().l == pom && K.front().dl == dlugosc(K.front())) {
            tab.push_back(K.front());
        }
        dl = K.front().dl;
        if (K.front().l == skrac(pom, dl) && dl != k) {
            p.dl = K.front().dl + 1;
            i = (ll) pow(10, K.front().dl);
            for (int o = 0; o < 10; o++) {
                p.l = i * o + K.front().l;
                K.push(p);
            }
        }
        K.pop();
    }

    sort(tab.begin(), tab.end(), porownanie);
    for (int s = 0; s < (int) tab.size(); s++)
        cout << tab[s].l << " ";

    system("PAUSE");
    return 0;
}