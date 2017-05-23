/**
 * III Olimpiada Informatyczna Gimnazjalistów
 * Zadanie: Klasy
 * Wynik 100/100
 * Wykonał: Marcin Wątroba
 * http://main.edu.pl/pl/archive/oig/3/kla
 */

#include <iostream>
#include <string>

using namespace std;

int nr = 1, n, w_x, w_y;
int x_1, x_2, y_1, y_2;
string kier, skret;

string nowy_kierunek() {
    if ((kier == "POLNOC" && skret == "PRAWO")
        || (kier == "POLUDNIE" && skret == "LEWO"))
        return "WSCHOD";

    if ((kier == "POLNOC" && skret == "LEWO")
        || (kier == "POLUDNIE" && skret == "PRAWO"))
        return "ZACHOD";

    if ((kier == "ZACHOD" && skret == "PRAWO")
        || (kier == "WSCHOD" && skret == "LEWO"))
        return "POLNOC";

    return "POLUDNIE";
}

bool spr_pole(bool **B) {
    if (w_x == -1)
        return false;
    if (w_x == n)
        return false;
    if (w_y == -1)
        return false;
    if (w_y == n)
        return false;
    if (B[w_x][w_y] == false)
        return true;
    return false;
}

bool uzu_kierunek(int **W, bool **B) {
    bool wynik = false;
    if (kier == "POLNOC") // zwiekszamy y
        while (true) {
            w_y++;
            if (spr_pole(B) == false) {
                w_y--;
                return wynik;
            }
            nr++;
            wynik = true;
            B[w_x][w_y] = true;
            if (w_x >= x_1 && w_x <= x_2 && w_y >= y_1 && w_y <= y_2)
                W[w_x - x_1][w_y - y_1] = nr;
        }

    if (kier == "POLUDNIE") // zmniejszamy y
        while (true) {
            w_y--;
            if (spr_pole(B) == false) {
                w_y++;
                return wynik;
            }
            nr++;
            wynik = true;
            B[w_x][w_y] = true;
            if (w_x >= x_1 && w_x <= x_2 && w_y >= y_1 && w_y <= y_2)
                W[w_x - x_1][w_y - y_1] = nr;
        }

    if (kier == "WSCHOD") // zwiekszamy x
        while (true) {
            w_x++;
            if (spr_pole(B) == false) {
                w_x--;
                return wynik;
            }
            nr++;
            wynik = true;
            B[w_x][w_y] = true;
            if (w_x >= x_1 && w_x <= x_2 && w_y >= y_1 && w_y <= y_2)
                W[w_x - x_1][w_y - y_1] = nr;
        }

    if (kier == "ZACHOD") // zmniejszamy x
        while (true) {
            w_x--;
            if (spr_pole(B) == false) {
                w_x++;
                return wynik;
            }
            nr++;
            wynik = true;
            B[w_x][w_y] = true;
            if (w_x >= x_1 && w_x <= x_2 && w_y >= y_1 && w_y <= y_2)
                W[w_x - x_1][w_y - y_1] = nr;
        }
}

void uzu(int **W, bool **B) {
    // ustawienie punktu poczštkowego
    if ((kier == "POLNOC" && skret == "PRAWO")
        || (kier == "WSCHOD" && skret == "LEWO")) {
        w_x = 0;
        w_y = 0;

    }
    if ((kier == "POLUDNIE" && skret == "LEWO")
        || (kier == "WSCHOD" && skret == "PRAWO")) {
        w_x = 0;
        w_y = n - 1;
    }
    if ((kier == "POLUDNIE" && skret == "PRAWO")
        || (kier == "ZACHOD" && skret == "LEWO")) {
        w_x = n - 1;
        w_y = n - 1;
    }
    if ((kier == "POLNOC" && skret == "LEWO")
        || (kier == "ZACHOD" && skret == "PRAWO")) {
        w_x = n - 1;
        w_y = 0;
    }

    // zaktualizowanie danych w pkt poczatkowym
    B[w_x][w_y] = true;
    if (w_x >= x_1 && w_x <= x_2 && w_y >= y_1 && w_y <= y_2)
        W[w_x - x_1][w_y - y_1] = nr;

    while (uzu_kierunek(W, B) == true)
        kier = nowy_kierunek();

    return;
}

int main() {
    // wczytanie danych
    cin >> n;
    cin >> kier >> skret;
    cin >> x_1 >> x_2 >> y_1 >> y_2;
    x_1--;
    x_2--;
    y_1--;
    y_2--;

    // utworzenie macierzy logicznej
    bool **B = new bool *[n];
    for (int a = 0; a < n; a++)
        B[a] = new bool[n];
    for (int a = 0; a < n; a++)
        for (int b = 0; b < n; b++)
            B[a][b] = false;

    // utworzenie macierzy z wynikiem
    int d_x = x_2 - x_1 + 1, d_y = y_2 - y_1 + 1;
    int **W = new int *[d_x];
    for (int a = 0; a < d_x; a++)
        W[a] = new int[d_y];
    for (int a = 0; a < d_x; a++)
        for (int b = 0; b < d_y; b++)
            W[a][b] = 0;

    // uzupełnienie tablic
    uzu(W, B);

    // wyswietlenie wyniku
    for (int Y = d_y - 1; Y >= 0; Y--) {
        for (int X = 0; X < d_x; X++)
            cout << W[X][Y] << " ";
        cout << endl;
    }

    system("PAUSE");
    return 0;
}