/**
 * XX Olimpiada Informatyczna
 * Zadanie: Łuk triumfalny
 * Wynik 100/100
 * Wykonał: Marcin Wątroba
 * http://main.edu.pl/pl/archive/oi/20/luk
 */

#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <queue>

using namespace std;

struct ss {
    set<int> zb_pol;
    int ilosc;
};

int min(int a, int b) {
    if (a > b)
        return b;
    return a;
}

int max(int a, int b) {
    if (a < b)
        return b;
    return a;
}

void oblicz_dla_rob(stack<int> stos, ss *tab, int k) {
    int ind;
    while (!stos.empty()) {
        ind = stos.top();
        stos.pop();
        tab[ind].ilosc = 0;
        for (set<int>::iterator it = tab[ind].zb_pol.begin(); it != tab[ind].zb_pol.end(); it++)
            tab[ind].ilosc += tab[*it].ilosc + 1;
        tab[ind].ilosc = max(0, tab[ind].ilosc - k);
    }
}

int main() {
    // wczytanie danych
    int n;
    cin >> n;
    bool *czy_byly = new bool[n + 1];
    ss *tab = new ss[n + 1];
    for (int a = 1; a <= n; a++)
        czy_byly[a] = false;

    int p1, p2;
    for (int a = 0; a < n - 1; a++) {
        cin >> p1 >> p2;
        tab[p1].zb_pol.insert(p2);
        tab[p2].zb_pol.insert(p1);
    }

    // utworzenie stosu prowadzącego od liści do korzenia
    queue<int> kolejka;
    kolejka.push(1);
    stack<int> stos;
    int ind, max_rozg = 0;
    while (!kolejka.empty()) {
        ind = kolejka.front();
        kolejka.pop();
        stos.push(ind);
        max_rozg = max(max_rozg, tab[ind].zb_pol.size());
        for (set<int>::iterator it = tab[ind].zb_pol.begin(); it != tab[ind].zb_pol.end(); it++) {
            kolejka.push(*it);
            tab[*it].zb_pol.erase(ind);
        }
    }

    // szukanie binarne wyniku
    // ustalenie zakresu
    int pocz = tab[1].zb_pol.size();
    int kon = max_rozg;
    while (pocz < kon) {
        int sr = (pocz + kon) / 2;
        oblicz_dla_rob(stos, tab, sr);
        if (tab[1].ilosc == 0)
            kon = sr;
        else pocz = sr + 1;
    }
    cout << pocz;

    return 0;
}