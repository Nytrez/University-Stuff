#include <stdio.h>
#include <stdlib.h>
#include "zbiory.h"


int main()
{
    Zbior a,b,razem,rsym;
    int el;

    printf("Podaj zbior A: ");
    if(!czytajZbior(a)){return 0;}
    printf("Podaj zbior B: ");
    if(!czytajZbior(b)){return 0;}

    printf("\n");

    printf("Zbior A:\n");
    wypiszZbior(a);
    printf("\nZbior B:\n");
    wypiszZbior(b);

    printf("\nRoznica symetryczna zbiorow A i B:\n");
    sumaZbiorow(a,b,rsym);
    roznicasym(rsym);
    wypiszZbior(rsym);


    printf("\nSuma zbiorow A i B:\n");
    sumaZbiorow(a,b,razem);
    usuwanieDup(razem);
    wypiszZbior(razem);


    printf("\nDodaj element do A+B: ");
    scanf("%d",&el);
    dodawanie(razem,el);
    wypiszZbior(razem);

    printf("\n");

    printf("Wpisz element ktory chcesz usunac: ");
    scanf("%d",&el);
    if(usuwanie(razem,el)==1){
    wypiszZbior(razem);}
    else{printf("\nelement nie wystepuje w zbiorze\n");}

    zerow(razem);

    return 0;
}
