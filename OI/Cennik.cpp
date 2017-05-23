/**
 * XX Olimpiada Informatyczna
 * Zadanie: Cennik
 * Wynik 100/100
 * Wykonał: Marcin Wątroba
 * http://main.edu.pl/pl/archive/oi/20/cen
 */

#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

struct kol {
    int krok;
    int miasto;
    bool stan;
    int wczes;
};

// zmienne główne
vector<int> kraw1[100001], kraw2[100001];
// kraw1 stałe - nie usuwamy, kraw2 usuwamy krawedzie;
set<int> z_kraw[100001];
// zbior krawedzi - dzięki niemu dowiemy się czy mamy krawędź łączącą 2 elementy
int odl_kol[100001], odl_lot[100001];
// tablice przechowywujące odległości do danego miasta od pkt startowego przez kolej i loty
int cennik[100001];
// tablica z najtańszymi cenami za przejazdy

int minimum(int a, int b) {
    if (a > b)
        return b;
    return a;
}

int cena(int i_kol, int i_lot, int a, int b) {
    if (i_lot != 2000000000) {
        if (i_kol % 2 == 0)
            return minimum(i_kol * a, i_lot * b);
        else
            return minimum((i_kol - 1) / 2 * b + a, i_lot * b);
    } else {
        if (i_kol % 2 == 0)
            return i_kol * a;
        else
            return minimum((i_kol - 1) / 2 * b + a, i_kol * a);
    }
}

void szukaj_odl_kol(int n, int k) {
    bool *cj = new bool[n + 1];
    for (int a = 1; a < n + 1; a++)
        cj[a] = false;
    queue<int> K;
    int krok, pom;
    int miasto;
    // dodanie powiwszego miasta do kolejki
    K.push(k);
    cj[k] = true;
    odl_kol[k] = 0;
    // kolejka puszczona i samogenerująca się
    while (!K.empty()) {
        miasto = K.front();
        krok = odl_kol[miasto] + 1;
        for (int a = 0; a < kraw1[miasto].size(); a++)
            if (!cj[kraw1[miasto][a]]) {
                pom = kraw1[miasto][a];
                odl_kol[pom] = krok;
                cj[pom] = true;
                K.push(pom);
            }
        K.pop();
    }
}

void szukaj_odl_lot(int n, int k) {
    bool *cj = new bool[n + 1];
    for (int a = 1; a < n + 1; a++) {
        cj[a] = false;
        odl_lot[a] = 2000000000;
    }
    // utworzenie kolejki i zmiennych pomocniczych
    queue<kol> K;
    kol obec;
    kol nowa;

    // dodanie pierwszego elementu do kolejki
    obec.krok = 0;
    obec.miasto = k;
    obec.stan = 0;
    K.push(obec);
    cj[k] = true;
    odl_lot[k] = 0;
    while (!K.empty()) {
        if (K.front().stan == 0) {
            obec = K.front();
            nowa.krok = obec.krok;
            nowa.stan = 1;
            nowa.wczes = obec.miasto;
            for (int a = 0; a < kraw1[obec.miasto].size(); a++) {
                nowa.miasto = kraw1[obec.miasto][a];
                K.push(nowa);
            }
            K.pop();
        }
        if (K.front().stan == 1) {
            obec = K.front();
            nowa.krok = obec.krok + 1;
            nowa.stan = 0;
            for (int a = 0; a < kraw2[obec.miasto].size(); a++)
                if (!cj[kraw2[obec.miasto][a]] &&
                    z_kraw[obec.wczes].find(kraw2[obec.miasto][a]) == z_kraw[obec.wczes].end()) {
                    nowa.miasto = kraw2[obec.miasto][a];
                    cj[nowa.miasto] = true;
                    odl_lot[nowa.miasto] = nowa.krok;
                    K.push(nowa);
                    swap(kraw2[obec.miasto][a], kraw2[obec.miasto].back());
                    kraw2[obec.miasto].pop_back();
                    a--;
                }
            K.pop();
        }
    }
}

int main() {
    int n, m, k, a, b;
    /*
        n - ilość miast
        m - ilość połączeń
        k - nr miasta początkowego
        a - koszt połączenia kolejowego
        b - koszt połączenia lotniczego
    */
    cin >> n >> m >> k >> a >> b;
    int p1, p2;
    for (int i = 0; i < m; i++) {
        cin >> p1 >> p2;
        kraw1[p1].push_back(p2);
        kraw1[p2].push_back(p1);
        kraw2[p1].push_back(p2);
        kraw2[p2].push_back(p1);
        z_kraw[p1].insert(p2);
        z_kraw[p2].insert(p1);
    }

    szukaj_odl_kol(n, k);
    szukaj_odl_lot(n, k);

    for (int i = 0; i < n + 1; i++)
        cennik[i] = cena(odl_kol[i], odl_lot[i], a, b);

    for (int i = 1; i < n + 1; i++)
        cout << cennik[i] << endl;

    return 0;
}