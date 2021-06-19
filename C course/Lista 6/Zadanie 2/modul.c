#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "modul.h"



void generator(int n,double tab[])
{

    for(int i=0;i<n;i++)
    {
        tab[i]=(rand()%100);//zapelnienie tablicy liczbami z zakresu 0 do 99
    }

}


void czas(double tab[], int a, int b) //obliczenie minimalnego, sredniego i najwiekszego czasu wykonania funkcji
{

    double max = tab[a],min = tab[a],avg = tab[a];

    for(int i=a+1;i<b;i++)
    {
        if(tab[i]>max)max=tab[i];
    }
    printf("\nCzas maxymalny: %f\n",max);


    for(int i=a+1;i<b;i++)
    {
        if(tab[i]<min)min=tab[i];
    }
    printf("Czas minimalny: %f\n",min);



    for(int i=a+1;i<b;i++)
    {
        avg+=tab[i];
    }
    double sr= avg/(b-a);
    printf("Czas sredni: %f\n",sr);

}


bool sprawdzanie( double tab[], double tabs[], int n) //przeslanie posortowanej tabeli, nieposortowanej tablicy i ich rozmiaru
{
    double test[n],test2[n];

    for(int i=0; i<n; i++) { //ustawienie kopii tablic aby nie pracowac na oryginalnych tablicach
        test[i]=tabs[i];
        test2[i]=tab[i];
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(test[i]==test2[j]) //jezeli znajdzie taka sama wartosc w jednej i drugiej tablicy to ustaw je na wartosc ktorej nie moglyby miec
            {
                test[i]=101;
                test2[j]=101;

                break;
            }
        }
    }

    for(int i=0; i<n; i++)
    {
        if(test[i]!=101) return false; //sprawdzanie czy zostala jakas wartosc ktorej nie bylo w posortowanej tablicy
    }


    for(int i=0; i<n-1; i++)
        if(tab[i]>tab[i+1]) return false; //sprawdzanie czy jest posortowane niemalejaco

    return true;
}


