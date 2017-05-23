/**
 * VIII Olimpiada Informatyczna
 * Zadanie: Podróż
 * Wynik 100/100
 * Wykonał: Marcin Wątroba
 * http://main.edu.pl/pl/archive/oi/8/pod
 */

#include <cstdio>
#include <functional>
#include <queue>
using namespace std;

struct kurs
{
    short przystanek_poczakowy;
    short przystanek_koncowy;
    short godz;
    short czas_przejazdu;
    short nastepny;
    short linia;
};
bool operator<(kurs a, kurs b)
{
    if (a.godz != b.godz)
        return a.godz < b.godz;
    return a.linia > b.linia;
}
bool operator>(kurs a, kurs b)
{
    if (a.godz != b.godz)
        return a.godz > b.godz;
    return a.linia > b.linia;
}

void wczytaj_linie_komunikacyjna(priority_queue< kurs, vector<kurs>, greater<kurs> > &kolejka, short czas_pocz, int n)
{
    int s;
    short p;
    kurs pom;
    pom.linia = n;
    scanf("%d%hd", &s, &pom.nastepny);
    short *nr = new short[s];
    short *czasy = new short[s - 1];

    for (int a = 0; a < s; a++)
        scanf("%hd", &nr[a]);
    for (int a = 0; a < s - 1; a++)
        scanf("%hd", &czasy[a]);

    // dodanie w pierwszej kolejnosci
    short czas_dotychczas = (czas_pocz/60)*60 + 60;

    for (int a = 0; a < s - 1; a++)
    {
        pom.przystanek_poczakowy = nr[a];
        pom.przystanek_koncowy = nr[a + 1];
        while (czas_dotychczas - pom.nastepny >= czas_pocz)
            czas_dotychczas = czas_dotychczas - pom.nastepny;
        czas_dotychczas = czas_dotychczas + czasy[a];
        pom.godz = czas_dotychczas;
        pom.czas_przejazdu = czasy[a];
        kolejka.push(pom);
    }

    // dodanie przejazdu od konca
    czas_dotychczas = (czas_pocz / 60) * 60 + 60;
    for (int a = s - 2; a >= 0; a--)
    {
        pom.przystanek_poczakowy = nr[a + 1];
        pom.przystanek_koncowy = nr[a];
        while (czas_dotychczas - pom.nastepny >= czas_pocz)
            czas_dotychczas = czas_dotychczas - pom.nastepny;
        czas_dotychczas = czas_dotychczas + czasy[a];
        pom.godz = czas_dotychczas;
        pom.czas_przejazdu = czasy[a];
        kolejka.push(pom);
    }
}

int main()
{
    short n, k, x, y, g_pocz, m_pocz, czas_pocz;
    //multiset<kurs> kolejka;
    priority_queue< kurs, vector<kurs>, greater<kurs> > kolejka;
    scanf("%hd%hd%hd%hd%hd%hd", &n, &k, &x, &y, &g_pocz, &m_pocz);
    czas_pocz = g_pocz * 60 + m_pocz;
    for (int a = 0; a < k; a++)
        wczytaj_linie_komunikacyjna(kolejka, czas_pocz, a+1);

    // utworzennie tablicy z informacjami czy dany przystanek był odwiedzony
    short *czy_odwiedzony = new short[n + 1];
    for (int a = 1; a <= n; a++)
        czy_odwiedzony[a] = 6000;
    czy_odwiedzony[x] = czas_pocz;

    // symulacja
    kurs tymczas;
    while (czy_odwiedzony[y] == 6000 && !kolejka.empty())
    {
        tymczas = kolejka.top();
        if (czy_odwiedzony[tymczas.przystanek_poczakowy] <= tymczas.godz - tymczas.czas_przejazdu)
        {
            if (czy_odwiedzony[tymczas.przystanek_koncowy] > tymczas.godz)
                czy_odwiedzony[tymczas.przystanek_koncowy] = tymczas.godz;
        }
        else
        {
            tymczas.godz = tymczas.godz + tymczas.nastepny;
            kolejka.push(tymczas);
        }
        kolejka.pop();
    }

    printf("%hd %hd", (czy_odwiedzony[y] / 60) % 24, czy_odwiedzony[y] % 60);

    return 0;
}