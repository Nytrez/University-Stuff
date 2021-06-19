#include "kolejka.h"
#include <stdio.h>
#include <stdlib.h>

int k=0;
//inicjacja kolejki (i pamieci dla niej zarezerowanej)
kolejka_T* strt_kolejka(int n){
    kolejka_T* kolejka = calloc(1,sizeof(struct KOLEJKA_STRUCT));

     kolejka->tab=malloc(n*sizeof(double));//poczatek kolejki (staly)
     kolejka->tab_k=kolejka->tab+n;//koniec kolejki+1 (staly)
     kolejka->poczkol=kolejka->tab;//pierwsza wartosc kolejki
     kolejka->konkol=kolejka->poczkol;//wskaznik na ostatnia wartosc kolejki+1 (miejsce w ktore nowa wartosc sie wpisuje)
     return kolejka;
}

void dodaj(kolejka_T* kolejka, double num){

 // ilosc elementow kolejki
    int n=kolejka->tab_k-kolejka->tab;

//jezeli jakis element byl pobrany (z lewej)
    if(k>0)
    {
        *(kolejka->poczkol-1)=num;
       kolejka->poczkol--;
       k--;
    }else{
       if(kolejka->konkol!=kolejka->tab_k){ //jezeli jest jeszcze miejsce w kolejce (z prawej strony)
          *(kolejka->konkol)=num;
           kolejka->konkol++;
         }
       else { //jezeli miejsce sie skonczy (z prawej strony)
         realloc_kolejka(kolejka,n);
         *(kolejka->konkol)=num;
           kolejka->konkol++;
       }

    }

}


//pobieranie elementu z kolejki
void pobierz(kolejka_T* kolejka){
    *(kolejka->poczkol)=0;
    kolejka->poczkol++; //przesuwanie wskaznika pierwszej wartosci w kolejce
    k++; // ilosc eelementow usunietych

}

//oproznianie kolejki
void oproznij(kolejka_T* kolejka){

 kolejka->konkol=kolejka->poczkol;

}

//sprawdzanie czy kolejka jest pusta
bool czy_pusta(kolejka_T* kolejka){
if(kolejka->konkol==kolejka->poczkol) return true;
return false;
}

//poszerzanie kolejki
void realloc_kolejka(kolejka_T* kolejka, int n){

int pocz_temp=kolejka->tab-kolejka->poczkol;
int kon_temp=kolejka->tab-kolejka->konkol;

kolejka->tab=realloc(kolejka->tab, 2*n*sizeof(double));
kolejka->tab_k=kolejka->tab+2*n;

kolejka->poczkol=kolejka->tab-pocz_temp;
kolejka->konkol=kolejka->tab-kon_temp;

}
