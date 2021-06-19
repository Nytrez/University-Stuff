#include <stdio.h>
#include <stdlib.h>
#include "modul.h"

int main()
{

    Lista lst = stworz();
    printf("dodawanie 10 elementow od 1 do 9 od lewej i prawej strony listy\n");
  for(double i=1;i<10;i++)
  {
      lst=dodaj_na_pocz(lst,i);
      lst=dodaj_na_tyl(lst,i);
  }
    wypisz(lst);
   printf("\nodejmowanie 5 elementow z lewej i prawej\n");
    for(double i=0;i<5;i++)
  {
      lst=odejmij_z_pocz(lst);
      lst=odejmij_z_kon(lst);
  }

    wypisz(lst);
    czy_pusta(lst);

    int x=dlugosc_listy(lst);
    printf("\nLista ma %d elementow\noproznianie listy...\n",x );

     for(int i=0;i<x;i++){
        lst=odejmij_z_pocz(lst);
     }

    wypisz(lst);
    czy_pusta(lst);

    printf("\nlista ma %d elementow\n", dlugosc_listy(lst));



    return 0;
}
