/**
 * IV Olimpiada Informatyczna Gimnazjalistów
 * Zadanie: Chochlik
 * Wynik 100/100
 * Wykonał: Marcin Wątroba
 * http://main.edu.pl/pl/archive/oig/4/cho
 */

#include <iostream>
#include <vector>
#include <set>
#include <utility>
#include <queue>

using namespace std;

struct ss {
    int kier;
    vector<pair<int, char> > pol;

    ss() { kier = 0; }
};

int main() {
    int n, k, p, p1, p2;
    char t;
    cin >> n;
    ss ob;
    for (int i = 0; i < n; i++) {
        cin >> k >> p;
        ss *tab = new ss[k + 1];
        for (int a = 0; a < p; a++) {
            cin >> p1 >> p2 >> t;
            tab[p1].pol.push_back(make_pair(p2, t));
            tab[p2].pol.push_back(make_pair(p1, t));
        }
        bool wynik = true;
        bool czy_wynik = false;
        queue<int> kolejka;
        for (int j = 1; j < k + 1; j++)
            if (tab[j].kier == 0) {
                kolejka.push(j);
                tab[j].kier = 1;
                while (!kolejka.empty()) {
                    int ind = kolejka.front();
                    for (int a = 0; a < tab[ind].pol.size(); a++) {
                        if (tab[ind].pol[a].second == 'A') {
                            if (tab[tab[ind].pol[a].first].kier == 0) {
                                tab[tab[ind].pol[a].first].kier = tab[ind].kier;
                                kolejka.push(tab[ind].pol[a].first);
                            } else if (tab[tab[ind].pol[a].first].kier * tab[ind].kier == -1) {
                                wynik = false;
                                czy_wynik = true;
                                break;
                            }
                        } else {
                            if (tab[tab[ind].pol[a].first].kier == 0) {
                                tab[tab[ind].pol[a].first].kier = -tab[ind].kier;
                                kolejka.push(tab[ind].pol[a].first);
                            } else if (tab[tab[ind].pol[a].first].kier * tab[ind].kier == 1) {
                                wynik = false;
                                czy_wynik = true;
                                break;
                            }
                        }
                    }
                    if (czy_wynik)
                        break;
                    kolejka.pop();
                }
                if (czy_wynik)
                    break;
            }
        if (wynik)
            cout << "TAK" << endl;
        else cout << "NIE" << endl;
    }

    system("PAUSE");
    return 0;
}