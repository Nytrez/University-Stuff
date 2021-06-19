#include <limits.h>
#include <stdbool.h>
#include <stdio.h>


#define MAX_SET_SIZE 8000

typedef int Zbior[MAX_SET_SIZE+1];

void zerow(Zbior a);
bool czytajZbior( Zbior a);
void wypiszZbior(const  Zbior a);
void sumaZbiorow(Zbior a,Zbior b, Zbior razem);
void roznicasym(Zbior rsym);
void dodawanie(Zbior razem,int a);
int usuwanie(Zbior razem,int a);

