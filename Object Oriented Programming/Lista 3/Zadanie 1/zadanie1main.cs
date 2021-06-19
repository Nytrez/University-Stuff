using System;
using KluczLista;

class zadanie1
{
    static void Main()
    {
        Lista <int> stos = new Lista <int> ();  //tworzenie stosu 
        Lista <string> kolejka = new Lista <string> (); //tworzenie kolejki

        string data = "a";
        for (int i = 0; i < 5; i ++) //dodawanie wartosci do list
        {
            Console.WriteLine("dodane wartosci: {0} oraz {1}" ,i, data); 
            stos.push_front(i);
            kolejka.push_back(data);
            Random rnd = new Random();
            data += (char)rnd.Next('a','z');
        }
         Console.WriteLine();
       /*
        for(int i =0; i<stos.size;i++)
        {
            Console.Write("{0} " ,stos.first.data); 
            stos.first=stos.first.next;
        }
        */

        /*
        for(int i =0; i<kolejka.size;i++)
        {
            Console.Write("{0} " ,kolejka.first.data); 
            kolejka.first=kolejka.first.next;
        }
         */
        Console.WriteLine();


          for (int i = 0; i < 5; i ++) //oproznianie list
        {

             Console.WriteLine("usuniete wartosci: {0} oraz {1}" ,stos.pop_back(),kolejka.pop_front()); 
            
        }
        

        Console.WriteLine("\nEmpty: {0} {1}", stos.is_empty(), kolejka.is_empty()); //sprawdzenie czy listy sa puste

        
       
        
        
    }
}