#include "zbiory.h"

bool czytajZbior(Zbior a)
{

    scanf("%d",&a[0]);
    scanf("%d",&a[1]);

    for(int i=2;i<=a[0];i++)
    {

        scanf("%d",&a[i]);
        if(a[i]<a[i-1]||a[i]==a[i-1]){
                printf("\n blad, ciag nie jest rosnacy");
        return false;
        }

    }
   return true;
}

void wypiszZbior(const Zbior a)
{

    for(int i=1;i<=a[0];i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");


}

void sumaZbiorow(Zbior a,Zbior b,Zbior razem)
{
   razem[0]=a[0]+b[0];

   for(int i=1;i<=a[0];i++)
   {
       razem[i]=a[i];
   }
   for(int i=1;i<=b[0];i++)
   {
       razem[i+a[0]]=b[i];
   }

       bubbleSort(razem);
}

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void dodawanie(Zbior razem,int el)
{

    for(int i=1;i<=razem[0];i++)
    {
        if(el==razem[i]){
                printf("\n element juz wystepuje: ");
               i=razem[0]+1;
               }else if(i==razem[0]){
                   razem[razem[0]+1]=el;
                   razem[0]=razem[0]+1;
                   bubbleSort(razem);
                   i=razem[0]+1;
        }
    }


}

void bubbleSort(int ar[])
{
   for (int i = 0; i <= ar[0]; i++)

       for (int j = 1; j <= ar[0]-i-1; j++)
           if (ar[j] > ar[j+1])
              swap(&ar[j], &ar[j+1]);

}

int usuwanie(Zbior razem,int a)
{
    int y=0;

    for(int i=1;i<=razem[0];i++)
    {
        if(a==razem[i])
        {
            y=1;
            for(int j=i;j<razem[0];j++)
            {
                razem[j]=razem[j+1];
            }
            razem[0]=razem[0]-1;
            i=i-1;
        }
    }
      if(y==0){return 0;}
      else return 1;

}

void usuwanieDup(int arr[])
{

     for(int i=1; i<arr[0]; i++)
    {

            if(arr[i] == arr[i+1])
            {

                for(int k=i; k<arr[0]; k++)
                {
                    arr[k] = arr[k + 1];
                }
                arr[0]--;
                i--;
            }

    }
}


void roznicasym(Zbior rsym)
{

   for(int i=1; i<rsym[0]; i++)
    {

            if(rsym[i] == rsym[i+1])
            {
              usuwanie(rsym,rsym[i]);
              i=i-1;
            }

    }


}

void zerow(Zbior zero)
{
    zero[0]=0;
    printf("\nOproznianie zbioru A+B pomyslne, ilosc elementow zbioru to %d\n",zero[0]);
}


