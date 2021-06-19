using System;
using ListLib;

class Program
{
    static void Main(string[] args)
    {
     
        //sprawdzenie list
        ListLib.List <string> list = new ListLib.List <string>();
        string data = "a";

       
        
        for (int i = 0; i < 10; i ++) //wrzucanie liter
        {
           list.push(data);
           data += ((char)(i + 98));       
        }

        //indeksowanie
        Console.WriteLine("indeks 2 {0}", list[2]);
        Console.WriteLine("indeks 3 {0}", list[3]);

        //dlugosc
        Console.WriteLine("dlugosc {0}", list.Length);

        //to string
        Console.WriteLine("do stringa {0}",list); 
        
        //IEnumerable
        ListLib.List <int> enumerable = new ListLib.List <int> ();
      
        for (int i = 0; i < 5; i ++)
            enumerable.push(i);
        
        foreach (int i in enumerable)
        {
            Console.Write("{0} ",i);
        }

        
        
        
    }
}