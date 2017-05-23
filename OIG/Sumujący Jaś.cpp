/**
 * I Olimpiada Informatyczna Gimnazjalistów
 * Zadanie: Sumujący Jaś
 * Wynik 100/100
 * Wykonał: Marcin Wątroba
 * http://main.edu.pl/pl/archive/oig/1/sum
 */

#include <iostream>
#include <string>

using namespace std;

struct liczba {
    string l;
    int przec; //ilość liczb bo przecinku
    bool znak; // true plus, flase minus
};

string usun_pier_znak(string l) {
    string w;
    for (int a = 1; a < (int) l.size(); a++)
        w += l[a];
    return w;
}

string usun_ost_znak(string l) {
    string w;
    for (int a = 0; a < l.size() - 1; a++)
        w += l[a];
    return w;
}

liczba odczytaj() {
    string l;
    cin >> l;
    liczba w;

    // odczytanie znaku
    if (l[0] == '+') {
        w.znak = true;
        l = usun_pier_znak(l);
    } else if (l[0] == '-') {
        w.znak = false;
        l = usun_pier_znak(l);
    } else
        w.znak = true;

    // przepisanie liczby bez przecinka
    for (int a = 0; a < (int) l.size(); a++)
        if (l[a] != ',')
            w.l += l[a];

    // odczytanie ile cyfr po przecinku
    w.przec = 0;
    for (int a = l.size() - 1; a >= 0; a--) {
        if (l[a] == ',')
            break;
        else
            w.przec++;
    }
    if (w.przec == w.l.size())
        w.przec = 0;

    // odwrócenie kolejności liczby
    for (int a = 0; a < (int) w.l.size() / 2; a++)
        swap(w.l[a], w.l[w.l.size() - a - 1]);

    return w;
}

bool czy_rowne_abs(liczba A, liczba B) {
    if (A.l != B.l)
        return false;
    return true;
}

bool czy_wieksze_abs(liczba A, liczba B) {
    // jak A większe to true
    if (A.l.size() > B.l.size())
        return true;
    if (A.l.size() < B.l.size())
        return false;
    for (int a = A.l.size() - 1; a >= 0; a--) {
        if ((int) A.l[a] > (int) B.l[a])
            return true;
        if ((int) A.l[a] < (int) B.l[a])
            return false;
    }
    return false;
}

liczba dodawanie(liczba A, liczba B) {
    liczba w;
    w.znak = A.znak;
    w.przec = A.przec;
    if (czy_wieksze_abs(B, A))
        swap(A, B);

    // dodanie cyfr długości pierwszej
    for (int a = 0; a < B.l.size(); a++) {
        if (w.l.size() == a)
            w.l += '0';
        w.l[a] = (char) ((int) A.l[a] + (int) B.l[a] + (int) w.l[a] - 96);

        // jak nadstan
        if ((int) w.l[a] > 57) {
            w.l[a] = (char) ((int) w.l[a] - 10);
            w.l += '1';
        }
    }

    // dodanie liczb (głównie przepisanie )
    for (int a = B.l.size(); a < A.l.size(); a++) {
        if (w.l.size() == a)
            w.l += '0';
        w.l[a] = (char) ((int) A.l[a] + (int) w.l[a] - 48);

        // jak nadstan
        if ((int) w.l[a] > 57) {
            w.l[a] = (char) ((int) w.l[a] - 10);
            w.l += '1';
        }
    }
    return w;
}

liczba odejmowanie(liczba A, liczba B) {
    liczba w;
    if (czy_rowne_abs(A, B)) {
        w.l = "0";
        w.przec = A.przec;
        w.znak = true;
        return w;
    }
    if (czy_wieksze_abs(B, A))
        swap(A, B);
    w.znak = A.znak;
    w.przec = A.przec;

    // dorównanie długości liczb
    while (true) {
        if (A.l.size() == B.l.size())
            break;
        else B.l += '0';
    }

    // odejmowanie ostateczne
    for (int a = 0; a < A.l.size(); a++) {
        if ((int) A.l[a] < B.l[a]) {
            A.l[a] = (char) ((int) A.l[a] + 10);
            A.l[a + 1] = (char) ((int) A.l[a + 1] - 1);
        }
        w.l += (char) ((int) A.l[a] - (int) B.l[a] + 48);
    }

    // usuwanie ostatnich liczb
    while (true) {
        if (w.l[w.l.size() - 1] == '0')
            w.l = usun_ost_znak(w.l);
        else break;
    }

    return w;
}

liczba dzialanie(liczba A, liczba B) {
    liczba w;
    if ((A.znak && !B.znak)
        || (!A.znak && B.znak)) {
        w = odejmowanie(A, B); // odejmowanie
    } else {
        w = dodawanie(A, B); // dodawanie
    }
    return w;
}

void wyswietl(liczba A) {
    string w;

    while (true) {
        if (A.l.size() > A.przec)
            break;
        else A.l += '0';
    }

    // dodanie przecinka do cyfry
    for (int a = 0; a < A.l.size(); a++) {
        if (A.przec == a)
            w += ',';
        w += A.l[a];
    }

    // usuwanie niepotrzebnych znaków
    while (true) {
        if (w[0] == ',') {
            w = usun_pier_znak(w);
            break;
        } else if (w[0] == '0')
            w = usun_pier_znak(w);
        else break;
    }

    // dodanie minusa
    if (!A.znak)
        w += '-';

    for (int a = 0; a < (int) w.size() / 2; a++)
        swap(w[a], w[w.size() - a - 1]);
    cout << w << endl;
}

int main() {
    // odczytanie danych
    int n;
    cin >> n;
    liczba *tab = new liczba[n];
    for (int a = 0; a < n; a++)
        tab[a] = odczytaj();

    // uzupełnienie zer po przecinkach
    int przec_max = 0;
    for (int a = 0; a < n; a++)
        if (przec_max < tab[a].przec)
            przec_max = tab[a].przec;
    for (int a = 0; a < n; a++) {
        int dod = przec_max - tab[a].przec;
        string str;
        for (int a = 0; a < dod; a++)
            str += '0';
        tab[a].l = str + tab[a].l;
        tab[a].przec = przec_max;
    }

    // wykonywanie działań
    for (int a = 1; a < n; a++) {
        tab[a] = dzialanie(tab[a - 1], tab[a]);
    }

    wyswietl(tab[n - 1]);

    system("PAUSE");
    return 0;
}