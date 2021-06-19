using System.Collections;

// Przestrzeñ nazw Primes
namespace Liczby_Pierwsze
{

    public class PrimeCollection : IEnumerable
    {
        // implementacja iteratora
        public class PrimeEnumerator : IEnumerator
        {
            // aktualny element, kolekcji
            int current;

            // sprawdzanie czy jest liczba pierwsza
            private bool IsPrime()
            {            
                if (this.current % 2 == 0 && this.current != 2)
                    return false;

                for (int i = 3; i <= (int)System.Math.Sqrt(this.current); i += 2)
                    if (this.current % i == 0)
                        return false;

                return true;
            }

            // wymagane przez interfejs, petla wykonuje sie az znajdzie liczbe pierwsze, i zwaraca prawde
            // jezeli przekroczymy zakres zwaraca falsz
            public bool MoveNext()
            {
                this.current++;

                while (!IsPrime())
                {
                    if (this.current >= System.Int32.MaxValue)
                        return false;
                    this.current++;
                }

                return true;
            }

            // wymagane przez interfejs
            public void Reset()
            {
                this.current = 1;
            }


            // wymagane przez interfejs.
            object IEnumerator.Current
            {
                get { return Current; }
            }

            

            // dostep do aktualnego elementu
            public int Current
            {
                get { return this.current; }
            }
        }

        // konstruktor kolekcji
        public PrimeCollection() {}

        // wymagane przez interfejs, zwraca iterator
        IEnumerator IEnumerable.GetEnumerator()
        {
            return (IEnumerator)GetEnumerator();
        }

        // metoda inicjalizujaca iterator
        public PrimeEnumerator GetEnumerator()
        {
            return new PrimeEnumerator();
        }
    }

}