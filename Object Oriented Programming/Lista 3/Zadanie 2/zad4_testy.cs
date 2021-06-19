using wektory;
using System;

class Zad4
{
    static void Main(){


       float[] wartosci1 = new float[] { 1, 2, 3, };
       float[] wartosci2 = new float[] {4.2F, 8.123F, 15F};

    wektor wektor1 = new wektor(wartosci1);
    wektor wektor2 = new wektor(wartosci2);
    wektor1.wypisz();
    wektor2.wypisz();
    wektor1*=2;
    wektor1.wypisz();
    wektor1+=wektor2;
    wektor1.wypisz();
    Console.WriteLine("Iloczyn wektorow: {0} ", wektor1*wektor2);





    }
}