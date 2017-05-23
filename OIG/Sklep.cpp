/**
 * I Olimpiada Informatyczna Gimnazjalistów
 * Zadanie: Sklep
 * Wynik 100/100
 * Wykonał: Marcin Wątroba
 * http://main.edu.pl/pl/archive/oig/1/skl
 */

#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

struct prod {
    int id;
    int kol;
    int il;
};

bool f_por1(prod A, prod B) {
    if (A.id < B.id)
        return true;
    if (A.id > B.id)
        return false;
    if (A.kol < B.kol)
        return true;
    if (A.kol > B.kol)
        return false;
}

bool f_por2(prod A, prod B) {
    if (A.kol < B.kol)
        return true;
    if (A.kol > B.kol)
        return false;
}

int main() {
    int N;
    scanf("%d", &N);

    prod *tab = new prod[N];
    vector<prod> zes;
    int nr = 1;
    for (int a = 0; a < N; a++) {
        scanf("%d%d", &tab[a].id, &tab[a].il);
        tab[a].kol = a;
    }
    sort(tab, tab + N, f_por1);
    zes.push_back(tab[0]);
    for (int a = 1; a < N; a++) {
        if (zes[zes.size() - 1].id == tab[a].id)
            zes[zes.size() - 1].il += tab[a].il;
        else
            zes.push_back(tab[a]);
    }
    sort(zes.begin(), zes.end(), f_por2);

    printf("%d\n", zes.size());
    for (int a = 0; a < zes.size(); a++)
        printf("%d %d\n", zes[a].id, zes[a].il);

    system("PAUSE");
    return 0;
}