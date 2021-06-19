#include <stdio.h>
#include <stdlib.h>
#define MAX 1002

void czytaj(int rozmiar, long int w[]);
void odejmowanie(int y, long int *a, long int *b, long int *w);
void dodawanie(int y, long int *a, long int *b, long int *w);
void mnozenie(int y, long int *a, long int *b, long int *w,int h);
void pierw(int dl,long int *a, long int *b);
int zamien(int a, int b);


int main()
{
    long int w[MAX]={0},a[MAX]={0},b[MAX]={0};
    a[0]=10;
    char c;
    int i=1,y,dl[2];

    scanf("%c",&c);

    if(c=='+'){

            scanf("%Ld",&dl[0]);
            czytaj(dl[0],&a);

            scanf("%Ld",&dl[1]);
            czytaj(dl[1],&b);

            y=zamien(dl[1],dl[0]);
            dodawanie(y,&a,&b,&w);



    }else if(c=='-'){
            scanf("%Ld",&dl[0]);
            czytaj(dl[0],&a);

            scanf("%Ld",&dl[1]);
            czytaj(dl[1],&b);

            y=zamien(dl[1],dl[0]);
            odejmowanie(y,&a,&b,&w);

    }else if(c=='*'){
            scanf("%Ld",&dl[0]);
            czytaj(dl[0],&a);

            scanf("%Ld",&dl[1]);
            czytaj(dl[1],&b);

            y=zamien(dl[1],dl[0]);
            int h=dl[1]+dl[0];
            printf("%d ",h);
            mnozenie(y,&a,&b,&w,h);

    }else if(c=='p'){
            scanf("%Ld",&dl[0]);
            czytaj(dl[0],&a);
            pierw(dl[0],&a,&b);

    }else printf("bledny znak operacji");

    return 0;
}

void odejmowanie(int y, long int *a, long int *b, long int *w){
          if(a[y]!=b[y]){

            }else { y=y-1;
                for(int h=y;h>=0;h--)
                {
                    if(a[y]!=b[y]){h=-1;}
                    else {y=y-1;}
                }
            }
            if(y<0){printf("0 0");}else{
            printf("%Ld ", y);
             for(int z=0;z<=y;z++){
                w[z]=a[z]-b[z];
                printf("%Ld ",w[z]);
            }
            }
}

void dodawanie(int y, long int *a, long int *b, long int *w)
{
               printf("%d ",y);
                for(int z=0;z<=y;z++){
                w[z]=a[z]+b[z];
                printf("%Ld ",w[z]);
}
}

void mnozenie(int y, long int *a, long int *b, long int *w,int h){

          for(int i=0;i<=y;i++)
            {
                for(int j=0;j<=y;j++)
                {
                    w[i+j]=w[i+j]+a[i]*b[j];
                }
            }

                for(int z=0;z<=h;z++){
                printf("%Ld ",w[z]);
            }
}

void czytaj(int stopien, long int *x){


        for (int i=0;i<=stopien;i++){

            scanf("%Ld",&x[i]);

            }

}

void pierw(int dl,long int *a, long int *b)
{
    int licz=0,pot=1;
    long int wynik=0;
    if(a[0]==0){printf("0");}else{
    for(int i=a[0]*-1;i<=a[0];i++)
    {
        if(i==0){}else if(a[0]%i==0)
        {
            b[licz]=i;
            licz++;

    }
    }
        for(int o=0;o<2*licz;o++)
        {
            for(int c=0; c<=dl;c++)
            {
                wynik=wynik+a[c]*pot;
                pot=pot*b[o];
            }
            if(wynik==0) printf("%d ",b[o]);
            wynik=0;
            pot=1;
        }
    }

}



int zamien(int a, int b)
{
     int y;
                    if(a>b){y=a;}
                    else {y=b;}

            return y;
}
