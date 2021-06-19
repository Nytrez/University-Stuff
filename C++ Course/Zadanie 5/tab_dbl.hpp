#include <iostream>
#include <new>
#include <ctime>

namespace obliczenia
{

    class tab_dbl
    {
        double *tab;                          // tablica liczb zmiennopozycyjnych
        int dl;                               // rozmiar tablicy
    public:                                   //do zadania pierwszego
        explicit tab_dbl(int rozm);           // wyzerowana tablica liczb
        tab_dbl(const tab_dbl &t);            // konstruktor kopiujący
        tab_dbl(tab_dbl &&t);                 // konstruktor przenoszący
        tab_dbl &operator=(const tab_dbl &t); // przypisanie kopiujące
        tab_dbl &operator=(tab_dbl &&t);      // przypisanie przenoszące
        ~tab_dbl();                           // destruktor
        double &operator[](int num);
        double operator[](int num) const;

        //zad 2
        tab_dbl();

        //zad 3
        tab_dbl(const std::initializer_list<double>& ini);     //konstruktor inicjalizujacy   
        double operator*(const tab_dbl &t);       //iloczyn skalarny
        int get_dl() const; //do pobierania dlugosci
    };

}
