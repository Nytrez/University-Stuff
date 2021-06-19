#include <iostream>
#include "tab_dbl.hpp"

using namespace std;
using namespace obliczenia;

int main()
{

    tab_dbl x(3);
    cout << x[0] << endl;
    x[1] = 1.234;
    x[2] = 2.1;
    x[0] = x[1] + x[2];
    // x[4]=1;  what():  niepoprawny indeks
    cout << x[0] << endl;

    x[0] = 1.2;
    cout << x[0] << endl;

    tab_dbl y = x;
    cout << y[0] << endl;

    tab_dbl z(y);
    cout << z[0] << endl;

    cout << z.get_dl() << endl;

    cout << z * y << endl;

    tab_dbl max; // tworzy tablice od 2^1 do 2^28 (134217728) i wyrzucal blad przy tablicy o rozmiarze 2^29 (268435456)
    cout << max[1] << endl;
    cout << max.get_dl() << endl;

    tab_dbl ini({12.2, 0.234, 0.23, 0, 1.53}); //tworzenie korzystajac z inicjalizatora
    cout<<ini.get_dl()<<endl;
    cout<<ini[2]<<endl;

    //cout<<ini*z<<endl; //zwraca blad what():  dlugosci tablic sa rozne
}