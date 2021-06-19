#include <bits/stdc++.h>
#include <iostream>
#include <cmath>

#define M_PI 3.14159265358979323846

class punkt
{

private:
    double x, y;

public:
    punkt(); //tworzenie domyslnego punktu
    punkt(const punkt &p); // konstruktor kopiujacy
    punkt(double x, double y);
    void print(); //wypisywanie wspolrzednych
    double rzedna(); //wyciagniecie x dla funkcji obliczajacej dlugosc //private
    double odcieta();//wyciagniecie y dla funkcji obliczajacej dlugosc //private
    void obroc(punkt a, double alfa); // obrot o kat alfa wzgledem punktu a
    void przesuniecie(double x, double y); //przesuniecice o x y
};

class Odcinek
{

private:
    punkt p1, p2;

public:
    Odcinek(); //tworzenie domyslnego odcinka
    Odcinek(const Odcinek &o); // konstruktor kopiujacy
    Odcinek(punkt p1, punkt p2); //tworzenie odcinka z punktu p1 do punktu p2
    void print(); //wypisanie koordynatow
    double dlugosc(); //mierzenie dlugosci odcinka
    bool czy_na_odcinku(punkt p); //sprawdzeniue czy punkt lezy na odcinku
    punkt srodek_odcinka(); //wypisanie srodka odcinka
    void przesuniecie(double x, double y);//przesuniecie odcinka o x y
    void obrot(punkt p, double alfa);//obrot odcinka wzgledem punktu p o kat alfa
    bool rownolegle(Odcinek o, Odcinek m); //sprawdzenie czy odcinki sa rownolegle
    bool prostopadle(Odcinek o, Odcinek m); //sprawdzenie czy odcinki sa prostopadle
    punkt punkt_przeciecia(Odcinek o, Odcinek m); //wyznaczenie punktu przeciecia odcunkow
};

class trojkat
{

private:
    punkt p1, p2, p3;

public:
    trojkat();//tworzenie domyslnego trojkata
    trojkat(punkt a, punkt b, punkt c);//tworzenie trojkata o wierzcholkach a b c
    void print();// wypisanie wierzcholkow trojkata
    double pole(trojkat t);//wyznaczenie pola trojkata
    double obwod(trojkat t);//wyznaczenie obwoduu trojkata
    punkt srodek(trojkat t);//wyznaczenie srodka trojkata
    double znak(punkt p1, punkt p2, punkt p3);
    bool czy_w_srodku(punkt t);//wyznaczenie czy punkt lezy w srodku trojkata
    bool zawiera(trojkat t1, trojkat t2);//wyznaczenie czy trojkat zawiera sie w drugim
    void przesuniecie(double x, double y);//przesuniecie trojkata o x y
    void obrot(punkt p, double alfa);//obrot trojkata wzgledem punktu p i kata alfa
};

inline double odleglosc(punkt a, punkt b)//wyznaczenie odleglosci punktow a i b
{
    double a_x = a.rzedna();
    double a_y = a.odcieta();

    double b_x = b.rzedna();
    double b_y = b.odcieta();

    return sqrt((a_x - b_x) * (a_x - b_x) + (a_y - b_y) * (a_y - b_y));
};
