#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct wektor
{
    long long int *tab;
    int vsize, n;

} wektor;
wektor lvl,korzen, drzewo;

void konst(wektor *wektor);
int szukaj_LCA(int s, int t);
void cofnij(int x, wektor *wektor);
long long int wart(int poz, wektor *wektor);

int main()
{
    konst(&lvl);
    konst(&korzen);
    konst(&drzewo);
    long long int v = 0;
    int poz = -1, potrz = 1, lvl_nr = 0, poz_w = 1, next_poz_w = 0;
    int stworz_drzewo =1;

    while(stworz_drzewo)
    {
        int w=1;
        for(int k=0;k<20;k++)
        {
            w=w*2;
        }
        scanf("%lld", &v);
        cofnij(v, &drzewo);
        cofnij(lvl_nr, &lvl);

        if(potrz == 0)
        {
            poz++;
            while(poz < (drzewo).n && wart(poz, &drzewo) == -1) poz++;
            potrz = 2;
        }

        cofnij(poz, &korzen);
        potrz--;
        poz_w--;
        
        if(v != -1)
        {
            next_poz_w += 2;
        }
        if(poz_w == 0)
        {
            poz_w = next_poz_w;
            next_poz_w = 0;
            lvl_nr++;
            if(poz_w == 0)
            {
                stworz_drzewo = false;
            }
        }
    }

    long long int s = 0, t = 0;

    while(scanf("%lld", &s) == 1)
    {
        scanf("%lld", &t);
        long long int ps = 0, pt = 0;
        for(int i = 0; i < (drzewo).n; i++)
        {
            if(wart(i, &drzewo) == s)
            {
                ps = i;
            }
            if(wart(i, &drzewo) == t)
            {
                pt = i;
            }
        }
       int LCA = szukaj_LCA(ps, pt);
        printf("%lld ", wart(ps, &lvl) + wart(pt, &lvl) - 2*wart(LCA,&lvl) );
    }

    printf("\n");
    return 0;

}

long long int wart(int poz, wektor *wektor)
{
    return (*wektor).tab[poz];
}


void cofnij(int x, wektor *wektor)
{
    if((*wektor).n == (*wektor).vsize)
    {
        (*wektor).vsize *= 2;
        long long int *temp = malloc((*wektor).vsize * sizeof(long long int));
        for(int i = 0; i < (*wektor).n; i++)
        {
            temp[i] = (*wektor).tab[i];
        }

        free((*wektor).tab);
        (*wektor).tab = temp;
    }
    (*wektor).tab[(*wektor).n++] = x;
}


int szukaj_LCA(int s, int t)
{
    if(wart(s, &lvl) < wart(t, &lvl))
    {
        int hel = s;
        s= t;
        t= hel;
    }
    while(wart(s, &lvl) > wart(t, &lvl))
    {
        s = wart(s, &korzen);
    }
    while(s != t)
    {
        s = wart(s, &korzen);
        t = wart(t, &korzen);
    }
    return s;
}


void konst(wektor *wektor)
{
    (*wektor).vsize = 1;
    (*wektor).n =0;
    (*wektor).tab =malloc((*wektor).vsize*sizeof(wektor));
}