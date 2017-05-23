/**
 * XXII Olimpiada Informatyczna
 * Zadanie: Pieczęć
 * Wynik: 100/100
 * Wykonał: Marcin Wątroba
 * http://main.edu.pl/pl/archive/oi/22/pie
 */

#include <cstdlib>
#include <cstdio>

using namespace std;

class pkt {
public:
    short int w;
    short int k;
};

class wi {
public:
    bool wie[1001];
};

void red(pkt *piecz, int il, short int pocz[], short int kon[]) {
    for (int a = 0; a < il; a++) {
        piecz[a].w -= pocz[0];
        piecz[a].k -= pocz[1];
    }
    kon[0] -= pocz[0] - 1;
    kon[1] -= pocz[1] - 1;
}

bool spr(wi *ob, int il, pkt *piecz, int p1, int p2) {
    for (int a = 0; a < il; a++)
        if (!ob[piecz[a].w + p1].wie[piecz[a].k + p2])
            return false;

    return true;
}

void usu(wi *ob, int il, pkt *piecz, int p1, int p2) {
    for (int a = 0; a < il; a++)
        ob[piecz[a].w + p1].wie[piecz[a].k + p2] = false;

    return;
}

int main(int argc, char *argv[]) {
    int N;
    scanf("%d", &N);
    for (int n = 0; n < N; n++) {
        int W, S, w[2];
        scanf("%d%d%d%d", &W, &S, &w[0], &w[1]);
        wi *ob = new wi[W];

        //WCZYTANIE DANYCH
        char linia[1001];
        int l_pkt = 0;
        for (int a = 0; a < W; a++) {
            scanf("%s", linia);
            //printf("%d\n", a);
            for (int b = 0; b < S; b++) {
                if (linia[b] == 'x') {
                    ob[a].wie[b] = true;
                    l_pkt++;
                } else
                    ob[a].wie[b] = false;
            }
        }

        //WCZYTANIE DOKUMENTU
        int il = 0;
        pkt *piecz = new pkt[1000001];
        short int pocz[2] = {1001, 1001};
        short int kon[2] = {-1, -1};

        //WCZYTANIE PIECZECI
        for (short a = 0; a < w[0]; a++) {
            scanf("%s", linia);
            for (short b = 0; b < w[1]; b++) {
                if (linia[b] == 'x') {
                    piecz[il].w = a;
                    if (a < pocz[0])pocz[0] = a;
                    if (a > kon[0])kon[0] = a;
                    piecz[il].k = b;
                    if (b < pocz[1])pocz[1] = b;
                    if (b > kon[1])kon[1] = b;
                    il++;
                }
            }
        }
        red(piecz, il, pocz, kon);
        if (l_pkt % il == 0);
        for (int a = 0; a + kon[0] <= W; a++) {
            for (int b = 0; b + kon[1] <= S; b++) {
                if (spr(ob, il, piecz, a, b)) {
                    usu(ob, il, piecz, a, b);
                    l_pkt -= il;
                    if (l_pkt == 0)
                        break;
                }
            }
            if (l_pkt == 0)
                break;
        }
        if (l_pkt == 0)
            printf("TAK\n");
        else
            printf("NIE\n");
        delete[] ob;
        delete[] piecz;
    }
    return EXIT_SUCCESS;
}