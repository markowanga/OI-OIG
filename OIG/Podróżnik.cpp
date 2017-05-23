/**
 * VI Olimpiada Informatyczna Gimnazjalistów
 * Zadanie: Podróżnik
 * Wynik 100/100
 * Wykonał: Marcin Wątroba
 * http://main.edu.pl/pl/archive/oig/6/pod
 */

#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

struct pkt {
    int x;
    int y;
};

void ctab(char tab[]) {
    for (int a = 0; tab[a] != '\0'; a++) tab[a] = '\0';
}

pkt zak(char tab[], int l[]) {
    pkt p;
    for (int a = 0; a < 4; a++) l[a] = 0;
    p.x = 0;
    p.y = 0;
    for (int a = 0; tab[a] != '\0'; a++) {
        if (tab[a] == 'W') {
            p.x--;
            if (p.x < l[1])l[1]--;
        }
        if (tab[a] == 'E') {
            p.x++;
            if (p.x > l[0])l[0]++;
        }
        if (tab[a] == 'N') {
            p.y++;
            if (p.y > l[2])l[2]++;
        }
        if (tab[a] == 'S') {
            p.y--;
            if (p.y < l[3])l[3]--;
        }
        //cout<<"pkt "<<p.x<<" "<<p.y<<endl;
    }
    return p;
}

int main(int argc, char *argv[]) {
    int n;
    cin >> n;
    pkt poz;
    poz.x = 0;
    poz.y = 0;
    int gl[4] = {0};
    //cout<<gl[0]<<gl[1]<<gl[2]<<gl[3]<<endl;
    int lok[4];
    int il;
    char *t = new char[1000001];
    for (int i = 0; i < n; i++) {
        ctab(t);
        cin >> il;
        cin >> t;
        pkt przes = zak(t, lok);
        //cout<<"PRZESUNIECIE "<<przes.x<<" "<<przes.y<<endl;
        if (gl[0] < poz.x + lok[0])gl[0] = poz.x + lok[0];
        if (gl[1] > poz.x + lok[1])gl[1] = poz.x + lok[1];
        if (gl[2] < poz.y + lok[2])gl[2] = poz.y + lok[2];
        if (gl[3] > poz.y + lok[3])gl[3] = poz.y + lok[3];
        for (int a = 0; a < il - 1; a++) {
            poz.x += przes.x;
            poz.y += przes.y;
        }
        if (il > 1) {
            if (gl[0] < poz.x + lok[0])gl[0] = poz.x + lok[0];
            if (gl[1] > poz.x + lok[1])gl[1] = poz.x + lok[1];
            if (gl[2] < poz.y + lok[2])gl[2] = poz.y + lok[2];
            if (gl[3] > poz.y + lok[3])gl[3] = poz.y + lok[3];
        }
        poz.x += przes.x;
        poz.y += przes.y;
        //cout<<"LOK "<<lok[0]<<" "<<lok[1]<<" "<<lok[2]<<" "<<lok[3]<<endl;
        //cout<<"GL "<<gl[0]<<" "<<gl[1]<<" "<<gl[2]<<" "<<gl[3]<<endl;
        //cout<<"PKT "<<poz.x<<" "<<poz.y<<endl;
    }
    cout << gl[2] - gl[3] << " " << gl[0] - gl[1];
    return EXIT_SUCCESS;
}