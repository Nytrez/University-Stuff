using System;
using System.Collections.Generic;


class Array
{ //klasa listy
    public int start, size;
    public List<int> list;

    public Array(int start, int end)
    {
        this.start = start;
        size = end - start + 1;
        list = new List<int>();
        for (int i = start; i < start + size; i++)
        {
            list.Add(i);
        }
    }

    public int get(int i)//pobieranie elementu z o indeksie i z listy
    { 
        return list[i - start];
    }

    public void insert_value(int index_to_add, int value)//dodawanie elementu na dany index
    { 
        if (index_to_add >= size + start)//jezeli indeks nowego elementu jest wiekszy od ostatnuego indexu  listy 
        { 
            int i = size;
            while (i <= index_to_add - start)
            {
                list.Add(0); //na indeksy pomiedzy docelowym a aktualnym ostatnim dodajemy 0
                i++;
                size++; //powiekszanie rozmiaru listy
            }
            list[index_to_add - start] = value; //ustawiamy w docelowym indeksie nasza wartosc
        }
        else if (index_to_add < start) //jezeli indeks nowego elementu jest mniejszy od pierwszego indexu  listy 
        {
            int desired_index = index_to_add - start;
            if (desired_index < 0) desired_index *=-1; //wartpsc bezwzgledna
  
            for (int i = 0; i < desired_index; i++)
            {
                list.Add(0); //rozszerzamy chwilowo liste o desired_indeks
                size++;
            }

            int new_el = size - 1;
            int old_el = size - 1 - desired_index;

            while (old_el >= 0)  //przesuwamy cala liste w prawo
            {
                list[new_el] = list[old_el];
                old_el--;
                new_el--;
            }
            while (new_el > 0) //dodajemy 0 pomiedzy docelowym indeksem a pierwszym
            {
                list[new_el] = 0;

                new_el--;
            }
            list[0] = value; //wstawiamy docelowa wartosc
            start = index_to_add; //ustawiamy nowy start
        }
        else //jezeli jest w zasiegu listy podmień element o danym indeksie
        {
            list[index_to_add - start] = value; 
        }
    }
}