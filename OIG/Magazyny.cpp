/**
 * II Olimpiada Informatyczna Gimnazjalistów
 * Zadanie: Magazyny
 * Wynik 100/100
 * Wykonał: Marcin Wątroba
 * http://main.edu.pl/pl/archive/oig/2/mag
 */

#include <iostream>
#include <set>
#include <queue>
#include <stack>

using namespace std;

struct sm {
    int nadrzedne;
    long long ilosc;
    vector<int> zb;

    sm() {
        nadrzedne = 0;
    }
};

long long w_bez(long long a) {
    if (a < 0)
        return -1 * a;
    return a;
}

int main() {
    // inicjalizacja danych
    int n;
    long long suma_towaru = 0, ilosc_srednia;
    cin >> n;
    sm *tab = new sm[n + 1];

    // wczytanie ilosci towaru i policzenie sredniej
    for (int a = 1; a <= n; a++) {
        cin >> tab[a].ilosc;
        suma_towaru += tab[a].ilosc;
    }
    ilosc_srednia = suma_towaru / n;

    // wczytanie poloczeń
    int p1, p2;
    for (int a = 0; a < n - 1; a++) {
        cin >> p1 >> p2;
        tab[p1].zb.push_back(p2);
        tab[p2].zb.push_back(p1);
    }

    // ustalenie nadrzednych poloczen
    tab[1].nadrzedne = 0;
    queue<int> kolejka;
    stack<int> stos;
    kolejka.push(1);
    stos.push(1);
    int ind;
    while (!kolejka.empty()) {
        ind = kolejka.front();
        kolejka.pop();
        for (int a = 0; a < tab[ind].zb.size(); a++)
            if (tab[ind].nadrzedne != tab[ind].zb[a]) {
                tab[tab[ind].zb[a]].nadrzedne = ind;
                kolejka.push(tab[ind].zb[a]);
                stos.push(tab[ind].zb[a]);
            }
        tab[ind].zb.clear();
    }

    long long cena_transportu = 0;
    while (!stos.empty()) {
        ind = stos.top();
        stos.pop();
        tab[tab[ind].nadrzedne].ilosc += tab[ind].ilosc - ilosc_srednia;
        cena_transportu += w_bez(tab[ind].ilosc - ilosc_srednia);
        tab[ind].ilosc = ilosc_srednia;
    }
    cout << cena_transportu << endl;


    system("PAUSE");
    return 0;
}