#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "modul.h"


int cmpfunc (const void * a, const void * b);
void wstawianie(double tab[], int n);
void selectsort(double tab[], int n);
void algorytmy();

int main()
{
    int n;
    printf("Podaj dlugosc testowej tablicy do posortowania: ");
    scanf("%d", &n);

    //alokacja pamieci dla tablicy
    double* tab = malloc(n*sizeof(double));
    double* tabs = malloc(n*sizeof(double));

    //wypelnienie tablicy
    generator(n,tab);

    for(int i=0; i<n; i++)
        tabs[i]=tab[i];

   selectsort(tab,n);

    //wyslanie do funkcji tablicy posortowanej i nie posortowanej
    if(sprawdzanie(tab, tabs, n)==true){
            printf("\nprawidlowo posortowane \n");
    }
    else {
            printf("\nnie prawidlowo posortowane \n");
    }

    algorytmy();
    return 0;
}


void algorytmy()
{
    //definiowanie licznikow czasu dla kazdego testu i algorytmu;
    double cz1[100],cz2[100],cz3[100];
    clock_t start_t, end_t; //start i koniec zmiennych liczenia czasu
    int licz[3]={5000,10000,50000}; //wielkosci danych
    double tablica[50000],t1[50000],t2[50000],t3[50000]; //pierwsza tablica raz generowana a kolejne 3 tablice w kazdym obrocie petli pobieraja dane z pierwszej tablicy
     //wypelnienie glownej tablicy

    for(int y=0;y<3;y++){ //zmiana wielkosci danych
        int rozmiar=licz[y];

    for(int i=0;i<100;i++) //testy
    {
        generator(rozmiar,tablica); //generowanie nowej tablicy matki z danymi

        for(int j=0;j<rozmiar;j++) //wypelnienie tablic nie posortowanymi danymi
        {
            t1[j]=tablica[j];
            t2[j]=tablica[j];
            t3[j]=tablica[j];
        }

        start_t = clock();  //start licznika
        insertsort(t1,rozmiar);
        end_t = clock(); //koniec licznika
        cz1[i] = (double)(end_t-start_t) / CLOCKS_PER_SEC; //obliczenie ilosci sekund

        start_t = clock();
        selectsort(t2, rozmiar);
        end_t = clock();
        cz2[i] = (double)(end_t-start_t) / CLOCKS_PER_SEC;

        start_t = clock();
        qsort(t3,rozmiar,sizeof(double),cmpfunc);
        end_t = clock();
        cz3[i] = (double)(end_t-start_t) / CLOCKS_PER_SEC;


    }

     printf("\nCzas algorytmow sortowania dla danych o rozmiarze %d:\n",rozmiar);
     printf("\nSortowanie przez wybieranie:");
     czas(cz2,0,100);
     printf("\nSortowanie przez wstawianie:");
     czas(cz1,0,100);
     printf("\nSortowanie uzywajac funkcji qsort:");
     czas(cz3,0,100);
    }

}

int cmpfunc (const void * a, const void * b) //funkcja pomocna do qsort
{
    return ( *(double*)a - *(double*)b );
}



void insertsort(double tab[], int n) //sortowanie przez wstawianie
{
    for(int j = n - 2; j >= 0; j--)
    {
        double x = tab[j];
        int i = j + 1;
        while((i < n) && (x > tab[i]))
        {
            tab[i - 1] = tab[i];
            i++;
        }
        tab[i - 1] = x;
    }
}

void selectsort(double tab[], int n) //sortowanie poprzez wybieranie
{
    double tmp;
    int pmin;
    for(int j = 0; j < n - 1; j++)
    {
        pmin = j;
        for(int i = j + 1; i < n; i++)
            if(tab[i] < tab[pmin]) pmin = i;
        {
            tmp=tab[j];
            tab[j]=tab[pmin];
            tab[pmin]=tmp;
        }
    }
}




