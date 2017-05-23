/**
 * XXI Olimpiada Informatyczna
 * Zadanie: Hotele
 * Wynik 100/100
 * Wykonał: Marcin Wątroba
 * http://main.edu.pl/pl/archive/oi/21/hot
 */

#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;
#define ll long long

struct ss {
    // w tej strukturze domyślnie mamy
    // ilość liści na końcu (il_lisci)
    // w pol są przechowywane wszytkie POZOSTAŁE polączenia
    set<int> pol;
    int il_lisci;

    ss() {
        il_lisci = 0;
    }
};

ll kombinacje_klasyczne(ll l) {
    if (l < 3)
        return 0;
    return l * (l - 1) * (l - 2) / 6;
}

ll ilosc_kombinacji(vector<int> V) {
    if (V.size() < 3)
        return 0;
    ll w = 0;
    int a, b, c;
    for (a = 0; a < V.size(); a++)
        for (b = a + 1; b < V.size(); b++)
            for (c = b + 1; c < V.size(); c++)
                w += V[a] * V[b] * V[c];
    return w;
}

bool compVec(vector<int> a, vector<int> v) {
    return a.size() < v.size();
}

vector<int> ile_na_odleglosc_z_jednego_wyjscia(int pocz, int n, bool *czy_ak, ss *pol) {
    vector<int> w;
    bool *ak = new bool[n + 1];
    for (int a = 1; a <= n; a++)
        ak[a] = czy_ak[a];
    set<int>::iterator it;
    queue<pair<int, int> > kol;
    kol.push(make_pair(pocz, 0));
    pair<int, int> licznik = make_pair(0, 0), tym_czas;
    while (!kol.empty()) {
        // second - stopień
        // first ilosc
        tym_czas = kol.front();
        kol.pop();
        ak[tym_czas.first] = false;
        //cout << "przerabiam: " << tym_czas.first << endl;
        if (tym_czas.second != licznik.second) {
            w.push_back(licznik.first);
            licznik.first = pol[tym_czas.first].il_lisci + pol[tym_czas.first].pol.size() - 1;
            licznik.second++;
        } else licznik.first += pol[tym_czas.first].il_lisci + pol[tym_czas.first].pol.size() - 1;

        tym_czas.second++;
        for (it = pol[tym_czas.first].pol.begin(); it != pol[tym_czas.first].pol.end(); it++)
            if (ak[*it])
                kol.push(make_pair(*it, tym_czas.second));
    }

    w.push_back(licznik.first);
    return w;
}

ll ile_mozna_poloczen(int pocz, int n, bool *czy_ak, ss *pol) {
    if (pol[pocz].pol.size() + pol[pocz].il_lisci < 3)
        return 0;
    czy_ak[pocz] = false;
    ll wynik = 0;
    wynik += kombinacje_klasyczne(pol[pocz].pol.size() + pol[pocz].il_lisci);
    if (pol[pocz].pol.size() == 0)
        return wynik;
    vector<int> *tab = new vector<int>[pol[pocz].pol.size()], pp;

    set<int>::iterator it;
    int licznik = 0;
    for (it = pol[pocz].pol.begin(); it != pol[pocz].pol.end(); it++, licznik++)
        tab[licznik] = ile_na_odleglosc_z_jednego_wyjscia(*it, n, czy_ak, pol);
    sort(tab, tab + pol[pocz].pol.size(), compVec);
    for (int a = 0; a < tab[pol[pocz].pol.size() - 1].size(); a++) {
        pp.clear();
        for (int i = pol[pocz].pol.size() - 1; i >= 0 && tab[i].size() > a; i--)
            pp.push_back(tab[i][a]);
        wynik += ilosc_kombinacji(pp);
    }
    czy_ak[pocz] = true;
    return wynik;
}

void optymalizacja_poloczen(int n, bool *czy_ak, ss *pol) {
    if (n < 3)
        return;
    int ind;
    queue<int> kolejka;
    if (pol[1].pol.size() > 1)
        kolejka.push(1);
    else kolejka.push(*pol[1].pol.begin());
    set<int>::iterator it;
    while (!kolejka.empty()) {
        ind = kolejka.front();
        kolejka.pop();
        czy_ak[ind] = false;
        if (pol[ind].pol.size() == 1) {
            pol[*pol[ind].pol.begin()].pol.erase(ind);
            pol[*pol[ind].pol.begin()].il_lisci++;
        } else {
            // dodajemy
            for (it = pol[ind].pol.begin(); it != pol[ind].pol.end(); it++)
                if (czy_ak[*it])
                    kolejka.push(*it);
        }
    }

    // wyzerowanie tablicy czy_ak
    for (int a = 1; a <= n; a++)
        czy_ak[a] = true;

    return;
}

int main() {
    ll wynik = 0;
    int n;
    scanf("%d", &n);
    bool *czy_ak = new bool[n + 1];
    for (int a = 1; a <= n; a++)
        czy_ak[a] = true;
    ss *pol = new ss[n + 1];
    // wczytanie poloczen
    int p1, p2;
    for (int a = 0; a < n - 1; a++) {
        scanf("%d%d", &p1, &p2);
        pol[p1].pol.insert(p2);
        pol[p2].pol.insert(p1);
    }

    // usuwanie poloczeń liści i dodanie ich do innego pola
    optymalizacja_poloczen(n, czy_ak, pol);

    for (int a = 1; a <= n; a++)
        wynik += ile_mozna_poloczen(a, n, czy_ak, pol);

    cout << wynik;

    return 0;
}