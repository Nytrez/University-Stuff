#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct fraction
{
    int numeral;
    int denominator;

} fraction;

fraction *new_fraction(int num, int denom)
{

    fraction *new = calloc(1, sizeof(struct fraction));

    if (denom == 0)
    {
        printf("DZIELENIE PRZEZ ZERO!!!");
        exit(0);
    }
    if (num == 0)
    {
        denom = 1;
    }
    else
    {
        int a, b, c; //nwd schematem Hornera
        if (denom < num)
        {
            a = num;
            b = denom;
        }
        else
        {
            a = denom;
            b = num;
        }
        do
        {
            c = a % b;
            a = b;
            b = c;
        } while (c != 0);

        num = num / a;
        denom = denom / a;
    }
    if (denom < 0)
    {
        num *= -1;
        denom *= -1;
    }
    new->numeral = num;
    new->denominator = denom;

    return new;
}

fraction *addition(fraction *a, fraction *b) //zwracanie wskaznika na nowy ulamek
{

    int num, denom;

    num = a->numeral * b->denominator + b->numeral * a->denominator;
    denom = a->denominator * b->denominator;

    return new_fraction(num, denom);
}

fraction *substraction(fraction *a, fraction *b) //zwracanie wskaznika na nowy ulamek
{

    int num, denom;

    num = a->numeral * b->denominator - b->numeral * a->denominator;
    denom = a->denominator * b->denominator;

    return new_fraction(num, denom);
}

fraction *multiplication(fraction *a, fraction *b) //zwracanie wskaznika na nowy ulamek
{

    int num, denom;

    num = a->numeral * b->numeral;
    denom = a->denominator * b->denominator;

    return new_fraction(num, denom);
}

fraction *division(fraction *a, fraction *b) //zwracanie wskaznika na nowy ulamek
{

    int num, denom;

    num = a->numeral * b->denominator;
    denom = a->denominator * b->numeral;

    return new_fraction(num, denom);
}

// modyfikacja drugiego skladnika
void horner(int *g, int *h)
{

    int num = *g;
    int denom = *h;

    if (denom == 0)
    {
        printf("DZIELENIE PRZEZ ZERO!!!");
        exit(0);
    }
    if (num == 0)
    {
        denom = 1;
    }
    else
    {
        int a, b, c;
        //nwd schematem Hornera
        if (denom < num)
        {
            a = num;
            b = denom;
        }
        else
        {
            a = denom;
            b = num;
        }
        do
        {
            c = a % b;
            a = b;
            b = c;
        } while (c != 0);

        denom = denom / a;
        num = num / a;
    }

    if (denom < 0)
    {
        num *= -1;
        denom *= -1;
    }

    *g = num;
    *h = denom;
}

void addition2(fraction *a, fraction *b) //zmiana drugiego skladnika
{

    int num, denom;

    num = a->numeral * b->denominator + b->numeral * a->denominator;
    denom = a->denominator * b->denominator;

    horner(&num, &denom);

    b->numeral = num;
    b->denominator = denom;
}

void substraction2(fraction *a, fraction *b) //zmiana drugiego skladnika
{

    int num, denom;

    num = a->numeral * b->denominator - b->numeral * a->denominator;
    denom = a->denominator * b->denominator;

    horner(&num, &denom);

    b->numeral = num;
    b->denominator = denom;
}

void multiplication2(fraction *a, fraction *b) //zmiana drugiego skladnika
{

    int num, denom;

    num = a->numeral * b->numeral;
    denom = a->denominator * b->denominator;

    horner(&num, &denom);

    b->numeral = num;
    b->denominator = denom;
}

void division2(fraction *a, fraction *b) //zmiana drugiego skladnika
{

    int num, denom;

    num = a->numeral * b->denominator;
    denom = a->denominator * b->numeral;

    horner(&num, &denom);

    b->numeral = num;
    b->denominator = denom;
}