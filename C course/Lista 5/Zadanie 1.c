#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool nast_perm(int n, int t[]);

int main(int argc, char *argv[])
{
    int n=atoi(argv[1]),tab[n];

    for(int i=n-1;i>=0;i--)
    {
        tab[i]=n-i;
    }

do
{
  for(int i=0;i<n;i++)
    {
        printf("%d",tab[i]);
    }
 printf("\n");

}while(nast_perm(n,tab)==true);

    return 0;
}

bool nast_perm(int n,int tab[]){

    int koniec=0;

    for(int i=0;i<n;i++){
        if(tab[i]==i+1){koniec++;}
    }
    if(koniec==n){return false;}

    if(tab[n-1]==n){
        if(nast_perm(n-1,tab)==true){
            for(int i=n-1;i>0;i--){
                tab[i]=tab[i-1];
            }
           tab[0]=n;
        }
        return true;
    }
    int temp;
    for(int i=0;i<n;i++){
        if(tab[i]==n){
            temp=tab[i+1];
            tab[i+1]=tab[i];
            tab[i]=temp;
            break;
        }
    }
    return true;
}
