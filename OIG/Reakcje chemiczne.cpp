/**
 * II Olimpiada Informatyczna Gimnazjalistów
 * Zadanie: Reakcje chemiczne
 * Wynik 100/100
 * Wykonał: Marcin Wątroba
 * http://main.edu.pl/pl/archive/oig/2/rea
 */

#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <set>

using namespace std;

struct reak {
    int skladnik;
    vector<int> produkt;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k, r;
    queue<int> K;
    int pom, g, ind, W = 0;
    cin >> n >> k >> r;

    // tablica zawierająca czy pierwiastek jest dostępny
    bool *pier = new bool[n + 1];
    for (int a = 1; a < n + 1; a++)
        pier[a] = false;

    // vector ze wszystkimi reakcjami
    vector<reak> tab;

    vector<int> *powiazania = new vector<int>[n + 1];
    vector<int>::iterator it;

    // pierwiastki dostepne od poczatku - dodanie do kolejki
    // i zaznaczenie w tablicy pier
    for (int a = 0; a < k; a++) {
        cin >> pom;
        pier[pom] = true;
        K.push(pom);
    }

    // wczytanie równań reakcji
    for (int a = 0; a < r; a++) {
        reak R;
        cin >> g;
        R.skladnik = g;
        for (int b = 0; b < g; b++) {
            cin >> pom;
            powiazania[pom].push_back(a);
        }
        cin >> g;
        for (int b = 0; b < g; b++) {
            cin >> pom;
            R.produkt.push_back(pom);
        }
        //wys_reak(R);
        tab.push_back(R);
    }
    //cout << "ok";
    while (!K.empty()) {
        g = K.front();
        //cout << "Sprawdzam: " << g << endl;
        for (int a = 0; a < powiazania[g].size(); a++) {
            ind = powiazania[g][a];
            tab[ind].skladnik--;
            if (tab[ind].skladnik == 0) {
                for (int b = 0; b < tab[ind].produkt.size(); b++)
                    if (!pier[tab[ind].produkt[b]]) {
                        pier[tab[ind].produkt[b]] = true;
                        K.push(tab[ind].produkt[b]);
                        W++;
                    }
            }
        }
        //cout << "------------" << endl;
        K.pop();
    }
    cout << W;

    system("PAUSE");
    return 0;
}
