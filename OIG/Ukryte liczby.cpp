/**
 * IV Olimpiada Informatyczna Gimnazjalistów
 * Zadanie: Ukryte liczby
 * Wynik 100/100
 * Wykonał: Marcin Wątroba
 * http://main.edu.pl/pl/archive/oig/4/ukr
 */

#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    int n;
    long long suma = 0, l = 0;
    char z;
    cin >> n;
    for (int a = 0; a < n; a++) {
        cin >> z;
        if ((int) z >= 48 && (int) z <= 57) {
            l *= 10;
            l += (int) z - 48;
        } else {
            //cout << l << endl;
            suma += l;
            l = 0;
        }
    }
    suma += l;
    cout << suma << endl;

    system("PAUSE");
    return 0;
}