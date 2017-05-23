/**
 * III Olimpiada Informatyczna Gimnazjalistów
 * Zadanie: Kalendarze
 * Wynik 100/100
 * Wykonał: Marcin Wątroba
 * http://main.edu.pl/pl/archive/oig/3/kal
 */

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

bool comp(const pair<int, int> &T, const int &W)
{
    if (T.second >= W)
        return false;
    return true;
}

int main()
{
    int n, m;
    //cin >> n >> m;
    scanf("%d%d", &n, &m);
    vector < pair<int, int> > A(n);
    vector < pair<int, int> > B(m);

    int pocz = 1;
    int dl;
    // wczytanie roku A
    for (int a = 0; a < n; a++)
    {
        //cin >> dl;
        scanf("%d", &dl);
        A[a].first = pocz;
        A[a].second = A[a].first + dl - 1;
        pocz += dl;
    }

    pocz = 1;
    // wczytanie roku B
    for (int a = 0; a < m; a++)
    {
        //cin >> dl;
        scanf("%d", &dl);
        B[a].first = pocz;
        B[a].second = B[a].first + dl - 1;
        pocz += dl;
    }

    int il;
    //cin >> il;
    scanf("%d", &il);
    int mies, dzien, dzien_b;
    char z;
    vector < pair<int, int> > :: iterator it;
    for (int i = 0; i < il; i++)
    {
        scanf("%d%d%s", &dzien, &mies, &z);
        //cin >> dzien >> mies >> z;
        mies--;
        dzien--;
        if (z == 'A') // A -> B
        {
            dzien_b = A[mies].first + dzien;
            //cout << "dzien bez: " << dzien_b << endl;
            it = lower_bound(B.begin(), B.end()-1, dzien_b, comp);
            //cout << dzien_b - (*it).first + 1 << " " << it - B.begin() + 1 << endl;
            printf("%d %d\n", dzien_b - (*it).first + 1, it - B.begin() + 1);
        }
        else // B -> A
        {
            dzien_b = B[mies].first + dzien;
            //cout << "dzien bez: " << dzien_b << endl;
            it = lower_bound(A.begin(), A.end()-1, dzien_b, comp);
            //cout << dzien_b - (*it).first + 1 << " " << it - A.begin() + 1 << endl;
            printf("%d %d\n", dzien_b - (*it).first + 1, it - A.begin() + 1);
        }
    }

    system("PAUSE");
    return 0;
}