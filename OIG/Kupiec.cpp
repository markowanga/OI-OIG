/**
 * IV Olimpiada Informatyczna Gimnazjalistów
 * Zadanie: Kupiec
 * Wynik 100/100
 * Wykonał: Marcin Wątroba
 * http://main.edu.pl/pl/archive/oig/4/kup
 */

#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int n;
    //cin >> n;
    scanf("%d", &n);
    int *ceny = new int[n];
    int *przejazd = new int[n - 1];
    for (int a = 0; a < n; a++)
        //cin >> ceny[a];
        scanf("%d", &ceny[a]);
    for (int a = 0; a < n - 1; a++)
        //cin >> przejazd[a];
        scanf("%d", &przejazd[a]);
    int kup_sprzed;
    int sprzed_kup;
    int max_zysk = 0;
    for (int a = 0; a < n - 1; a++) {
        if (a == 0) {
            kup_sprzed = -ceny[a];
            sprzed_kup = ceny[a];
        } else {
            if (kup_sprzed + ceny[a] > max_zysk)
                max_zysk = kup_sprzed + ceny[a];
            if (sprzed_kup - ceny[a] > max_zysk)
                max_zysk = sprzed_kup - ceny[a];
            //cout << "MAX ZYSK: " << max_zysk;

            if (kup_sprzed < -ceny[a])
                kup_sprzed = -ceny[a];
            if (sprzed_kup < ceny[a])
                sprzed_kup = ceny[a];
            //cout << "    k->s: " << kup_sprzed << "   s->k: " << sprzed_kup << endl;
        }
        kup_sprzed -= przejazd[a];
        sprzed_kup -= przejazd[a];
    }
    if (n != 1) {
        if (kup_sprzed + ceny[n - 1] > max_zysk)
            max_zysk = kup_sprzed + ceny[n - 1];
        if (sprzed_kup - ceny[n - 1] > max_zysk)
            max_zysk = sprzed_kup - ceny[n - 1];
    }

    //cout << max_zysk << endl;
    printf("%d\n", max_zysk);

    system("PAUSE");
    return 0;
}