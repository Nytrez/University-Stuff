#include <stdio.h>
#include "zad2.c"

int main()
{
    fraction *f;
    f = new_fraction(-1, 8);
    printf("\n ulamek pierwszy %d/%d ", f->numeral, f->denominator);

    fraction *g;
    g = new_fraction(-3, -8);
    printf("\n ulamek drugi %d/%d  \n", g->numeral, g->denominator);


    printf("\n uulamki uzywajac metody zwracania wskaznika  \n");
    fraction *result;
    result = addition(f, g);
    printf("\n ulamki po dodaniu %d/%d ", result->numeral, result->denominator);

    result = substraction(f, g);
    printf("\n ulamki po odjeciu %d/%d ", result->numeral, result->denominator);
   
    
    result =multiplication(f, g);
    printf("\n ulamki po wymnozeniu %d/%d ", result->numeral, result->denominator);
 
    
    result = division(f, g);
    printf("\n ulamki po podzieleniu %d/%d ", result->numeral, result->denominator);


    printf("\n\n ulamki uzywajac metody modyfikacji drugiego skladnika  \n");

     addition2(f,g);
     printf("\n drugi skladnik %d/%d ", g->numeral, g->denominator);

     substraction2(f,g);
     printf("\n drugi skladnik %d/%d ", g->numeral, g->denominator);

     multiplication2(f,g);
     printf("\n drugi skladnik %d/%d ", g->numeral, g->denominator);

     division2(f,g);
     printf("\n drugi skladnik %d/%d ", g->numeral, g->denominator);

    return 0;
}