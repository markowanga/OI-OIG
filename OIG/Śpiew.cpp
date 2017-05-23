/**
 * VI Olimpiada Informatyczna Gimnazjalistów
 * Zadanie: Śpiew
 * Wynik 100/100
 * Wykonał: Marcin Wątroba
 * http://main.edu.pl/pl/archive/oig/6/spi
 */

#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    int n;
    cin >> n;
    char tab[n];
    cin >> tab;
    int w = 0;
    int l;
    for (int a = 0; a < n; a++) {
        l = 0;
        if (tab[a] == 'Z') {
            for (a; a < n && tab[a] == 'Z'; a++)
                l++;
            w += l / 3;
            if (l % 3 != 0)w++;
        }
    }
    cout << w;

    return EXIT_SUCCESS;
}