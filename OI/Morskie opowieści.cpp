/**
 * XX Olimpiada Informatyczna
 * Zadanie: Morskie opowieści
 * Wynik: 100/100
 * Wykonał: Marcin Wątroba
 * http://main.edu.pl/pl/archive/oi/20/mor
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct odp {
    short int p;
    short int n;

    // czy ma połączenie z innymi liniami
    odp() {
        p = -1;
        n = -1;
    }
};

struct kol {
    int nr;
    bool parz;
    short int krok;
};

vector<short int> pol[5001];
// tu zapisuję wszystkie połączenia
odp wyniki[5001][5001];
bool cb[5001][2];

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    /*
        n - liczba miast;
        m - liczba połączeń
        k - liczba opowieści
    */
    // dodanie ścieżek
    short int p1, p2;
    for (int a = 0; a < m; a++) {
        cin >> p1 >> p2;
        pol[p1].push_back(p2);
        pol[p2].push_back(p1);
    }

    // obliczenie całkowietej ilosci połączeń parzystych i nieparzystych w relacji każdy z każdym
    for (int a = 1; a < n + 1; a++) {
        for (int b = 1; b < n + 1; b++) {
            cb[b][0] = false;
            cb[b][1] = false;
        }
        queue<kol> K;
        int nr;
        kol pom, ob;
        pom.krok = 0;
        pom.parz = true;
        pom.nr = a;
        wyniki[a][a].p = 0;
        if (pol[a].size() == 0)
            wyniki[a][a].p = -2;
        cb[a][0] = true;
        K.push(pom);
        while (!K.empty()) {
            if (K.front().parz) {
                pom.parz = false;
                pom.krok = K.front().krok + 1;
                nr = K.front().nr;
                for (int i = 0; i < pol[nr].size(); i++)
                    if (!cb[pol[nr][i]][1]) {
                        cb[pol[nr][i]][1] = true;
                        pom.nr = pol[nr][i];
                        wyniki[a][pom.nr].n = pom.krok;
                        K.push(pom);
                    }
            } else {
                pom.parz = true;
                pom.krok = K.front().krok + 1;
                nr = K.front().nr;
                for (int i = 0; i < pol[nr].size(); i++)
                    if (!cb[pol[nr][i]][0]) {
                        cb[pol[nr][i]][0] = true;
                        pom.nr = pol[nr][i];
                        wyniki[a][pom.nr].p = pom.krok;
                        K.push(pom);
                    }
            }
            K.pop();
        }
    }

    // wczytanie odpowiedzi i odpowiedzenie na nie
    int pocz, kon, d;
    for (int a = 0; a < k; a++) {
        cin >> pocz >> kon >> d;
        if (d % 2 == 1) {
            if (wyniki[pocz][kon].n == -1)
                cout << "NIE" << endl;
            else if (wyniki[pocz][kon].n <= d)
                cout << "TAK" << endl;
            else cout << "NIE" << endl;
        } else {
            if (wyniki[pocz][kon].p == -2) {
                if (d == 0)
                    cout << "TAK" << endl;
                else cout << "NIE" << endl;
            } else if (wyniki[pocz][kon].p == -1)
                cout << "NIE" << endl;
            else if (wyniki[pocz][kon].p <= d)
                cout << "TAK" << endl;
            else cout << "NIE" << endl;
        }
    }

    return 0;
}