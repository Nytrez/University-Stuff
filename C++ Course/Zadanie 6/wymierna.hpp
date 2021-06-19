#include <iostream>
#include <climits>
#include <vector>

namespace obliczenia
{
    int NWD(int a, int b); //funkcja pomocnicza do znajdywania Najwiekszego Wspolnego Dzielnika 

    class Wymierna
    {
    public:
        int mianownik;
        int licznik;
        void skracanie(); //funkcja sluzaca skracaniu ulamkow do najprostszej formy (korzystajac z NWD)

        Wymierna(int licz, int min); // tworzenie ulamka licz/mian
        Wymierna(int licz);          // tworzenie liczby calkowitej licz/1

        friend Wymierna operator-(Wymierna a);                           // a*=-1
        friend Wymierna operator!(Wymierna a);                           // a^(-1) - > p/q -> q/p
        friend Wymierna operator+(const Wymierna &a, const Wymierna &b); // a + b
        friend Wymierna operator-(const Wymierna &a, const Wymierna &b); // a - b
        friend Wymierna operator*(const Wymierna &a, const Wymierna &b); // a * b
        friend Wymierna operator/(const Wymierna &a, const Wymierna &b); // a / b

        Wymierna &operator+=(const Wymierna &x); // this +=x
        Wymierna &operator-=(const Wymierna &x); // this -= x
        Wymierna &operator*=(const Wymierna &x); // this *= x
        Wymierna &operator/=(const Wymierna &x); // this /= x

        operator double(); // zwracabue liczbyy postacji p/q na double (1/2 -> 0.5)
        operator int();    // zwracany liczby postaci p/q na int (przyblizony)

        friend std::ostream &operator<<(std::ostream &output, const Wymierna &x);
    };
}
