#include "wymierna.hpp"

namespace obliczenia
{
    int NWD(int a, int b)
    {
        int reszta = a % b;

        if (reszta == 0)
            return b;

        return NWD(b, reszta);
    }

    void Wymierna::skracanie()
    {
        int licznik_tmp = this->licznik;
        int mianownik_tmp = this->mianownik;
        int nwd = NWD(licznik_tmp, mianownik_tmp);

        licznik_tmp = licznik_tmp / nwd;
        mianownik_tmp = mianownik_tmp / nwd;

        if (mianownik_tmp < 0)
        {
            licznik_tmp *= (-1);
            mianownik_tmp *= (-1);
        }

        this->licznik = licznik_tmp;
        this->mianownik = mianownik_tmp;
    }

    Wymierna::Wymierna(int licz, int mian) // tworzenie liczby licz/mian
    {
        if (mian == 0)
            throw "dzielenie przez 0!";

        this->licznik = licz;
        this->mianownik = mian;
        skracanie(); //skracamy do najprostszej postaci
    }

    Wymierna::Wymierna(int licz) // tworzenie liczby licz/1
    {
        this->licznik = licz;
        this->mianownik = 1;
    }

    Wymierna operator-(Wymierna a) // zamiana a na -a
    {
        a.licznik = a.licznik * (-1);
        return a;
    }

    Wymierna operator!(Wymierna a) // zamiana a na 1/a
    {
        if (a.licznik == 0)
            throw "dzielenie przez 0!";

        int temp = a.licznik;
        a.licznik = a.mianownik;
        a.mianownik = temp;
        
        a.skracanie();
        return a;
    }

    Wymierna operator+(const Wymierna &a, const Wymierna &b) // a + b
    {
        long long int mian_tmp = a.licznik * b.mianownik + b.licznik * a.mianownik;
        long long int licz_tmp = a.mianownik * b.mianownik;

        if (mian_tmp > INT_MAX || mian_tmp < INT_MIN || licz_tmp > INT_MAX || licz_tmp < INT_MIN)
            throw "liczba poza zakresem!";

        Wymierna result(a.licznik * b.mianownik + b.licznik * a.mianownik,
                        a.mianownik * b.mianownik);
        
        return result;
    }

    Wymierna operator-(const Wymierna &a, const Wymierna &b) // a - b
    {
        long long int mian_tmp = a.licznik * b.mianownik - b.licznik * a.mianownik;
        long long int licz_tmp = a.mianownik * b.mianownik;

        if (mian_tmp > INT_MAX || mian_tmp < INT_MIN || licz_tmp > INT_MAX || licz_tmp < INT_MIN)
            throw "liczba poza zakresem!";

        Wymierna result(a.licznik * b.mianownik - b.licznik * a.mianownik,
                        a.mianownik * b.mianownik);

       
        return result;
    }

    Wymierna operator*(const Wymierna &a, const Wymierna &b) // a * b
    {
        long long int mian_tmp = a.licznik * b.licznik;
        long long int licz_tmp = a.mianownik * b.mianownik;
        
        if (mian_tmp > INT_MAX || mian_tmp < INT_MIN || licz_tmp > INT_MAX || licz_tmp < INT_MIN)
            throw "liczba poza zakresem!";

        Wymierna result(a.licznik * b.licznik, a.mianownik * b.mianownik);
        
        
        return result;
    }

    Wymierna operator/(const Wymierna &a, const Wymierna &b) // a / b
    {
        if (b.licznik == 0)
            throw "dzielenie przez 0!";

        long long int mian_tmp = a.licznik * b.mianownik;
        long long int licz_tmp = a.mianownik * b.licznik;

        if (mian_tmp > INT_MAX || mian_tmp < INT_MIN || licz_tmp > INT_MAX || licz_tmp < INT_MIN)
            throw "liczba poza zakresem!";

        Wymierna result(a.licznik * b.mianownik, a.mianownik * b.licznik);

        
        return result;
    }

    Wymierna &Wymierna::operator+=(const Wymierna &x) // this += x
    {
        long long int mian_tmp = this->licznik * x.mianownik + x.licznik * this->mianownik;
        long long int licz_tmp = this->mianownik * x.mianownik;

        if (mian_tmp > INT_MAX || mian_tmp < INT_MIN || licz_tmp > INT_MAX || licz_tmp < INT_MIN)
            throw "liczba poza zakresem!";

        this->licznik = this->licznik * x.mianownik + x.licznik * this->mianownik;
        this->mianownik = this->mianownik * x.mianownik;

        skracanie();
        return *this;
    }

    Wymierna &Wymierna::operator-=(const Wymierna &x) // this -= x
    {
        long long int mian_tmp = this->licznik * x.mianownik - x.licznik * this->mianownik;
        long long int licz_tmp = this->mianownik * x.mianownik;

        if (mian_tmp > INT_MAX || mian_tmp < INT_MIN || licz_tmp > INT_MAX || licz_tmp < INT_MIN)
            throw "liczba poza zakresem!";

        this->licznik = this->licznik * x.mianownik - x.licznik * this->mianownik;
        this->mianownik = this->mianownik * x.mianownik;

        skracanie();
        return *this;
    }

    Wymierna &Wymierna::operator*=(const Wymierna &x) // this *= x
    {
        long long int mian_tmp = this->licznik * x.licznik;
        long long int licz_tmp = this->mianownik * x.mianownik;

        if (mian_tmp > INT_MAX || mian_tmp < INT_MIN || licz_tmp > INT_MAX || licz_tmp < INT_MIN)
            throw "liczba poza zakresem!";

        this->licznik = this->licznik * x.licznik;
        this->mianownik = this->mianownik * x.mianownik;

        skracanie();
        return *this;
    }

    Wymierna &Wymierna::operator/=(const Wymierna &x) // this /= x
    {
        if (x.licznik == 0)
            throw "dzielenie przez 0!";

        long long int mian_tmp = this->licznik * x.mianownik;
        long long int licz_tmp = this->mianownik * x.licznik;

        if (mian_tmp > INT_MAX || mian_tmp < INT_MIN || licz_tmp > INT_MAX || licz_tmp < INT_MIN)
            throw "liczba poza zakresem!";

        this->licznik = this->licznik * x.mianownik;
        this->mianownik = this->mianownik * x.licznik;

        skracanie();
        return *this;
    }

    Wymierna::operator double()
    {
        return (double)this->licznik / this->mianownik;
    }

    Wymierna::operator int()
    {
        return this->licznik / this->mianownik;
    }

    std::ostream &operator<<(std::ostream &output, const obliczenia::Wymierna &x)
    {
        std::vector<int> reszty_tmp;
        std::vector<int> wynik;

        unsigned int i, j;
        int reszta;

        reszta = x.licznik % x.mianownik;
        if (reszta == 0)
        {
            output << x.licznik / x.mianownik;
            return output;
        }

        if (reszta < 0)
            reszta *= (-1);

        reszty_tmp.push_back(reszta);

        // musialem wyodrebnic na ujemny i dodatni bo gdy bylo samo output << x.licznik/x.mianownik 
        // to dzialalo z wyjatkiem gdy wynik byl ujemny ale przyblizal sie do 0 wtedy do outputu dodawalismy 0 zamiast -0
        if ((x.licznik < 0 && x.mianownik > 0) || (x.licznik >= 0 && x.mianownik < 0))
        {
            output << "-"; //specjalnie dla momentu gdy wynik przybliza sie do 0
            output << -1 * x.licznik / x.mianownik; //usuniecie zbednego "-"
        }
        else
        {
            output << x.licznik / x.mianownik;
        }

        while (true)
        {
            wynik.push_back(reszta * 10 / x.mianownik); //dodajemy inty
            reszta = reszta * 10 % x.mianownik;

            if (reszta == 0) // liczba nie ma nieskonczonego rozwiniecia
            {
                output << ".";
                for (i = 0; i < wynik.size(); i++) //wiec dodajemy kropke i caly wynik z naszego wektora
                    output << wynik[i];
                return output;
            }

            for (j = 0; j < reszty_tmp.size(); j++) // rozwiniecie zaczyna sie powtarzac
            {
                if (reszta == reszty_tmp[j])
                {
                    output << ".";
                    for (i = 0; i < j; i++)
                        output << wynik[i];

                    output << "(";
                    for (i = j; i < wynik.size(); i++)
                    {
                        output << wynik[i];
                    }
                    output << ")";

                    return output;
                }
            }
            reszty_tmp.push_back(reszta);
        }
    }
}