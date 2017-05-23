/**
 * III Olimpiada Informatyczna Gimnazjalistów
 * Zadanie: Statystyki
 * Wynik 100/100
 * Wykonał: Marcin Wątroba
 * http://main.edu.pl/pl/archive/oig/3/sta
 */

#include <iostream>
#include <string>

using namespace std;

bool czy_pali(string str) {
    // zamiana na duże litery całego słowa
    for (int a = 0; a < str.size(); a++)
        if ((int) str[a] > 90)
            str[a] = (char) ((int) str[a] - 32);

    for (int a = 0; a < str.size() / 2; a++)
        if (str[a] != str[str.size() - a - 1])
            return false;
    return true;
}

int main() {
    char ost_znak = '\0';
    // spacje
    int spacje = 0;

    // liczby
    int liczby = 0;

    // slowa
    int slowa = 0;

    // zdania
    int zdania = 0;
    int il_slow_zdania = 0;

    // palindromy
    int palindormy = 0;
    string slowo = "";

    //////
    string W;
    int n;
    cin >> n;
    int *tab = new int[n];
    for (int a = 0; a < n; a++)
        cin >> tab[a];
    cin.ignore();
    getline(cin, W);

    for (int a = 0; a < W.size(); a++) {
        // jak cyfra
        if ((int) W[a] >= 48 && (int) W[a] <= 57) {
            //cout << "cyfra" << endl;
            if ((int) ost_znak > 57 || (int) ost_znak < 48)
                liczby++;
            if (slowo.size() != 0)
                if (czy_pali(slowo))
                    palindormy++;
            slowo = "";
        }
            // jak litera
        else if (((int) W[a] >= 65 && (int) W[a] <= 90)
                 || ((int) W[a] >= 97 && (int) W[a] <= 122)) {
            //cout << "litera" << endl;
            if (slowo.size() == 0) {
                slowa++;
                il_slow_zdania++;
            }
            slowo += W[a];
        }
            // jak spacja
        else if (W[a] == ' ') {
            //cout << "spacja" << endl;
            spacje++;
            if (slowo.size() != 0)
                if (czy_pali(slowo))
                    palindormy++;
            slowo = "";
        }
            // jak kropka
        else if (W[a] == '.') {
            //cout << "kropka" << endl;
            if (slowo.size() != 0)
                if (czy_pali(slowo))
                    palindormy++;
            slowo = "";
            if (il_slow_zdania != 0)
                zdania++;
            il_slow_zdania = 0;
        } else {
            //cout << "inne" << endl;
            if (slowo.size() != 0)
                if (czy_pali(slowo))
                    palindormy++;
            slowo = "";
        }
        ost_znak = W[a];
    }
    if (slowo.size() != 0)
        if (czy_pali(slowo))
            palindormy++;
    for (int a = 0; a < n; a++) {
        if (tab[a] == 1)
            cout << spacje << " ";
        if (tab[a] == 2)
            cout << liczby << " ";
        if (tab[a] == 3)
            cout << slowa << " ";
        if (tab[a] == 4)
            cout << zdania << " ";
        if (tab[a] == 5)
            cout << palindormy << " ";
    }

    system("PAUSE");
    return 0;
}
// A-Z  -  65 - 90
// a-z  -  97 - 122
// 0-9  -  48 - 57
// spacja 32
// tab - 9