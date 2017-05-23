/**
 * V Olimpiada Informatyczna Gimnazjalistów
 * Zadanie: Wyścig
 * Wynik 100/100
 * Wykonał: Marcin Wątroba
 * http://main.edu.pl/pl/archive/oig/5/wys
 */

#include <iostream>
#include <cstdio>
#include <iomanip>

using namespace std;

struct ss {
    double ogr;
    double dl;
    bool czy_koniec;
    double poczatatek;

    ss() {
        czy_koniec = false;
    }
};

struct gonsienica {
    int znak;
    int odl;
};

double min(double a, double b) {
    if (a < b)
        return a;
    return b;
}

int main() {
    int n, m, d;
    double wynik = 0, czas = 0;
    gonsienica pocz, kon;
    scanf("%d%d%d", &n, &m, &d);
    ss *tab = new ss[n + 1];
    tab[n].poczatatek = d;
    tab[n].czy_koniec = true;

    cin >> tab[0].poczatatek >> tab[0].ogr;
    for (int a = 1; a < n; a++) {
        scanf("%lf%lf", &tab[a].poczatatek, &tab[a].ogr);
        tab[a - 1].dl = tab[a].poczatatek - tab[a - 1].poczatatek;
    }
    tab[n - 1].dl = tab[n].poczatatek - tab[n - 1].poczatatek;

    pocz.znak = 0;
    pocz.odl = 0;
    kon.odl = 0;
    kon.znak = 0;

    while (tab[kon.znak + 1].poczatatek <= m) {
        czas += tab[kon.znak].dl / tab[kon.znak].ogr;
        kon.znak++;
        if (kon.znak == n)
            break;
    }

    if (tab[kon.znak].poczatatek < m) {
        double deficyt = m - tab[kon.znak].poczatatek;
        kon.odl = deficyt;
        czas += deficyt / tab[kon.znak].ogr;
    }

    wynik = czas;
    while (!tab[kon.znak].czy_koniec) {
        double odl_pocz = tab[pocz.znak].dl - pocz.odl;
        double odl_kon = tab[kon.znak].dl - kon.odl;

        if (odl_pocz < odl_kon) {
            czas -= odl_pocz / tab[pocz.znak].ogr;
            czas += odl_pocz / tab[kon.znak].ogr;
            pocz.odl += odl_pocz;
            kon.odl += odl_pocz;
            if (pocz.odl == tab[pocz.znak].dl) {
                pocz.znak++;
                pocz.odl = 0;
            }
            if (kon.odl == tab[kon.znak].dl) {
                kon.znak++;
                kon.odl = 0;
            }
        } else {
            czas -= odl_kon / tab[pocz.znak].ogr;
            czas += odl_kon / tab[kon.znak].ogr;
            pocz.odl += odl_kon;
            kon.odl += odl_kon;
            if (pocz.odl == tab[pocz.znak].dl) {
                pocz.znak++;
                pocz.odl = 0;
            }
            if (kon.odl == tab[kon.znak].dl) {
                kon.znak++;
                kon.odl = 0;
            }
        }
        wynik = min(wynik, czas);
    }
    cout << fixed << setprecision(3) << wynik << endl;

    return 0;
}