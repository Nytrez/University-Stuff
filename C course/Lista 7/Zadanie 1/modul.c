#include <stdio.h>
#include <stdlib.h>
#include "modul.h"

void czy_pusta(Lista lst)
{
    if(lst==NULL) printf("\nLista pusta");
    else printf("\nLista nie pusta");
}

int dlugosc_listy(Lista lst)
{
    int i=0;
    if(lst==NULL)return 0;
    Lista start=lst;
    do
    {
        i++;
        start=start->nast;
    }
    while(start!=lst);
    return i;
}

void wypisz(Lista L)
{
    Lista p=L;
    if(L!=NULL){
        do {
            printf("%.2lf ", p->info);
            p=p->nast;
        }
        while(p!=L);
        printf("\n");
    }else
     printf("pusta\n");
}

Lista stworz()
{
    Lista lst = NULL;
    return lst;
}

Lista dodaj_na_pocz(Lista lst, double info)
{
    if(lst == NULL)
    {
        Lista p=(Wezel*)malloc(sizeof(Wezel));
        if(p==NULL)return lst;
        else
        {
            Lista p=(Wezel*)malloc(sizeof(Wezel));
            if(p==NULL)return NULL;
            p->info=info;
            p->poprz=p->nast=p;
            return p;
        }

    }
    else
    {
        Lista p=(Wezel*)malloc(sizeof(Wezel));
        if(p==NULL)return NULL;
        else
        {
            p->info=lst->info;
            p->nast=lst->nast;
            p->poprz=lst;
            lst->info=info;
            lst->nast=p;
        }
    }

    return lst;
}

Lista dodaj_na_tyl(Lista lst, double info)
{
    if(lst == NULL)
    {
        Lista p=(Wezel*)malloc(sizeof(Wezel));
        if(p==NULL)return lst;
        else
        {
            Lista p=(Wezel*)malloc(sizeof(Wezel));
            if(p==NULL)return NULL;
            p->info=info;
            p->poprz=p->nast=p;
            return p;
        }

    }
    else
    {
        Lista p=(Wezel*)malloc(sizeof(Wezel));
        if(p==NULL)return NULL;
        else
        {
            p->info=info;
            p->nast=lst;
            p->poprz=lst->poprz;
            lst->poprz->nast=p;
            lst->poprz=p;
        }
    }
    return lst;
}

Lista odejmij_z_kon(Lista lst)
{
    if(lst)
    {
        if(lst==lst->poprz)return NULL;
        else
        {
            lst=lst->poprz;
            Lista nst = lst->nast;
            lst->poprz->nast = lst->nast;
            lst->nast->poprz = lst->poprz;

            free(lst);
            lst=nst;
        }
    }
    return lst;
}

Lista odejmij_z_pocz(Lista lst)
{

    if(lst)
    {
        if(lst==lst->nast)return NULL;
        else
        {
            Lista nst = lst->nast;
            lst->poprz->nast = lst->nast;
            lst->nast->poprz = lst->poprz;
            free(lst);
            lst=nst;
        }
    }
    return lst;
}

