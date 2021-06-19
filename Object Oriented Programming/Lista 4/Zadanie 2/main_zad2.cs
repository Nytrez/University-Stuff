using System;
using Liczby_Pierwsze;

class Program
{
    static void Main(string[] args)
    {

System.Console.WriteLine(int.MaxValue);

        Liczby_Pierwsze.PrimeCollection pc = new PrimeCollection();
        foreach(int p in pc)
				System.Console.WriteLine(p);
    }
}