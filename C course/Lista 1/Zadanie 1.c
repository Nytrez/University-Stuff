#include <stdio.h>
#include <stdlib.h>
#include <math.h>


//SZYMON SZENDZIELORZ ZADANIE 1 LISTA 1

const long double e = 2.718281828459045235360287471352662497757247093;




int granica(double z)
{

double d=(1+1/z);
double w=1;
for(double i=1;i<=z;i++)
{
    w=d*w;
}

printf("Wartosc z granicy double to %.20f \n",w);
     double r=e-w;

    printf (" Roznica double to %.20g\n\n",r);
return 0;

}



int longgranica(double z)
{

long double d=(1+1/z);
long double w=1;
for(long double i=1;i<=z;i++)
{
    w=d*w;
}

printf("Wartosc z granicy long double to %.15Lf \n",w);
     long double r=e-w;

    printf (" Roznica double to %.20Lg\n\n",r);
return 0;

}



int longdouble(double z)
{
    long double w=0;
    long double a=1;

    for(long double i=1; i<z;i++)
    {
      w=1/(i*a)+w;
      a=i*a;

    }
    w=w+1;

    printf("Wartosc long double szeregu to %.20Lf\n",w);
    long double r=w-e;
    printf (" Roznica long double szeregu to %.20Lg\n\n",r);
    return 0;
}

int onlydouble(double z)
{
    double w=0;
    double a=1;

    for(double i=1; i<z;i++)
    {
      w=1/(i*a)+w;
      a=i*a;

    }
    w=w+1;
    printf("Wartosc double szeregu to %.20f\n",w);
    double r=w-e;
    printf (" Roznica double szeregu to %.20g\n\n",r);
    return 0;
}



int main()
{
   long double eld= expl(1);
   double ed=exp(1);

    double l=1000;
    double s=1000;

    onlydouble(l);
    longdouble(l);
    granica(s);
    longgranica(s);



    printf("Wartosc double z biblioteki math.h: %.20f\n",ed);
    double r=eld-e;
    printf (" Roznica double szeregu to %.20g\n\n",r);

    printf("Wartosc long double z biblioteki math.h: %.20Lf\n",eld);
    long double h=ed-e;
    printf (" Roznica double szeregu to %.20Lg\n\n",h);



    return 0;
}
