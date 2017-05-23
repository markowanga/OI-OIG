/**
 * VI Olimpiada Informatyczna Gimnazjalistów
 * Zadanie: Skrzaty
 * Wynik 100/100
 * Wykonał: Marcin Wątroba
 * http://main.edu.pl/pl/archive/oig/6/skr
 */

#include <cstdlib>
#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

struct przed {
    int p;
    int k;
};

int wbez(int a) {
    if (a > 0)return a;
    else return -1 * a;
}

bool czy_wsp(int *tab, int dl, vector<przed> prz[1]) {
    int ltab = 0; // licznik tablicy
    int lvec = 0; // licznik vectora
    bool wynik = false;
    int ostwprz = -1;
    for (ltab; ltab < dl; ltab++) {
        //DOBRA FUNKCJA
        while (true) {
            if (lvec == prz[0].size()) {
                lvec--;
                break;
            } else if (tab[ltab] >= prz[0][lvec].p && tab[ltab] <= prz[0][lvec].k)
                break;
            else if (tab[ltab] < prz[0][lvec].p)
                break;
            if (ltab == 0)
                wynik = true;
            else if (-1 * tab[ltab - 1] != prz[0][lvec].k && tab[ltab - 1] < 0)
                wynik = true;
            else if (tab[ltab] > prz[0][lvec].k && tab[ltab - 1] < prz[0][lvec].k && tab[ltab - 1] > 0)
                wynik = true;
            lvec++;
        }
        if (tab[ltab] >= prz[0][lvec].p && tab[ltab] <= prz[0][lvec].k) {
            if (tab[ltab] - 1 >= prz[0][lvec].p && ltab > 0)
                if (tab[ltab] - 1 != tab[ltab - 1] * (-1))
                    wynik = true;
            tab[ltab] *= -1;
        }
    }
    if (wbez(tab[dl - 1]) < prz[0][prz[0].size() - 1].k) {
        wynik = true;
    }
    for (int a = 0; a < dl; a++)
        if (tab[a] < 0)tab[a] = 0;
    return wynik;
}

void nzbior(int *tab, int dl, vector<przed> prz[1], int n) {
    vector<przed> tym;
    int ltab;
    przed pom;
    pom.p = 1;
    for (int ltab = 0; ltab <= dl; ltab++) {
        if (ltab == 0)
            pom.p = 1;
        else
            pom.p = tab[ltab - 1] + 1;
        while (ltab != dl && tab[ltab] == 0)
            ltab++;
        if (ltab != dl)
            pom.k = tab[ltab] - 1;
        else
            pom.k = n;
        if (pom.p <= pom.k) {
            tym.push_back(pom);
        }
    }
    prz[0].assign(tym.begin(), tym.begin() + tym.size());
}

int main(int argc, char *argv[]) {
    int n, m;
    scanf("%d%d", &n, &m);
    int *dl = new int[m];
    int **obs = new int *[m];
    vector<przed> prz[1];
    przed pom = {1, 1};
    prz[0].push_back(pom);
    int i;
    bool wyn = false;
    for (i = 0; i < m; i++) {
        scanf("%d", &dl[i]);
        obs[i] = new int[dl[i]];
        for (int a = 0; a < dl[i]; a++)
            scanf("%d", &obs[i][a]);
        if (czy_wsp(obs[i], dl[i], prz)) {
            nzbior(obs[i], dl[i], prz, n);
        }
        if (prz[0][prz[0].size() - 1].k == n) {
            cout << i;
            wyn = true;
            break;
        }
    }

    if (!wyn)
        cout << m;

    return EXIT_SUCCESS;
}