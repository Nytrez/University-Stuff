using System;

namespace wektory
{
    public class wektor
    {
        public float[] wartosci;

        public wektor(float[] tablica)
        {
            wartosci = (float[])tablica.Clone();
        }

        public void wypisz()
        {
            for (int i = 0; i < this.wartosci.Length; i++)
            {
                Console.Write("{0} ", wartosci[i]);
            }

            Console.WriteLine();
        }

        public static wektor operator *(wektor a, float wartosc)
        {
            for (int i = 0; i < a.wartosci.Length; i++)
            {
                a.wartosci[i] *= wartosc;
            }

            return a;
        }

        public static float operator *(wektor a, wektor b)
        {
            if (a.wartosci.Length != b.wartosci.Length)
            {
                Console.WriteLine("niepoprawne dlugosci wektorow!");

                return 0;
            }

            float iloczyn = 0;

            for (int i = 0; i < a.wartosci.Length; i++)
            {
                iloczyn += a.wartosci[i] * b.wartosci[i];
            }

            return iloczyn;
        }


        public static wektor operator +(wektor a, wektor b)
        {
            if (a.wartosci.Length != b.wartosci.Length)
            {
                return a;
            }
            for (int i = 0; i < a.wartosci.Length; i++)
            {
                a.wartosci[i] += b.wartosci[i];
            }

            return a;
        }


        public float norma()
        {
            float[] tab_pom;
            tab_pom = (float[])this.wartosci.Clone();
            wektor pom = new wektor(tab_pom);
            float val = (float)Math.Sqrt(this * this);
            return val;
        }

    }
}



