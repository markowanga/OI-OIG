/**
 * III Olimpiada Informatyczna Gimnazjalistów
 * Zadanie: Aquapark
 * Wynik 100/100
 * Wykonał: Marcin Wątroba
 * http://main.edu.pl/pl/archive/oig/3/aqu
 */

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int x(int a, int b, int n) {
    return -b + a + n;
}

int y(int a, int b) {
    return a + b - 1;
}

int main() {
    int n, r;
    //cin >> n >> r;
    scanf("%d %d", &n, &r);
    long long **t = new long long *[2 * n + 1];
    for (int a = 0; a < 2 * n + 1; a++) {
        t[a] = new long long[2 * n + 1];
        for (int b = 0; b < 2 * n + 1; b++)
            t[a][b] = 0;
    }
    long long pom;
    int px, py, kx, ky;
    // a kolumny(x)
    // b wiersze(y)
    for (int b = 1; b <= n; b++)
        for (int a = 1; a <= n; a++)
            //cin >> t[x(a, b, n)][y(a, b)];
            scanf("%lld", &t[x(a, b, n)][y(a, b)]);

    for (int b = 1; b < n * 2; b++)
        for (int a = 1; a < n * 2; a++)
            t[a][b] += t[a][b - 1] + t[a - 1][b] - t[a - 1][b - 1];

    int rx, ry, l, xx, yy;
    int x1, x2, y1, y2;
    long long prawy_gorny, lewy_gorny, lewy_dolny;
    for (int a = 0; a < r; a++) {
        //cin >> ry >> rx >> l;
        scanf("%d%d%d", &ry, &rx, &l);
        xx = x(rx, ry, n);
        yy = y(rx, ry);
        //cout << xx << " " << yy << endl;
        x1 = max(1, xx - l);
        y1 = max(1, yy - l);
        x2 = min(2 * n - 1, xx + l);
        y2 = min(2 * n - 1, yy + l);
        //cout << t[x2][y2] + t[x1 - 1][y1 - 1] - t[x1 - 1][y2] - t[x2][y1 - 1] << endl;
        printf("%lld\n", t[x2][y2] + t[x1 - 1][y1 - 1] - t[x1 - 1][y2] - t[x2][y1 - 1]);
    }

    system("PAUSE");
    return 0;
}
