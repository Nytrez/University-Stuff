#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

typedef long long int wymierna;

wymierna dziel(wymierna a, wymierna b);
wymierna mnoz(wymierna a, wymierna b);
wymierna odejmowanie(wymierna a, wymierna b);
wymierna dodaj(wymierna a, wymierna b);
wymierna mianownik(wymierna zesp);
wymierna licznik(wymierna zesp);
wymierna stworz(int licz, int mian);
void czytaj(int *a, int *b);
void wypisz(wymierna zesp);

