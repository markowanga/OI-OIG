/**
 * V Olimpiada Informatyczna Gimnazjalistów
 * Zadanie: Skracalne liczby pierwsze
 * Wynik 100/100
 * Wykonał: Marcin Wątroba
 * http://main.edu.pl/pl/archive/oig/5/skr
 */

#include <cstdlib>
#include <iostream>
#include <ctime>
#include <math.h>

using namespace std;

int ost_el(long long tab[]) {
    int w = 0;
    while (tab[w] != 0)
        w++;
    w--;
    return w;
}

bool cp(long long l) {
    for (int a = 2; a * a <= l; a++)
        if (l % a == 0) return false;
    return true;
}

void sort(long long tab[], int ost) {
    cout << "ost=" << ost << endl;
    for (int a = 0; a < ost; a++)
        for (int b = 0; b < ost - a; b++)
            if (tab[b] > tab[b + 1]) {
                cout << tab[b] << " " << tab[b + 1] << endl;
                long long p = tab[b];
                tab[b] = tab[b + 1];
                tab[b + 1] = p;
                cout << tab[b] << " " << tab[b + 1] << endl;
            }
    return;
}

int main(int argc, char **argv) {
    long long tab[10000];
    long long wynik[10000];
    for (int a = 0; a < 10000; a++)
        tab[a] = 0;
    for (int a = 0; a < 10000; a++)
        wynik[a] = 0;
    tab[0] = 2;
    tab[1] = 3;
    tab[2] = 5;
    tab[3] = 7;
    int o = ost_el(tab);
    while (o != -1) {
        if (cp(tab[o]) == true) {
            wynik[ost_el(wynik) + 1] = tab[o];
            long long p = tab[o];
            p *= 10;
            for (int a = 0; a < 10; a++) {
                tab[o] = p + a;
                o++;
            }
        } else tab[o] = 0;
        o = ost_el(tab);
    }
    long long a, b;
    cin >> a >> b;
    int w = 0;
    for (int c = 0; c <= ost_el(wynik); c++)
        if (wynik[c] >= a && wynik[c] <= b)
            w++;
    cout << w << endl;

    return EXIT_SUCCESS;
}