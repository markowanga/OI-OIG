/**
 * III Olimpiada Informatyczna Gimnazjalistów
 * Zadanie: Szyfr
 * Wynik 100/100
 * Wykonał: Marcin Wątroba
 * http://main.edu.pl/pl/archive/oig/3/szy
 */

#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    char popularny;
    cin >> n >> popularny;
    string W;
    cin >> W;
    int tab[100];
    for (int a = 0; a < 100; a++)
        tab[a] = 0;
    for (int a = 0; a < n; a++)
        tab[(int) W[a]]++;
    int ind_max = 0;
    for (int a = 1; a < 100; a++)
        if (tab[a] > tab[ind_max])
            ind_max = a;
    int roznica = ind_max - (int) popularny;
    for (int a = 0; a < n; a++) {
        W[a] = (int) W[a] - roznica;
        if ((int) W[a] < 65)
            W[a] = (int) W[a] + 26;
        if ((int) W[a] > 90)
            W[a] = (int) W[a] - 26;
    }
    cout << W << endl;

    system("PAUSE");
    return 0;
}