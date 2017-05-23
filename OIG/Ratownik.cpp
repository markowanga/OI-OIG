/**
 * VI Olimpiada Informatyczna Gimnazjalistów
 * Zadanie: Ratownik
 * Wynik 100/100
 * Wykonał: Marcin Wątroba
 * http://main.edu.pl/pl/archive/oig/6/rat
 */

#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    int ild, zas, rx, ry;
    cin >> ild >> zas >> rx >> ry;
    int w=0;
    int dx, dy, x, y, pit;
    for (int n=0; n<ild; n++)
    {
        cin >> dx >> dy;
        x=dx-rx;
        y=dy-ry;
        pit=x*x+y*y;
        if (pit>zas*zas)w++;
    }
    cout<<w;

    return EXIT_SUCCESS;
}