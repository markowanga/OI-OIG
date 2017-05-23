/**
 * II Olimpiada Informatyczna Gimnazjalistów
 * Zadanie: Statki kosmiczne
 * Wynik 100/100
 * Wykonał: Marcin Wątroba
 * http://main.edu.pl/pl/archive/oig/2/sta
 */

#include <iostream>
#include <algorithm>

using namespace std;
#define ll long long

void wys_tab(ll *tab, int il) {
    for (int a = 0; a < il; a++)
        cout << tab[a] << " ";
    cout << endl;
}

int main() {
    int wynik = 0;
    ll b, k, z, pom, max;
    cin >> b >> k >> z;
    int il_b, il_k, il_z;
    cin >> il_b;
    ll *B = new ll[il_b];
    for (int a = 0; a < il_b; a++) {
        cin >> pom;
        B[a] = pom * b;
    }
    cin >> il_k;
    ll *K = new ll[il_k];
    for (int a = 0; a < il_k; a++) {
        cin >> pom;
        K[a] = pom * k;
    }
    cin >> il_z;
    ll *Z = new ll[il_z];
    for (int a = 0; a < il_z; a++) {
        cin >> pom;
        Z[a] = pom * z;
    }
    // sortowanie
    sort(B, B + il_b);
    sort(K, K + il_k);
    sort(Z, Z + il_z);

    max = B[il_b - 1] + K[il_k - 1] + Z[il_z - 1];
    int c;
    for (int a = 0; a < il_b; a++) {
        c = -1;
        for (int b = il_k - 1; b >= 0; b--) {
            while (c + 1 < il_z && (B[a] + K[b] + Z[c + 1]) * 2 <= max) {
                c++;
            }
            wynik += il_z - (c + 1);
        }
    }
    cout << wynik;

    return 0;
}