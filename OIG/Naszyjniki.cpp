/**
 * III Olimpiada Informatyczna Gimnazjalistów
 * Zadanie: Naszyjniki
 * Wynik 100/100
 * Wykonał: Marcin Wątroba
 * http://main.edu.pl/pl/archive/oig/3/nas
 */

#include <iostream>
#include <string>

using namespace std;

/*
1. JASNE
2. CIEMNE
3. jasne
4. ciemne
*/

int kat(char A) {
    if (A == 'A' || A == 'E' || A == 'I' || A == 'O' || A == 'U' || A == 'Y')
        return 1;
    if (A == 'a' || A == 'e' || A == 'i' || A == 'o' || A == 'u' || A == 'y')
        return 3;
    if ((int) A > 94)
        return 4;
    return 2;

}

int max(int a, int b) {
    if (a > b)
        return a;
    return b;
}

int min(int a, int b) {
    if (a == 0)
        return b;
    if (b == 0)
        return a;
    if (a < b)
        return a;
    return b;
}

int main() {
    int n;
    string str, pom;
    int MAX[5], tym[5], MIN[5];
    cin >> n;
    int ost = 0, k = 0;
    for (int a = 0; a < n; a++) {
        cin >> str;
        // ustawienie odpowiedniejgo poczštku odcinka
        /*
        for (int b = 0; b < str.size(); b++)
        {
            if (kat(str[0]) != kat(str[str.size() - 1]))
                break;
            pom = str;
            str = pom[pom.size() - 1];
            for (int i = 0; i < pom.size() - 1; i++)
                str += pom[i];
        }
        */
        if (kat(str[0]) == kat(str[str.size() - 1]))
            for (int b = str.size() - 2; b >= 0; b--) {
                if (kat(str[b]) != kat(str[b + 1])) {
                    pom = str;
                    str = pom[b + 1];
                    for (int c = b + 2; c < pom.size(); c++)
                        str += pom[c];
                    for (int c = 0; c <= b; c++)
                        str += pom[c];
                    break;
                }
            }

        for (int i = 0; i < 5; i++) {
            MAX[i] = 0;
            tym[i] = 0;
            MIN[i] = 0;
        }
        ost = 0;
        for (int b = 0; b < str.size(); b++) {
            k = kat(str[b]);
            //cout << k << " " << ost << " ";
            if (k != ost) {
                tym[k] = 1;
                MIN[ost] = min(tym[ost], MIN[ost]);
                ost = k;
            } else
                tym[k]++;
            if (str.size() - 1 == b)
                MIN[ost] = min(tym[ost], MIN[ost]);
            //cout << " " << tym[k];
            MAX[k] = max(tym[k], MAX[k]);
            //cout << endl;
        }

        // wyswietlenie wyniku
        int maks = MAX[1];
        int mini = MIN[1];
        for (int b = 2; b < 5; b++) {
            maks = max(maks, MAX[b]);
            mini = min(mini, MIN[b]);
            //cout << "MIN" << mini << endl;
        }
        // wys max
        for (int b = 1; b < 5; b++)
            if (MAX[b] == maks) {
                cout << maks << " ";
                if (b == 1)
                    cout << "JASNE";
                else if (b == 2)
                    cout << "CIEMNE";
                else if (b == 3)
                    cout << "jasne";
                else cout << "ciemne";
                cout << endl;
                break;
            }

        // min
        for (int b = 1; b < 5; b++)
            if (MIN[b] == mini) {
                cout << mini << " ";
                if (b == 1)
                    cout << "JASNE";
                else if (b == 2)
                    cout << "CIEMNE";
                else if (b == 3)
                    cout << "jasne";
                else cout << "ciemne";
                cout << endl;
                break;
            }
    }

    system("PAUSE");
    return 0;
}