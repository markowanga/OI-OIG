/**
 * IV Olimpiada Informatyczna Gimnazjalistów
 * Zadanie: Program
 * Wynik 100/100
 * Wykonał: Marcin Wątroba
 * http://main.edu.pl/pl/archive/oig/4/pro
 */

#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
    int n;
    cin >> n;
    char tab[n];
    cin >> tab;
    char naw[3][2] = {{'(', ')'},
                      {'[', ']'},
                      {'{', '}'}};
    int w = 0;
    int r = 0;
    bool error = false;
    char *tt = new char[1000000];
    for (int a = 0; a < n; a++) {
        if (w == 0 && (tab[a] == '}' || tab[a] == ')' || tab[a] == ']')) {
            error = true;
            break;
        }
        if (tab[a] == '{' || tab[a] == '(' || tab[a] == '[') {
            tt[w] = tab[a];
            w++;
            if (r < w)r = w;
            //cout<<"up "<<w<<" "<<tt[w-1]<<endl;
        } else {
            w--;
            if ((tt[w] == '[' && tab[a] == ']') || (tt[w] == '(' && tab[a] == ')') || (tt[w] == '{' && tab[a] == '}')) {
                tt[w] = '\0';
                //cout<<"pop odj"<<endl;
            } else {
                //cout<<tab[w];
                //cout<<"error"<<endl;
                error = true;
                break;
            }
        }
    }
    if (tt[0] != '\0') {
        //cout<<"fik"<<endl;
        error = true;
    }
    if (error)cout << "NIE" << endl;
    else cout << r << endl;

    return EXIT_SUCCESS;
}