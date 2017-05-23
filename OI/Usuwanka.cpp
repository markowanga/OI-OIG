/**
 * XX Olimpiada Informatyczna
 * Zadanie: Usuwanka
 * Wynik 100/100
 * Wykonał: Marcin Wątroba
 * http://main.edu.pl/pl/archive/oi/20/usu
 */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class ss {
public:
    int ilc;
    int ilb;
    int nr;

    ss(int a, int b, int c) {
        ilc = a;
        ilb = b;
        nr = c;
    }
};

int main() {
    int n, k;
    cin >> n >> k;
    stack<int> wynik;
    vector<ss> str;
    char z;
    str.push_back(ss(0, 0, 0));
    for (int a = 1; a <= n; a++) {
        scanf(" %c", &z);
        if (z == 'b')
            str.push_back(ss(str.back().ilc, str.back().ilb + 1, a));
        else str.push_back(ss(str.back().ilc + 1, str.back().ilb, a));
        // sprawdzanie czy można usunąc
        if (str.size() > k + 1 && str[str.size() - 1].ilb == str[str.size() - 2 - k].ilb + k)
            // można usunąc
            for (int i = 0; i < k + 1; i++) {
                wynik.push(str.back().nr);
                str.pop_back();
            }
    }
    for (int a = 1; a <= n; a++) {
        if (a % (k + 1) != 0)
            printf("%d ", wynik.top());
        else printf("%d\n", wynik.top());
        wynik.pop();
    }

    return 0;
}