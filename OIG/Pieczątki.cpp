/**
 * VI Olimpiada Informatyczna Gimnazjalistów
 * Zadanie: Pieczątki
 * Wynik 100/100
 * Wykonał: Marcin Wątroba
 * http://main.edu.pl/pl/archive/oig/6/pie
 */

#include <cstdlib>
#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

class pkt {
public:
    bool cj;
    bool cb;

    pkt() {
        cb = false;
    }
};

void reduk(int zak[4], bool pom[10][10]) {
    bool czy;
    //ZAKRES OD DO£U [0]
    zak[0] = 0;
    czy = false;
    for (int a = 9; a >= 0; a--) {
        for (int b = 0; b < 10; b++) {
            if (pom[a][b]) {
                czy = true;
                break;
            }
        }
        if (czy) {
            zak[0] = a;
            break;
        }
    }
    //ZAKRES OD GORY [1]
    zak[1] = 0;
    czy = false;
    for (int a = 0; a < 10; a++) {
        for (int b = 0; b < 10; b++) {
            if (pom[a][b]) {
                czy = true;
                break;
            }
        }
        if (czy) {
            zak[1] = a;
            break;
        }
    }
    //ZAKRES OD PRAWEJ [2]
    zak[2] = 0;
    czy = false;
    for (int a = 9; a >= 0; a--) {
        for (int b = 0; b < 10; b++) {
            if (pom[b][a]) {
                czy = true;
                break;
            }
        }
        if (czy) {
            zak[2] = a;
            break;
        }
    }
    //ZAKRES OD LEWEJ [3]
    zak[3] = 9;
    czy = false;
    for (int a = 0; a < 10; a++) {
        for (int b = 0; b < 10; b++) {
            if (pom[b][a]) {
                czy = true;
                break;
            }
        }
        if (czy) {
            zak[3] = a;
            break;
        }
    }
    return;
}

bool spr(pkt obraz[100][100], bool piecz[10][10], int a, int b, int w[2]) {
    for (int c = 0; c < w[0]; c++)
        for (int d = 0; d < w[1]; d++)
            if (obraz[a + c][b + d].cj && piecz[c][d])
                return false;
    return true;
}

void przyb(pkt obraz[100][100], bool piecz[10][10], int a, int b, int w[2]) {
    for (int c = 0; c < w[0]; c++)
        for (int d = 0; d < w[1]; d++)
            if (piecz[c][d])
                obraz[a + c][b + d].cb = true;
    return;
}

int main(int argc, char *argv[]) {
    int W, S;
    cin >> W >> S;
    pkt obraz[100][100];
    //ODCZYT OBRAZU
    char znak;
    for (int a = 0; a < W; a++) {
        for (int b = 0; b < S; b++) {
            cin >> znak;
            if (znak == '#')
                obraz[a][b].cj = true;
            else
                obraz[a][b].cj = false;
        }
    }
    int ilp;
    cin >> ilp;
    bool piecz[ilp][10][10];
    int w[ilp][2];
    bool pom[10][10];
    int zak[4];
    for (int a = 0; a < ilp; a++) {
        for (int b = 0; b < 10; b++)
            for (int c = 0; c < 10; c++)
                pom[b][c] = false;
        cin >> w[a][0] >> w[a][1];
        for (int b = 0; b < w[a][0]; b++)
            for (int c = 0; c < w[a][1]; c++) {
                cin >> znak;
                if (znak == '#')
                    pom[b][c] = true;
                else
                    pom[b][c] = false;
            }
        reduk(zak, pom);
        w[a][0] = zak[0] - zak[1] + 1;
        w[a][1] = zak[2] - zak[3] + 1;
        for (int b = 0; b < w[a][0]; b++) {
            for (int c = 0; c < zak[2] - zak[3] + 1; c++) {
                piecz[a][b][c] = pom[zak[1] + b][zak[3] + c];
            }
        }
    }
    //OK
    for (int a = 0; a < W; a++)
        for (int b = 0; b < S; b++)
            for (int c = 0; c < ilp; c++)
                if (a + w[c][0] <= W && b + w[c][1] <= S) {
                    if (spr(obraz, piecz[c], a, b, w[c]))
                        przyb(obraz, piecz[c], a, b, w[c]);
                    //cout<<c<<"ok";
                }
    //SPRAWDZENIE CZY SĄ NIE PRZYBITE POLA
    bool s = false;
    for (int a = 0; a < W; a++)
        for (int b = 0; b < S; b++)
            if (obraz[a][b].cj && !obraz[a][b].cb)
                s = true;
    if (s)cout << "NIE";
    else cout << "TAK";
    return EXIT_SUCCESS;
}