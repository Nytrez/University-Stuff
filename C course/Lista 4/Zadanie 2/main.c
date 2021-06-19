#include <stdio.h>
#include <stdlib.h>
#include "licz.h"
//Szymon Szendzielorz
//Przepraszam za pozne przeslanie zadania, ale bylem pewien ze wczesniej juz przeslalem
int main()
{
    wymierna x,y,z,g,q,h;

    //czytam i tworze liczbe
    int a,b;
    czytaj(&a,&b);
    if(b==0){printf("Blad, nie dziel przez 0!!!");return 0;}
    x=stworz(a,b);

    //wypisuje liczbe
    wymierna mianx,liczx;

    mianx=mianownik(x);
    liczx=licznik(x);
    printf("Liczba wymierna:");
    wypisz(x);
    printf("\n");

    //dodawanie
    czytaj(&a,&b);
    if(b==0){printf("Blad,nie dziel przez 0!!!");return 0;}
    y=stworz(a,b);
    z=dodaj(x,y);
    printf("\nSuma liczb a i b: ");
    wypisz(z);

    //odejmowanie
    g=odejmowanie(x,y);
    printf("Roznica a-b wynosi: ");
    wypisz(g);

    //mnozenie
    q=mnoz(x,y);
    printf("Iloczyn liczb a i b: ");
    wypisz(q);

    //dzielenie
    h=dziel(y,x);
    printf("Iloraz liczb a i b: ");
    wypisz(h);

    return 0;
}
