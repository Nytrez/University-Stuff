#include "tab_dbl.hpp"

namespace obliczenia
{
    tab_dbl::tab_dbl(int rozm) // wyzerowana tablica liczb
    {
        if (rozm <= 0)
            throw std::invalid_argument("niepoprawny rozmiar");
        dl = rozm;
        tab = new double[dl]();
    }

    tab_dbl::tab_dbl(const tab_dbl &t) // konstruktor kopiujący
    {
        delete[] tab;
        dl = t.dl;
        tab = new double[t.dl]();
        std::copy(t.tab, t.tab + dl + 1, tab);
    }

    tab_dbl::tab_dbl(tab_dbl &&t) // konstruktor przenoszący
    {
        if (this == &t)
            return;
        delete[] tab;
        dl = t.dl;
        tab = t.tab;
        t.tab = nullptr;
    }

    tab_dbl &tab_dbl::operator=(const tab_dbl &t) // przypisanie kopiujące
    {
        if (this == &t)
            return *this;
        dl = t.dl;
        tab = new double[dl]();
        std::copy(t.tab, t.tab + dl, tab);
        return *this;
    }

    tab_dbl &tab_dbl::operator=(tab_dbl &&t) // konstruktor przenoszący
    {
        if (this == &t)
            return *this;
        delete[] tab;
        dl = t.dl;
        tab = t.tab;
        t.tab = nullptr;
        return *this;
    }

    tab_dbl::~tab_dbl() //dekonstruktor
    {
        delete[] tab;
    }

    double tab_dbl::operator[](int num) const //zwracanie wartosci pod indeksem
    {
        if (num < 0 || num >= dl)
        {
            throw std::out_of_range("niepoprawny indeks");
        }
        return (tab[num]);
    }

    double &tab_dbl::operator[](int num) //zwracanie wartosci pod indeksem
    {
        if (num < 0 || num >= dl)
        {
            throw std::out_of_range("niepoprawny indeks");
        }
        return tab[num];
    }

    int tab_dbl::get_dl() const //zwracanie dlugosci
    {
        return dl;
    }

    // zadanie 2
    tab_dbl::tab_dbl()
    {
        long long rozmiar = 1;
        while (true) // gdy tworzyla sie kolejna tablica o rozmiarze 2^29 program sie wysypywal std::bad_array_new_length
        {
            try
            {
                tab = new (std::nothrow) double[rozmiar];
               // std::cout << "rozmiar: " << rozmiar << std::endl;
                rozmiar = rozmiar * 2;
                delete[] tab;
            }
            catch (std::bad_array_new_length)
            {
                rozmiar = rozmiar / 2;
                dl = rozmiar;
                tab = new double[rozmiar];
                for (int i = 0; i < rozmiar; i++)
                {
                    tab[i] = (float)rand() / RAND_MAX;
                }

                return;
            }
        }
    }

    // zadanie 3

    tab_dbl::tab_dbl(const std::initializer_list<double> &ini)
    {
        if (!ini.size())
        {
            throw std::invalid_argument("pusta lista inicjalizujaca");
        }
        dl = ini.size() - 1;
        int k = 0;
        tab = new double[ini.size()];
        for (auto i = ini.begin(); i != ini.end(); i++)
        {
            tab[k++] = *i;
        }
    }

    double tab_dbl::operator*(const tab_dbl &t) //iloczyn skalarny
    {
        if (t.get_dl() != dl)
            throw std::invalid_argument("dlugosci tablic sa rozne");
        double suma = 0;
        for (int i = 0; i < dl; i++)
            suma += tab[i] * t.tab[i];

        return suma;
    }

}
