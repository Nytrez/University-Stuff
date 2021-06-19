#include "tab_bit.hpp"
namespace obliczenia
{

    std::istream &operator>>(std::istream &we, tab_bit &tab)
    {
        std::string wejscie;
        we >> wejscie;

        delete[] tab.bit_tab;

        tab.dl = wejscie.size();
        int ilosc_slow = std::ceil((double)wejscie.size() / (double)tab_bit::rozmiar_slowa);
        tab.bit_tab = new tab_bit::slowo[ilosc_slow];

        int i = 0;
        for (auto &bit : wejscie)
        {
            if (bit != '0' and bit != '1')
                throw std::invalid_argument("niepoprawny napis - cyfry rozne od 0 i 1");

            bool wartosc = (bool)(bit - '0');
            tab[i++] = wartosc;
        }

        return we;
    }

    std::ostream &operator<<(std::ostream &wy, const tab_bit &tab)
    {
        for (int index = 0; index < tab.dl; index++)
            wy << tab[index];

        return wy;
    }

    tab_bit::ref &tab_bit::ref::operator=(bool wartosc)
    {
        tab_bit::slowo maska = uint64_t(1) << i;
        *(this->wsk) &= ~maska;
        *(this->wsk) |= (uint64_t)wartosc << i;

        return *this;
    }

    tab_bit::ref::operator bool() const
    {
        return (bool)(*(this->wsk) & (uint64_t(1) << this->i));
    }

    tab_bit::ref & tab_bit::ref::operator=(const ref &bit) 
    {
        bool wartosc = (bool)bit;
        *this = wartosc;

        return *this;
    }

    tab_bit::ref::ref(int i, slowo *s)
    {
        this->wsk = s;
        this->i = i;
    }

    bool tab_bit::operator[](int i) const
    {
        if (i >= this->dl || i < 0)
            throw std::invalid_argument("tablica nie posiada takiego indeksu");

        uint64_t indeks_slowa = i / rozmiar_slowa;
        uint64_t indeks_bitu = i % rozmiar_slowa;

        return (bool)ref(indeks_bitu, &(this->bit_tab[indeks_slowa])); 
    }

    tab_bit::ref tab_bit::operator[](int i)
    {
        if (i >= this->dl || i < 0)
            throw std::invalid_argument("tablica nie posiada takiego indeksu");

        int indeks_slowa = i / rozmiar_slowa;
        int indeks_bitu = i % rozmiar_slowa;

        return ref(indeks_bitu, &(this->bit_tab[indeks_slowa]));
    }

    tab_bit::tab_bit(int rozm)
    {
        if (rozm <= 0)
            throw std::invalid_argument("ujemny rozmiar");

        this->dl = rozm;
        int ilosc_slow = std::ceil((double)this->dl / (double)rozmiar_slowa);

        this->bit_tab = new slowo[ilosc_slow];

        for (int i = 0; i < ilosc_slow; i++)
            this->bit_tab[i] = 0;
    }

    tab_bit::tab_bit(slowo tab)
    {
        this->dl = rozmiar_slowa;
        this->bit_tab = new slowo[1];
        this->bit_tab[0] = tab;
    }

    tab_bit::tab_bit(const std::initializer_list<int> &lista) : tab_bit((int)lista.size())
    {
        if (!lista.size())
            throw std::invalid_argument("pusta lista inicjalizujaca");

        int i = 0;
        for (int bit : lista)
        {
            if (bit == 0 or bit == 1)
                (*this)[i++] = (bool)bit;
            else
                throw std::invalid_argument("niewlasciwe wartosci w liscie inicjalizujacej!");
        }
    }

    tab_bit::tab_bit(const tab_bit &tab)
    {
        this->dl = tab.dl;
        this->bit_tab = new slowo[(int)(sizeof(tab.bit_tab))];

        for (int i = 0; i < (int)(sizeof(tab.bit_tab)); i++)
            this->bit_tab[i] = tab.bit_tab[i];
    }

    tab_bit::tab_bit(tab_bit &&tab)
    {
        this->dl = tab.dl;
        this->bit_tab = tab.bit_tab;

        tab.dl = 0;
        tab.bit_tab = nullptr;
    }

    tab_bit &tab_bit::operator=(const tab_bit &tab)
    {
        if (this != &tab)
        {
            delete[] this->bit_tab;

            this->dl = tab.dl;
            int ilosc_slow = std::ceil((double)tab.dl / (double)rozmiar_slowa);
            this->bit_tab = new slowo[ilosc_slow];

            for (int i = 0; i < ilosc_slow; i++)
                this->bit_tab[i] = tab.bit_tab[i];
        }

        return *this;
    }

    tab_bit &tab_bit::operator=(tab_bit &&tab)
    {
        if (this != &tab)
        {
            delete[] this->bit_tab;

            this->dl = tab.dl;
            this->bit_tab = tab.bit_tab;
            tab.bit_tab = nullptr;
            tab.dl = 0;
        }

        return *this;
    }

    tab_bit &tab_bit::operator|=(const tab_bit &tab)
    {
        const tab_bit &wynik = (*this | tab);
        *this = std::move(wynik);

        return *this;
    }

    tab_bit &tab_bit::operator&=(const tab_bit &tab)
    {
        const tab_bit &wynik = (*this & tab);
        *this = std::move(wynik);

        return *this;
    }

    tab_bit &tab_bit::operator^=(const tab_bit &tab)
    {
        const tab_bit &wynik = (*this ^ tab);
        *this = std::move(wynik);

        return *this;
    }

    tab_bit operator|(const tab_bit &tab1, const tab_bit &tab2)
    {
        tab_bit wynik(tab1.rozmiar() > tab2.rozmiar() ? tab1 : tab2);
        int min = tab1.rozmiar() > tab2.rozmiar() ? tab2.rozmiar() : tab1.rozmiar();

        for (int i = 0; i < min; i++)
            wynik[i] = tab1[i] | tab2[i];

        return wynik;
    }

    tab_bit operator&(const tab_bit &tab1, const tab_bit &tab2)
    {
        tab_bit wynik(tab1.rozmiar() > tab2.rozmiar() ? tab1 : tab2);
        int min = tab1.rozmiar() > tab2.rozmiar() ? tab2.rozmiar() : tab1.rozmiar();

        for (int i = 0; i < min; i++)
            wynik[i] = tab1[i] & tab2[i];

        return wynik;
    }

    tab_bit operator^(const tab_bit &tab1, const tab_bit &tab2)
    {
        tab_bit wynik(tab1.rozmiar() > tab2.rozmiar() ? tab1 : tab2);
        int min = tab1.rozmiar() > tab2.rozmiar() ? tab2.rozmiar() : tab1.rozmiar();

        for (int i = 0; i < min; i++)
            wynik[i] = tab1[i] ^ tab2[i];

        return wynik;
    }

    tab_bit operator~(const tab_bit &tab)
    {
        tab_bit wynik(tab);

        int ilosc_slow = std::ceil((double)tab.rozmiar() / (double)tab_bit::rozmiar_slowa);

        for (int i = 0; i < ilosc_slow; i++)
            wynik.bit_tab[i] = ~wynik.bit_tab[i];

        return wynik;
    }

    tab_bit::~tab_bit()
    {
        delete[] this->bit_tab;
    }
};