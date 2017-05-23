/**
 * I Olimpiada Informatyczna Gimnazjalistów
 * Zadanie: Sortowanie biżuterii
 * Wynik 100/100
 * Wykonał: Marcin Wątroba
 * http://main.edu.pl/pl/archive/oig/1/sor
 */

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

bool porownanie(string A, string B) {
    if (A.size() > B.size())
        return false;
    if (A.size() < B.size())
        return true;
    for (int a = 0; a < (int) A.size(); a++) {
        if ((int) A[a] > (int) B[a])
            return false;
        else if ((int) A[a] < (int) B[a])
            return true;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    string *tab = new string[n];
    for (int a = 0; a < n; a++)
        cin >> tab[a];
    sort(tab, tab + n, porownanie);
    for (int a = 0; a < n; a++)
        cout << tab[a] << endl;

    system("PAUSE");
    return 0;
}