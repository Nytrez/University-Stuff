#include <bits/stdc++.h>
#include "kolejka.hpp"

Queue::Queue()
{
    poczatek = 0, pojemnosc = 1, ilosc_elem = 0;
    queue = new string[pojemnosc];
}

Queue::Queue(int pojemnosc)
{
    if (pojemnosc <= 0)
    {
        clog << "za maly rozmiar! \n";
    }
    else
    {
        this->pojemnosc = pojemnosc;
        poczatek = 0, ilosc_elem = 0;
        queue = new string[pojemnosc];
    }
}

Queue::Queue(initializer_list<string> list)
{
    if (list.size() == 0)
    {
        clog << "lista jest pusta! \n";
    }
    else
    {
        pojemnosc = list.size();
        queue = new string[pojemnosc];
        ilosc_elem = list.size();
        poczatek = 0;

        int ptr = poczatek;
        for (auto elem : list)
            queue[ptr++] = elem;
    }
}

Queue::Queue(const Queue &k)
{
    pojemnosc = k.pojemnosc;
    poczatek = k.poczatek;
    ilosc_elem = k.ilosc_elem;

    queue = new string[pojemnosc];
    copy(k.queue, k.queue + k.pojemnosc, queue);
}

Queue::Queue(Queue &&k)
{
    pojemnosc = k.pojemnosc;
    queue = k.queue;
    poczatek = k.poczatek;
    ilosc_elem = k.ilosc_elem;

    k.pojemnosc = 0;
    k.poczatek = 0;
    k.ilosc_elem = 0;
    k.queue = nullptr;
}

Queue::~Queue()
{
    delete[] queue;
}

Queue &Queue::operator=(const Queue &k)
{
    if (this == &k)
    {
        return *this;
    }
    else
    {
        delete[] queue;
        pojemnosc = k.pojemnosc;
        queue = new string[pojemnosc];
        poczatek = k.poczatek;
        ilosc_elem = k.ilosc_elem;
        copy(k.queue, k.queue + k.pojemnosc, queue);

        return *this;
    }
}

Queue &Queue::operator=(Queue &&k)
{
    if (this != &k)
    {
        delete[] queue;
        pojemnosc = k.pojemnosc;
        queue = k.queue;
        poczatek = k.poczatek;
        ilosc_elem = k.ilosc_elem;
    }
    return *this;
}

string Queue::wyciagnij()
{
    if (this->czy_pusta())
    {
        clog << "Empty queue! \n";
        return 0;
    }
    else
    {
        auto del = sprawdz();
        poczatek++;
        ilosc_elem--;
        return del;
    }
}

string Queue::sprawdz()
{
    if (this->czy_pusta())
    {
        clog << "Empty queue! \n";
        return 0;
    }
    else
    {
        poczatek %= pojemnosc;
        return queue[poczatek];
    }
}

void Queue::wloz(string x)
{
    if (this->czy_pelna())
    {
        clog << "kolejka jest pelna! \n";
    }
    else
    {
        queue[(poczatek + ilosc_elem) % pojemnosc] = x;
        ilosc_elem++;
    }
}

void Queue::wypisz()
{
    int i = poczatek, cnt = ilosc_elem;
    while (cnt--)
    {
        cout << queue[i % pojemnosc] << " ";
        i++;
    }
}

int Queue::rozmiar()
{
    return ilosc_elem;
}

bool Queue::czy_pusta()
{
    return ilosc_elem == 0;
}

bool Queue::czy_pelna()
{
    return pojemnosc == ilosc_elem;
}
