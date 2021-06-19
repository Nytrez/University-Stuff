#include <limits.h>
#include <stdbool.h>

typedef struct KOLEJKA_STRUCT{
  double* poczkol;
  double* konkol;
  double* tab;
  double* tab_k;

  }kolejka_T;

    kolejka_T* strt_kolejka(int n);
    void oproznij(kolejka_T* queue);
    bool czy_pusta(kolejka_T* queue);
    void dodaj(kolejka_T* queue,double num);
    void pobierz(kolejka_T* queue);
    void realloc_kolejka(kolejka_T* queue,int n);


