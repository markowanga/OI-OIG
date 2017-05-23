/**
 * II Olimpiada Informatyczna Gimnazjalistów
 * Zadanie: Żabka Bajtozja
 * Wynik 100/100
 * Wykonał: Marcin Wątroba
 * http://main.edu.pl/pl/archive/oig/2/zab
 */

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <set>
#include <queue>
#include <utility>
#include <math.h>

using namespace std;

long long odl(pair<int, int> *Zb, int a, int b) {
    long long W = 0;
    long long x = (long long) Zb[a].first - (long long) Zb[b].first;
    x *= x;
    long long y = (long long) Zb[a].second - (long long) Zb[b].second;
    y *= y;

    return x + y;
}

int main() {
    int n, p, g;
    long long s, max = 0, po;
    cin >> n >> p >> s;
    p--;
    s *= s;
    pair<int, int> *Zb = new pair<int, int>[n];
    bool *cb = new bool[n];
    pair<int, int> pom;
    for (int a = 0; a < n; a++) {
        cb[a] = false;
        cin >> pom.first >> pom.second;
        Zb[a] = pom;
    }

    queue<int> K;
    K.push(p);
    cb[p] = true;
    while (!K.empty()) {
        g = K.front();
        po = odl(Zb, g, p);
        if (po > max)
            max = po;
        for (int a = 0; a < n; a++)
            if (!cb[a])
                if (odl(Zb, g, a) <= s) {
                    cb[a] = true;
                    K.push(a);
                }
        K.pop();
    }

    cout << fixed << setprecision(3) << sqrt((double) max) + sqrt((double) s) << endl;

    system("PAUSE");
    return 0;
}