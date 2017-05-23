/**
 * II Olimpiada Informatyczna Gimnazjalistów
 * Zadanie: Hurtownia
 * Wynik 100/100
 * Wykonał: Marcin Wątroba
 * http://main.edu.pl/pl/archive/oig/2/hur
 */

#include <iostream>

using namespace std;

int main() {
    char z;
    int il;
    char r;
    int tab[26];
    for (int a = 0; a < 26; a++)
        tab[a] = -1;
    int N;
    cin >> N;
    for (int a = 0; a < N; a++) {
        cin >> r >> z >> il;
        if (tab[(int) r - 65] == -1)
            tab[(int) r - 65] = 0;
        if (z == '-')
            tab[(int) r - 65] -= il;
        else
            tab[(int) r - 65] += il;
    }

    for (int a = 0; a < 26; a++)
        if (tab[a] != -1)
            cout << (char) (a + 65) << " " << tab[a] << endl;

    system("PAUSE");
    return 0;
}
// 65 - 90