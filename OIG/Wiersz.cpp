/**
 * VI Olimpiada Informatyczna Gimnazjalistów
 * Zadanie: Wiersz
 * Wynik 100/100
 * Wykonał: Marcin Wątroba
 * http://main.edu.pl/pl/archive/oig/6/wie
 */

#include <cstdlib>
#include <iostream>

using namespace std;

void liczw(char tab[], int il[2]) {
    int a = 0;
    il[1] = 0;
    for (a; tab[a] != '\0'; a++) {
        if (tab[a] == 'a' || tab[a] == 'e' || tab[a] == 'i' || tab[a] == 'o' || tab[a] == 'u' || tab[a] == 'y') il[1]++;
    }
    il[0] = a;
    return;
}

bool por(char t1[], char t2[], int i1, int i2, int k) {
    i1--;
    i2--;
    while (k > 0) {
        while (t1[i1] == ' ')i1--;
        while (t2[i2] == ' ')i2--;
        if (i1 < 0 || i2 < 0)return false;
        if (t1[i1] != t2[i2])return false;
        k--;
        i1--;
        i2--;
    }
    return true;
}

int main(int argc, char *argv[]) {
    int n, k;
    cin >> n >> k;
    int il[2][2];
    int w = 0;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        char *t1 = new char[2001];
        char *t2 = new char[2001];
        cin.getline(t1, 2001);
        cin.getline(t2, 2001);
        liczw(t1, il[0]);
        //cout<<"p1 ";
        liczw(t2, il[1]);
        //cout<<"p2 ";
        //cout<<il[0][1]<<il[1][1]<<endl;
        if (il[0][1] == il[1][1]) {
            if (por(t1, t2, il[0][0], il[1][0], k)) {
                w++;
            }
        }
        //cout<<"por"<<endl;
    }
    cout << w;
    return EXIT_SUCCESS;
}