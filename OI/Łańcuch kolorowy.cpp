/**
 * XX Olimpiada Informatyczna
 * Zadanie: Łańcuch kolorowy
 * Wynik 100/100
 * Wykonał: Marcin Wątroba
 * http://main.edu.pl/pl/archive/oi/20/lan
 */

#include <cstdio>

using namespace std;
#define ll long long

int ilosc[1000001];
int wzor[1000001];

int main() {
    int m, n, pom, wynik = 0;
    ll dlugosc_ladnego = 0;
    scanf("%d%d", &m, &n);
    int *lancuch = new int[m + 1], *dlugosci = new int[n]; // potem nie używane

    // wczytanie ladnego frag. - najpierw ilosci kolorow
    for (int a = 0; a < n; a++) {
        scanf("%d", &dlugosci[a]);
        dlugosc_ladnego += dlugosci[a];
    }

    // kolory można później bo można ożec wcześniej że nie potrzeba
    // pobierać jak nie trzeba
    if (dlugosc_ladnego <= m) {
        // potem kolory
        for (int a = 0; a < n; a++) {
            scanf("%d", &pom);
            wzor[pom] = dlugosci[a];
        }

        int do_usuniecia = 1;
        // szukanie miotlą
        for (int a = 1; a <= dlugosc_ladnego; a++) {
            scanf("%d", &lancuch[a]);
            if (ilosc[lancuch[a]] == wzor[lancuch[a]]) {
                n++;
                ilosc[lancuch[a]]++;
            } else {
                ilosc[lancuch[a]]++;
                if (ilosc[lancuch[a]] == wzor[lancuch[a]])
                    n--;
            }
        }
        for (int a = (int) dlugosc_ladnego + 1; a <= m + 1; a++) {
            if (n == 0)
                wynik++;
            if (a <= m) {
                scanf("%d", &lancuch[a]);
                if (ilosc[lancuch[a]] == wzor[lancuch[a]]) {
                    n++;
                    ilosc[lancuch[a]]++;
                } else {
                    ilosc[lancuch[a]]++;
                    if (ilosc[lancuch[a]] == wzor[lancuch[a]])
                        n--;
                }

                if (ilosc[lancuch[do_usuniecia]] == wzor[lancuch[do_usuniecia]]) {
                    n++;
                    ilosc[lancuch[do_usuniecia]]--;
                } else {
                    ilosc[lancuch[do_usuniecia]]--;
                    if (ilosc[lancuch[do_usuniecia]] == wzor[lancuch[do_usuniecia]])
                        n--;
                }
                do_usuniecia++;
            }
        }
    }
    printf("%d", wynik);

    return 0;
}