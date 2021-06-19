#include <bits/stdc++.h>
using namespace std;

#include "kolejka.hpp"

int main()
{
    bool run = true;
    char c;
    int n;

    cout << "wpisz rozmiar kolejki: ";
    cin >> n;

    Queue *Q = new Queue(n);

    while (run)
    {

        cout << "\n";
        cout << "w - wypisz kolejke\n"
             << "d - dodaj \n"
             << "u - usun \n"
             << "p - poczatek \n"
             << "e - exit \n"
             << "r- rozmiar \n";

        cout << "\n";

        cin >> c;

        system("clear");

        switch (c)
        {
         case 'w':
        {
            Q->wypisz();
            cout << "\n";
            break;
        }


        case 'd':
        {
            cout << "dodaj cos do kolejki: \n";
            string x;
            cin >> x;

            if (Q->czy_pelna())
            {
                clog << "kolejka jest pelna! \n";
                break;
            }
            Q->wloz(x);
            cout << "dodano: " << x << "\n";
            break;
        }

        case 'u':
        {
            cout << "usuniete: " << Q->wyciagnij() << "\n";
            break;
        }

        case 'p':
        {
            cout << "poczatek: " << Q->sprawdz() << "\n";
            break;
        }
         case 'e':
        {
            run = false;
            break;
        }

        case 'r':
        {
            cout << "rozmiar: " << Q->rozmiar() << "\n";
            break;
        }


        }
    }

    return 0;
}
