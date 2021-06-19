#include <iostream>
#include <initializer_list>
#include <string>
#include <utility>
#include <cmath>
#include <stdexcept>

namespace obliczenia{

class tab_bit
{
    typedef uint64_t slowo; // komorka w tablicy
    static const int rozmiar_slowa = 8 * sizeof(slowo); // rozmiar slowa w bitach

    friend  std::istream& operator>>(std::istream& we, tab_bit& tab);
    friend  std::ostream&  operator<<(std::ostream& wy, const tab_bit& tab);

    class ref // klasa pomocnicza do adresowania bitów
    {
        slowo* wsk;
        int i;

    public:
        ref(int i, slowo* s);
        ref& operator=(bool wartosc);
        ref& operator=(const ref& bit);
        operator bool() const;
    };

protected:

    int dl; // liczba bitów
    slowo* bit_tab; // tablica bitów
    
public:

    explicit tab_bit(int rozm); // wyzerowana tablica bitow [0...rozm]
    explicit tab_bit(slowo tab); // tablica bitów [0...rozmiar_slowa]
    tab_bit(const std::initializer_list<int>& lista); // konstruktor z listą inicjalizacyjną
    tab_bit(const tab_bit& tab); // konstruktor kopiujący
    tab_bit(tab_bit&& tab); // konstruktor przenoszący
    tab_bit& operator=(const tab_bit& tab); // przypisanie kopiujące
    tab_bit& operator=(tab_bit&& tab); // przypisanie przenoszące
    ~tab_bit(); // destruktor

public:

    bool operator[](int i) const; // indeksowanie dla stałych tablic bitowych
    ref operator[](int i); // indeksowanie dla zwykłych tablic bitowych
    inline int rozmiar() const  {return this->dl;}; // rozmiar tablicy w bitach

public:

    tab_bit& operator|=(const tab_bit& tab);
    tab_bit& operator&=(const tab_bit& tab);
    tab_bit& operator^=(const tab_bit& tab);
    friend tab_bit operator|(const tab_bit& tab1, const tab_bit& tab2);
    friend tab_bit operator&(const tab_bit& tab1, const tab_bit& tab2);
    friend tab_bit operator^(const tab_bit& tab1, const tab_bit& tab2);
    friend tab_bit operator~(const tab_bit& tab);
};
};