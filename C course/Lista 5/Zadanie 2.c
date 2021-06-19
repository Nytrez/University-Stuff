#include <stdio.h>
#include <stdlib.h>

void kwadrat(int n,int kwdr[n][n],int wolne[n*n], int Mag,int sumka,int wier,int kol,int *licz,int k);

int main(int argc,char *argv[])
{
    if (argc<3)
    {
        printf("brak argumentow\n");
        return 1;
    }
    int n=atoi(argv[1]);
    int k=atoi(argv[2]);
    int kwdr[n][n];
    int wolne[n*n];
    for(int i=0;i<n*n;i++)
    {
        wolne[i]=0;
    }
    int p=0;
    int Mag=(n*(n*n+1)/2);

    kwadrat(n,kwdr,wolne,Mag,Mag,0,0,&p,k);
    return 0;
}

void kwadrat(int n,int kwdr[n][n],int wolne[n*n],int Mag,int sumka,int wier,int kol,int *licz,int k)
{
    if(*licz>=k)return;
    if (wier!=n)
    {
        if (kol!=n)
        {
            for (int i=n*n-1;i>=0;i--)
            {
                if (wolne[i]!=1)
                {
                    wolne[i] = 1;
                    kwdr[wier][kol]=i+1;
                    kwadrat(n,kwdr,wolne, Mag, sumka-kwdr[wier][kol],wier,kol+1,licz,k);
                    wolne[i] = 0;
                }
            }
        }
        else
        {
            if (sumka != 0) return;
            kwadrat(n,kwdr,wolne,Mag,Mag,wier+1,0,licz,k);
        }
    }
    else
    {
        for (int i=0;i<n;i++)
        {
            sumka = Mag;
            for (int j=0;j<n;j++)
                sumka-=kwdr[j][i];
            if (sumka!=0)return;
        }
        sumka = Mag;
        for (int j=0;j<n;j++)
            sumka-=kwdr[j][j];
        if (sumka!=0)return;
        sumka = Mag;
        for (int j=0;j<n;j++)
            sumka-=kwdr[j][n-j-1];
        if (sumka!=0)return;

        *licz=*licz+1;
        for (int x=0;x<n;x++)
        {
            for (int y=0;y<n;y++)
            {
                printf("%d ",kwdr[x][y]);
            }
            putchar('\n');
        }
        putchar('\n');
    }
}
