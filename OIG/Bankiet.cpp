/**
 * I Olimpiada Informatyczna Gimnazjalistów
 * Zadanie: Bankiet
 * Wynik 100/100
 * Wykonał: Marcin Wątroba
 * http://main.edu.pl/pl/archive/oig/1/ban
 */

#include <iostream>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n;
    int *tab = new int[n + 1];
    set<int> Z;
    set<int>::iterator it;
    for (int a = 1; a < n + 1; a++) {
        cin >> tab[a];
        Z.insert(a);
    }

    int w = 1;
    int nas = 0;
    while (!Z.empty()) {
        if (nas == 0) {
            it = Z.begin();
            nas = tab[*it];
            Z.erase(it);
        } else {
            it = Z.find(nas);
            if (it == Z.end()) {
                w++;
                nas = 0;
            } else {
                nas = tab[*it];
                Z.erase(it);
            }
        }
    }
    cout << w << endl;

    //system("PAUSE");
    return 0;
}