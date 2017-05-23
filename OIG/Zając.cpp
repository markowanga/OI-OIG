/**
 * IV Olimpiada Informatyczna Gimnazjalistów
 * Zadanie: Zając
 * Wynik 100/100
 * Wykonał: Marcin Wątroba
 * http://main.edu.pl/pl/archive/oig/4/zaj
 */

#include <iostream>
#include <cstdio>
#include <utility>
#include <queue>

using namespace std;

struct ss {
    pair<short int, short int> p;
    int nr;
};

bool czy_poz_ok(pair<short int, short int> poz, bool **tab, short int n, short int m) {
    if (poz.first < 0)
        return false;
    if (poz.first >= n)
        return false;
    if (poz.second < 0)
        return false;
    if (poz.second >= m)
        return false;
    if (tab[poz.first][poz.second] == true)
        return true;
    return false;
}

int main() {
    short int n, m;
    char z;
    cin >> n >> m;
    //scanf("%hd%hd", &n, &m);
    bool **tab = new bool *[n];
    pair<short int, short int> poz, nora, pom;
    for (int a = 0; a < n; a++) {
        tab[a] = new bool[m];
        for (short int b = 0; b < m; b++) {
            cin >> z;
            //scanf("%c", &z);
            if (z == 'z') {
                poz = make_pair(a, b);
                tab[a][b] = false;
            } else if (z == 'x')
                tab[a][b] = false;
            else if (z == 'n') {
                nora = make_pair(a, b);
                tab[a][b] = true;
            } else
                tab[a][b] = true;
        }
    }

    queue<ss> K;
    ss P, nastepny;
    P.p = poz;
    P.nr = 0;
    K.push(P);
    bool czy_wynik = false;
    while (K.empty() == false) {
        P = K.front();
        if (P.p == nora) {
            czy_wynik = true;
            cout << P.nr << endl;
            break;
        }
        // kombinacje
        pom = make_pair(P.p.first + 1, P.p.second + 2);
        if (czy_poz_ok(pom, tab, n, m) == true) {
            tab[pom.first][pom.second] = false;
            nastepny.p = pom;
            nastepny.nr = P.nr + 1;
            K.push(nastepny);
        }
        pom = make_pair(P.p.first + 1, P.p.second - 2);
        if (czy_poz_ok(pom, tab, n, m) == true) {
            tab[pom.first][pom.second] = false;
            nastepny.p = pom;
            nastepny.nr = P.nr + 1;
            K.push(nastepny);
        }
        pom = make_pair(P.p.first - 1, P.p.second + 2);
        if (czy_poz_ok(pom, tab, n, m) == true) {
            tab[pom.first][pom.second] = false;
            nastepny.p = pom;
            nastepny.nr = P.nr + 1;
            K.push(nastepny);
        }
        pom = make_pair(P.p.first - 1, P.p.second - 2);
        if (czy_poz_ok(pom, tab, n, m) == true) {
            tab[pom.first][pom.second] = false;
            nastepny.p = pom;
            nastepny.nr = P.nr + 1;
            K.push(nastepny);
        }
        pom = make_pair(P.p.first + 2, P.p.second + 1);
        if (czy_poz_ok(pom, tab, n, m) == true) {
            tab[pom.first][pom.second] = false;
            nastepny.p = pom;
            nastepny.nr = P.nr + 1;
            K.push(nastepny);
        }
        pom = make_pair(P.p.first + 2, P.p.second - 1);
        if (czy_poz_ok(pom, tab, n, m) == true) {
            tab[pom.first][pom.second] = false;
            nastepny.p = pom;
            nastepny.nr = P.nr + 1;
            K.push(nastepny);
        }
        pom = make_pair(P.p.first - 2, P.p.second + 1);
        if (czy_poz_ok(pom, tab, n, m) == true) {
            tab[pom.first][pom.second] = false;
            nastepny.p = pom;
            nastepny.nr = P.nr + 1;
            K.push(nastepny);
        }
        pom = make_pair(P.p.first - 2, P.p.second - 1);
        if (czy_poz_ok(pom, tab, n, m) == true) {
            tab[pom.first][pom.second] = false;
            nastepny.p = pom;
            nastepny.nr = P.nr + 1;
            K.push(nastepny);
        }
        K.pop();
    }
    if (czy_wynik == false)
        cout << "NIE" << endl;

    system("PAUSE");
    return 0;
}