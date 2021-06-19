#include <bits/stdc++.h>
using namespace std;

class Queue
{

private:
    int pojemnosc, ilosc_elem, poczatek;
    string *queue;

public:
    //konstruowanie
    Queue();
    Queue(int pojemnosc);
    Queue(initializer_list<string> il);
    Queue(const Queue &k);
    Queue(Queue &&k);
    ~Queue();

    // przypisywanie
    Queue &operator=(const Queue &k); // kopiujacy
    Queue &operator=(Queue &&k);      // przenoszacy
    // funkcje
    string wyciagnij();
    string sprawdz();
    void wloz(string x);
    void wypisz();
    int rozmiar();
    bool czy_pelna();
    bool czy_pusta();
};
