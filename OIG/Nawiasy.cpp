/**
 * V Olimpiada Informatyczna Gimnazjalistów
 * Zadanie: Nawiasy
 * Wynik 100/100
 * Wykonał: Marcin Wątroba
 * http://main.edu.pl/pl/archive/oig/5/naw
 */

#include <iostream>
#include <vector>

using namespace std;

#define ll long long

int main() {
    vector<ll> ilosc;
    int n;
    cin >> n;
    char *wyrazenie = new char[n];
    ll licznik = 0;
    int ind = 0;
    int st = 0;
    cin >> wyrazenie;

    while (ind != n) {
        if (wyrazenie[ind] == '(') {
            if (ilosc.size() == st)
                ilosc.push_back(0);
            st++;
        } else {
            st--;
            if (st >= 0) {
                ilosc[st]++;
                licznik += ilosc[st];
                if (ilosc.size() != st + 1)
                    ilosc[st + 1] = 0;
            } else {
                st = 0;
                if (!ilosc.empty())
                    ilosc[0] = 0;
            }
        }
        ind++;
    }
    cout << licznik << endl;

    return 0;
}