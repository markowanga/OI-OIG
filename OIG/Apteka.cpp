/**
 * VI Olimpiada Informatyczna Gimnazjalistów
 * Zadanie: Apteka
 * Wynik 100/100
 * Wykonał: Marcin Wątroba
 * http://main.edu.pl/pl/archive/oig/6/apt
 */

#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
    int n;
    cin >> n;
    long long *tab = new long long[n];
    vector<long long> t;
    for (int a = 0; a < n; a++) cin >> tab[a];
    t.push_back(n - 1);
    int p = 0;
    if (n > 1)
        for (int a = n - 2; a >= 0; a--) {
            if (tab[a] < tab[t[p]]) {
                p++;
                t.push_back(a);
            }
        }
    int l = -1;
    long long s = 0;
    p;
    for (p; p >= 0; p--) {
        s = s + tab[t[p]] * (t[p] - l);
        l = t[p];
    }
    cout << s;

    return EXIT_SUCCESS;
}