#include <stdio.h>
#include <stdlib.h>
#include "kolejka.h"

int main()
{

    kolejka_T* kolejeczka=strt_kolejka(4); //inicjalizacja kolejki
    for(double i=1;i<=4;i++){          // rozpoczecie operacji na kolejce
        dodaj(kolejeczka,i);
    }

    dodaj(kolejeczka,19);
    pobierz(kolejeczka);
    dodaj(kolejeczka,9);

     for(double i=6;i<12;i++){
        dodaj(kolejeczka,i);
    }
    pobierz(kolejeczka);
    dodaj(kolejeczka,70);

 for(double i=75;i<81;i++){
        dodaj(kolejeczka,i);
    }                          //koniec operacji na kolejce

    //wypisanie zawartosci kolejki
    double*i=kolejeczka->poczkol;
    while(i!=kolejeczka->konkol){
        printf("%.0f ", *(i));
        i++;
        if(i>kolejeczka->tab_k) i=kolejeczka->tab;
    }

    //oproznienie kolejki oraz sprawdzenie czy zostala oprozniona
     oproznij(kolejeczka);

     if(czy_pusta(kolejeczka)){printf("\nkolejka oprozniona!");}
     else{printf("kolejka nie pusta");}

    return 0;
}
