/**
 * VI Olimpiada Informatyczna Gimnazjalistów
 * Zadanie: Gumka do mazania
 * Wynik 100/100
 * Wykonał: Marcin Wątroba
 * http://main.edu.pl/pl/archive/oig/6/gum
 */

#include <cstdlib>
#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

void ctab(char *tab) {
    for (int a = 0; tab[a] != '\0'; a++)tab[a] = '\0';
    return;
}

int dl(char *tab) {
    int w = 0;
    while (tab[w] != '\0')
        w++;
    return w;
}

int main(int argc, char *argv[]) {
    int n;
    scanf("%d", &n);
    //char **tab = new char *[n];
    vector<char> tab[n];
    char *w = new char[10000001];
    int *d = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> w;
        d[i] = dl(w);
        tab[i].reserve(d[i]);
        for (int a = 0; a < d[i]; a++)
            tab[i][a] = w[a];
        ctab(w);
    }
    //cout<<"DANE WCZYTANE"<<endl;
    int *pocz = new int[n];
    for (int a = 0; a < n; a++)
        pocz[a] = -1;
    int *kon = new int[n];
    ctab(w);
    int licznik = 0;
    //cout<<"POCZATEK PETLI"<<endl;
    for (int a = 25; a >= 0; a--) {
        //cout<<"a "<<a<<endl;
        bool cj = true;
        while (true) {
            for (int b = 0; b < n; b++) {
                //cout<<"b "<<b<<endl;
                if (pocz[b] + 1 == d[b]) {
                    //cout<<"za krutkie";
                    cj = false;
                    break;
                }
                for (int c = pocz[b] + 1; c < d[b]; c++) {
                    //cout<<tab[b]<<endl;
                    //cout<<"c "<<c<<tab[b][c]<<endl;

                    if ((int) tab[b][c] == a + 97) {
                        //cout<<"ok";
                        kon[b] = c;
                        break;
                    } else if (c == d[b] - 1) {
                        cj = false;
                        break;
                    }
                }
                if (!cj) break;
            }
            if (!cj) break;
            w[licznik] = char(a + 97);
            licznik++;
            //cout<<"WWW"<<w<<endl;
            for (int b = 0; b < n; b++)
                pocz[b] = kon[b];
        }
    }
    char tt[] = {"bitek"};
    bool czyd = true;
    bool bit = true;
    for (int a = 0; a < 5; a++) {
        if ((int) tt[a] > (int) w[a]) {
            bit = true;
            czyd = false;
            break;
        }
        if ((int) tt[a] < (int) w[a]) {
            bit = false;
            czyd = false;
            break;
        }
    }
    if (czyd && w[5] != '\0')bit = false;
    if (bit)cout << "bitek" << endl;
    else
        for (int a = 0; w[a] != '\0'; a++)cout << w[a];

    return EXIT_SUCCESS;
}