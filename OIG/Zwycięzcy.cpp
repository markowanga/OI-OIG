/**
 * I Olimpiada Informatyczna Gimnazjalistów
 * Zadanie: Zwycięzcy
 * Wynik 100/100
 * Wykonał: Marcin Wątroba
 * http://main.edu.pl/pl/archive/oig/1/zwy
 */

#include <iostream>
#include <algorithm>

using namespace std;

struct ss {
    char id;
    int pkt;
};

bool por(ss A, ss B) {
    if (A.pkt > B.pkt)
        return true;
    else if (A.pkt < B.pkt)
        return false;
    else if (A.id > B.id)
        return false;
    return true;
}

int main() {
    int n;
    cin >> n;
    ss *tab = new ss[n];
    for (int a = 0; a < n; a++) {
        cin >> tab[a].pkt;
        tab[a].id = (char) (a + 65);
    }

    sort(tab, tab + n, por);

    int pp = tab[0].pkt;
    for (int a = 0; a < n; a++) {
        if (tab[a].pkt == pp)
            cout << tab[a].id;
        else break;
    }

    //system("PAUSE");
    return 0;
}