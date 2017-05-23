/**
 * I Olimpiada Informatyczna Gimnazjalistów
 * Zadanie: Zliczacz liter
 * Wynik 100/100
 * Wykonał: Marcin Wątroba
 * http://main.edu.pl/pl/archive/oig/1/zli
 */

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    string *linie = new string[n];
    cin.ignore();
    for (int a = 0; a < n; a++)
        getline(cin, linie[a]);
    int tab[128];
    for (int a = 0; a < 128; a++)
        tab[a] = 0;
    for (int a = 0; a < n; a++)
        for (int b = 0; b < linie[a].size(); b++)
            tab[(int) linie[a][b]]++;
    for (int a = 97; a <= 122; a++)
        if (tab[a] != 0)
            cout << (char) a << " " << tab[a] << endl;
    for (int a = 60; a <= 90; a++)
        if (tab[a] != 0)
            cout << (char) a << " " << tab[a] << endl;

    system("PAUSE");
    return 0;
}
// 97->122
// 65->90