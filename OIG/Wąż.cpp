/**
 * IV Olimpiada Informatyczna Gimnazjalistów
 * Zadanie: Wąż
 * Wynik 100/100
 * Wykonał: Marcin Wątroba
 * http://main.edu.pl/pl/archive/oig/4/waz
 */

#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int main() {
    char kier;
    char **tab = new char *[1001];
    bool **W = new bool *[1001];
    for (int a = 0; a < 1001; a++) {
        tab[a] = new char[1001];
        W[a] = new bool[1001];
    }
    queue<pair<int, int> > K;
    pair<int, int> pocz;
    int n, m, r;
    cin >> n >> m >> r;
    cin >> kier;
    for (int a = 0; a < n; a++) {
        cin >> tab[a];
        for (int b = 0; b < m; b++) {
            if (tab[a][b] == 'W') {
                pocz = make_pair(a, b);
                tab[a][b] = '.';
                K.push(pocz);
                W[a][b] = true;
            } else
                W[a][b] = false;
        }
    }
    char pos;
    bool czy_ok = true;
    for (int a = 0; a < r; a++) {
        //cout << "NASTEPNY RUCH" << endl;
        cin >> pos;
        //cout << pocz.first << " " << pocz.second << endl;

        if (pos == 'P') {
            if (kier == 'N') kier = 'E';
            else if (kier == 'E') kier = 'S';
            else if (kier == 'S') kier = 'W';
            else if (kier == 'W') kier = 'N';
        }
        if (pos == 'L') {
            if (kier == 'N') kier = 'W';
            else if (kier == 'E') kier = 'N';
            else if (kier == 'S') kier = 'E';
            else if (kier == 'W') kier = 'S';
        }
        //cout << pos << kier << endl;

        if (kier == 'N') pocz.first--;
        if (kier == 'S') pocz.first++;
        if (kier == 'E') pocz.second++;
        if (kier == 'W') pocz.second--;
        //cout << pocz.first << " " << pocz.second << endl;
        K.push(pocz);
        // sprawdzenie czy nie wykracza poza plansze
        if (pocz.first == -1 || pocz.first == n || pocz.second == -1 || pocz.second == m) {
            //cout << "wykracza poza" << endl;
            cout << a + 1 << endl;
            czy_ok = false;
            break;
        }

        // sprawdzenie czy wšż nie się ukšsza
        if (W[pocz.first][pocz.second] == true) {
            //cout << "gryzie sie" << endl;
            cout << a + 1 << endl;
            czy_ok = false;
            break;
        }

        W[pocz.first][pocz.second] = true;
        // sprawdzenie czy wšż je
        if (tab[pocz.first][pocz.second] == 'J')
            tab[pocz.first][pocz.second] = '.';
        else {
            W[K.front().first][K.front().second] = false;
            K.pop();
        }
    }
    if (czy_ok == true)
        cout << "OK" << endl;


    system("PAUSE");
    return 0;
}