#include "licz.h"
#include <stdio.h>
#include <limits.h>



void czytaj(int *a, int *b) {
    printf("Licznik: ");
    scanf("%d", a);

    printf("Mianownik: ");
    scanf("%d", b);
}


wymierna stworz(int licz, int mian){
    int neg = 0;
    if((licz < 0 && mian > 0) || (licz >=0 && mian < 0)) {
        neg = 1;
    }

    if(licz < 0) {
        licz *= -1;
    }
    if(mian < 0) {
        mian *= -1;
    }

    if(mian == 0) {
        return 0;
    }

    int n = licz/nwd(licz, mian);
    int m = mian/nwd(licz, mian);

    if(neg == 1) {
        n *= -1;
    }
    wymierna w = n;
    w <<= 32;
    w |= m;

    return w;
}

void wypisz(wymierna zesp) {
    wymierna licz = licznik(zesp);
    wymierna mian = mianownik(zesp);
    printf("%lld/%lld\n", licz, mian);
}

wymierna dodaj(wymierna a, wymierna b) {
    wymierna liczA = licznik(a);
    wymierna mianA = mianownik(a);

    wymierna liczB = licznik(b);
    wymierna mianB = mianownik(b);

    if(liczA*mianB + liczB*mianA > INT_MAX || mianA*mianB > INT_MAX || liczA*mianB + liczB*mianA <  INT_MIN || mianA*mianB < INT_MIN) {
        return 0;
    }

    int licz = liczA*mianB + liczB*mianA;
    int mian = mianA*mianB;

    int l = licz/nwd(licz, mian);
    int m = mian/nwd(licz, mian);

    wymierna suma = stworz(l,m);
    return suma;
}

wymierna odejmowanie(wymierna a, wymierna b) {
    wymierna liczA = licznik(a);
    wymierna mianA = mianownik(a);

    wymierna liczB = licznik(b);
    wymierna mianB = mianownik(b);

    if(mianA*mianB > INT_MAX || mianA*mianB<INT_MIN) {
        return 0;
    }
    int licz = liczA*mianB - liczB*mianA;
    int mian = mianA*mianB;

    int l = licz/nwd(licz, mian);
    int m = mian/nwd(licz, mian);


    wymierna diff = stworz(l,m);
    return diff;
}

wymierna mnoz(wymierna a, wymierna b) {
    wymierna liczA = licznik(a);
    wymierna mianA = mianownik(a);

    wymierna liczB = licznik(b);
    wymierna mianB = mianownik(b);

    if(liczA*liczB > INT_MAX||mianA*mianB > INT_MAX || liczA*liczB < INT_MIN||mianA*mianB < INT_MIN) {
        return 0;
    }

    int licz = liczA*liczB;
    int mian = mianA*mianB;

    int l = licz/nwd(licz, mian);
    int m = mian/nwd(licz, mian);


    wymierna mnozi = stworz(l, m);
    return mnozi;
}

wymierna dziel(wymierna a, wymierna b) {
    wymierna liczA = licznik(a);
    wymierna mianA = mianownik(a);

    wymierna liczB = licznik(b);
    wymierna mianB = mianownik(b);

    if(liczA*liczB > INT_MAX||mianA*mianB > INT_MAX || liczA*liczB < INT_MIN||mianA*mianB < INT_MIN) {
        return 0;
    }

    int licz = liczA*mianB;
    int mian = mianA*liczB;

    int l = licz/nwd(licz, mian);
    int m = mian/nwd(licz, mian);


    wymierna dzieli = stworz(l, m);
    return dzieli;
}

int nwd(int a,int b) {
    if(a < 0) {
        a *= -1;
    }
    if(b<0){
        b *= -1;
    }
    if(b>0) {
        return nwd(b,a%b);
    }
    return a;
}

wymierna licznik(wymierna zesp) {
    wymierna licz = zesp >> 32;
    return licz;
}

wymierna mianownik(wymierna zesp) {
    wymierna mian = zesp & ((1ull << 32u)-1u);
    return mian;
}
