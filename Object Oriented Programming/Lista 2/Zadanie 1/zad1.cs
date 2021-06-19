using System;

class IntStream
{
    protected int num = 0;

    public virtual void reset()//inicjowanie strumienia od nowa
    {
        num = 0;
    }

    public virtual bool eos() //sprawdzenie czy to koniec strumienia
    {
        if (num >= int.MaxValue)
        {
            return true;
        }
        return false;
    }

    public virtual int next()//zwracanie kolejnych liczb naturalnych
    {
        if (eos())
        {
            return num;
        }
        return num++;
    }

}

class PrimeStream : IntStream
{

    public override int next()// nastepna liczba pierwsza
    {
        if (base.num < 2)//pierwsza liczba pierwsza
        {
            base.num = 2;
            return base.num;
        }

        base.next();
        while (!eos()) //szukanie kolejnej liczby pierwszej do konca strumienia
        {

            bool prime = true;

            for (int i = 2; i * i <= base.num; i++)//sprawdzenie czy liczba jest liczba pierwsza
            {
                if (base.num % i == 0)
                {
                    i = base.num;
                    prime = false;
                }
            }

            if (prime == true)
            {
                return base.num;
            }

            base.next();
        }

        return -1; //w przypadku gdy skonczy sie strumien

    }



}

class RandomStream : IntStream//zwracanie losowych liczb
{
    public override int next()
    {
        Random rand = new Random();
        return rand.Next();
    }
}

class RandomWordStream //tworzenie losowych slow o dlugosci kolejnych liczb pierwszych
{
    PrimeStream prime = new PrimeStream();
    public int length;

    public RandomWordStream()//inicjowanie 
    {
        length = prime.next();
    }

    public string next() //kolejne slowa losowe
    {
        RandomStream random = new RandomStream();
        string word = "";
        int i = 0;
        while (i < length)
        {
            char randomLetter = (char)((random.next() % 26) + 97); // losowanie litery od a - z
            word += randomLetter.ToString();
            i++;
        }
        length = prime.next();
        return word;
    }
}