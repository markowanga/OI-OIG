/**
 * III Olimpiada Informatyczna Gimnazjalistów
 * Zadanie: Palindroliczby
 * Wynik 100/100
 * Wykonał: Marcin Wątroba
 * http://main.edu.pl/pl/archive/oig/3/pal
 */

#include <iostream>
#include <string>
#include <vector>
#include <cstdio>

using namespace std;

const int BASE = 1000000000;
const int DIGS = 9;
struct liczba {
    vector<int> kont;
};

void odczyt(liczba &l) {
    l.kont.clear();
    string str;
    cin >> str;
    int G = 0, m = 1;
    for (int a = str.size() - 1; a >= 0; a--) {
        G += ((int) str[a] - 48) * m;
        if (m == BASE / 10) {
            l.kont.push_back(G);
            m = 1;
            G = 0;
        } else if (a == 0)
            l.kont.push_back(G);
        else
            m *= 10;
    }
}

liczba intToLiczba(int l) {
    liczba w;
    w.kont.push_back(l);
    return w;
}

int liczbaToInt(liczba l) {
    return l.kont[0];
}

void wyswietl(liczba l) {
    cout << l.kont[l.kont.size() - 1];
    for (int a = l.kont.size() - 2; a >= 0; a--)
        printf("%0*d\n", 9, l.kont[a]);
}

int ile_cyfr(liczba l) {
    int pom;
    int w = (l.kont.size() - 1) * DIGS;
    pom = l.kont[l.kont.size() - 1];
    if (pom == 0)
        w++;
    for (pom; pom != 0; pom /= 10, w++);
    return w;
}

void pomnoz_razy_wiel_10(liczba &l, int k) {
    // k to ile zer mam odoać przred liczbą
    liczba pom;
    int ile_pustych = k / DIGS;
    for (int a = 0; a < ile_pustych; a++)
        pom.kont.push_back(0);
    k %= DIGS;
    long long mn = 1;
    for (int a = 0; a < k; a++)
        mn *= 10;
    long long pp = 0;
    for (int a = 0; a < l.kont.size(); a++) {
        pp += mn * l.kont[a];
        pom.kont.push_back((int) (pp % BASE));
        pp /= BASE;
    }
    if (pp != 0)
        pom.kont.push_back((int) (pp % BASE));
    l = pom;
}

void podziel_10(liczba &l) {
    liczba w;
    int pom;
    for (int a = 0; a < l.kont.size(); a++) {
        if (a != 0)
            w.kont[a - 1] += (l.kont[a] % 10) * 100000000;
        pom = l.kont[a] / 10;
        if ((a == l.kont.size() - 1 && pom != 0)
            || (a != l.kont.size() - 1))
            w.kont.push_back(pom);
    }
    l = w;
}

bool operator>(liczba A, liczba B) {
    if (A.kont.size() > B.kont.size())
        return true;
    if (A.kont.size() < B.kont.size())
        return false;
    for (int a = A.kont.size() - 1; a >= 0; a--) {
        if (A.kont[a] > B.kont[a])
            return true;
        if (A.kont[a] < B.kont[a])
            return false;
    }
    return false;
}

bool operator<(liczba A, liczba B) {
    if (A.kont.size() > B.kont.size())
        return false;
    if (A.kont.size() < B.kont.size())
        return true;
    for (int a = A.kont.size() - 1; a >= 0; a--) {
        if (A.kont[a] > B.kont[a])
            return false;
        if (A.kont[a] < B.kont[a])
            return true;
    }
    return false;
}

bool operator<=(liczba A, liczba B) {
    return !(A > B);
}

bool operator>=(liczba A, liczba B) {
    return !(A < B);
}

bool operator==(liczba A, liczba B) {
    if (A.kont.size() != B.kont.size())
        return false;
    for (int a = 0; a < A.kont.size(); a++)
        if (A.kont[a] != B.kont[a])
            return false;
    return true;
}

bool operator!=(liczba A, liczba B) {
    if (A.kont.size() != B.kont.size())
        return true;
    for (int a = 0; a < A.kont.size(); a++)
        if (A.kont[a] != B.kont[a])
            return true;
    return false;
}

liczba operator+(liczba A, liczba B) {
    liczba W;
    if (A.kont.size() < B.kont.size())
        swap(A, B);

    int G = 0;
    for (int a = 0; a < A.kont.size(); a++) {
        G += A.kont[a];
        if (a < B.kont.size())
            G += B.kont[a];
        W.kont.push_back(G % BASE);
        G /= BASE;
    }
    if (G != 0)
        W.kont.push_back(G);
    return W;
}

void operator+=(liczba &A, liczba B) {
    A = A + B;
}

liczba operator-(liczba A, liczba B) {
    liczba W;
    for (int a = 0; a < A.kont.size(); a++) {
        if (A.kont[a] < 0) {
            A.kont[a] += BASE;
            A.kont[a + 1]--;
        }
        if (a < B.kont.size()) {
            if (A.kont[a] < B.kont[a]) {
                A.kont[a] += BASE;
                A.kont[a + 1]--;
            }
            W.kont.push_back(A.kont[a] - B.kont[a]);
        } else
            W.kont.push_back(A.kont[a]);
    }

    // usuwanie pustych zer czyli 0000043 -> 43
    for (int a = W.kont.size() - 1; a > 0; a--) {
        if (W.kont[a] == 0)
            W.kont.pop_back();
        else break;
    }
    return W;
}

void operator-=(liczba &A, liczba B) {
    A = A - B;
}

liczba operator%(liczba A, liczba B) {
    int dl_A = ile_cyfr(A), dl_B = ile_cyfr(B);
    int ileDodacZer = dl_A - dl_B;
    if (ileDodacZer > 0)
        pomnoz_razy_wiel_10(B, ileDodacZer);

    for (ileDodacZer; ileDodacZer >= 0; ileDodacZer--) {
        while (A >= B)
            A -= B;
        podziel_10(B);
    }
    return A;
}

void operator%=(liczba &A, liczba B) {
    A = A % B;
}

liczba operator%(liczba A, int B) {
    long long dziel = 0;
    for (int a = A.kont.size() - 1; a >= 0; a--) {
        dziel *= BASE;
        dziel += A.kont[a];
        dziel %= B;
    }
    return intToLiczba((int) dziel);
}

void operator%=(liczba &A, int B) {
    A = A % B;
}

liczba operator/(liczba A, liczba B) {
    int licznik;
    int dl_A = ile_cyfr(A), dl_B = ile_cyfr(B);
    int ileDodacZer = dl_A - dl_B;
    if (ileDodacZer > 0)
        pomnoz_razy_wiel_10(B, ileDodacZer);
    // zarezerwowanie struktury wyniku
    liczba W;
    // i - ilość cyfr w których zawiera się wynik
    int i = ileDodacZer + 1;
    int j = i / 9;
    if (i % 9 != 0)
        j++;
    for (int a = 0; a < j; a++)
        W.kont.push_back(0);
    //zmienne dzieiki którym będziemy zapisywać wynik
    int ind = i / 9; // indeks uzupełnianej liczby z wynikiem
    if (i % 9 == 0)
        ind--;
    int mn = 1;
    if (i % 9 == 0)
        i = 9;
    else i %= 9;
    for (int a = 1; a < i; a++)
        mn *= 10;
    for (ileDodacZer; ileDodacZer >= 0; ileDodacZer--) {
        licznik = 0;
        while (A >= B) {
            A -= B;
            licznik++;
        }
        podziel_10(B);
        W.kont[ind] += licznik * mn;
        if (mn == 1) {
            mn = 100000000;
            ind--;
        } else mn /= 10;
    }

    // usuwanie nieznaczących zer
    for (int a = W.kont.size() - 1; a > 0; a--) {
        if (W.kont[a] == 0)
            W.kont.pop_back();
        else break;
    }
    if (W.kont.size() == 0)
        W.kont.push_back(0);
    return W;
}

void operator/=(liczba &A, liczba B) {
    A = A / B;
}

liczba operator/(liczba A, int B) {
    liczba W = A;
    int ind = W.kont.size();
    for (int a = 0; a < ind; a++)
        W.kont[a] = 0;
    long long dziel = 0;
    for (int a = ind - 1; a >= 0; a--) {
        dziel *= BASE;
        dziel += A.kont[a];
        W.kont[a] = dziel / B;
        dziel %= B;
    }
    // usuwanie nieznaczących zer
    for (int a = W.kont.size() - 1; a > 0; a--) {
        if (W.kont[a] == 0)
            W.kont.pop_back();
        else break;
    }
    return W;
}

void operator/=(liczba &A, int B) {
    A = A / B;
}

liczba operator*(liczba A, liczba B) {
    // mnożenie w słupku (przyspieszona wersja -> częściej dodawane cząstki)
    ///*
    int max_dl_wyniku = A.kont.size() + B.kont.size() + 1;
    long long pom;
    liczba W;
    for (int a = 0; a < max_dl_wyniku; a++)
        W.kont.push_back(0);
    for (int a = 0; a < A.kont.size(); a++)
        for (int b = 0; b < B.kont.size(); b++) {
            pom = (long long) A.kont[a] * (long long) B.kont[b];
            W.kont[a + b] += pom % BASE;
            W.kont[a + b + 1] += pom / BASE;
            if (W.kont[a + b] >= BASE) {
                W.kont[a + b + 1] += W.kont[a + b] / BASE;
                W.kont[a + b] %= BASE;
            }
            if (W.kont[a + b + 1] >= BASE) {
                W.kont[a + b + 2] += W.kont[a + b + 1] / BASE;
                W.kont[a + b + 1] %= BASE;
            }
        }
    // usuwanie pustych zer czyli 0000043 -> 43
    for (int a = W.kont.size() - 1; a > 0; a--) {
        if (W.kont[a] == 0)
            W.kont.pop_back();
        else break;
    }
    return W;
    //*/
}

void operator*=(liczba &A, liczba B) {
    A = A * B;
}

bool czy_pali(string str) {
    for (int a = 0; a < str.size() / 2; a++)
        if (str[a] != str[str.size() - 1 - a])
            return false;
    return true;
}

int main() {
    liczba l, pom;
    odczyt(l);
    int licznik = 0;
    for (int a = 2; a <= 10; a++) {
        pom = l;
        string str;
        while (pom != intToLiczba(0)) {
            str += liczbaToInt(pom % a) + 48;
            pom /= a;
        }
        if (czy_pali(str) == true) {
            licznik++;
            cout << a << " " << str << endl;
        }
    }
    if (licznik == 0)
        cout << "NIE" << endl;

    system("PAUSE");
    return 0;
}