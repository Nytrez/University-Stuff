using System;

class task1example
{
    static void Main()
    {

        // Console.WriteLine("int maxvalue {0}", int.MaxValue);

        IntStream stream = new IntStream();
        Console.WriteLine("Int 1: {0}", stream.next());
        Console.WriteLine("Int 2: {0}", stream.next());
        Console.WriteLine("Int 3: {0}", stream.next());


        PrimeStream prime = new PrimeStream();
        Console.WriteLine("Prime 1: {0}", prime.next());
        Console.WriteLine("Prime 2: {0}", prime.next());
        Console.WriteLine("Prime 3: {0}", prime.next());
        Console.WriteLine("Prime 4: {0}", prime.next());
        Console.WriteLine("Prime 5: {0}", prime.next());
        Console.WriteLine("Prime 6: {0}", prime.next());

        RandomStream random = new RandomStream();
        Console.WriteLine("Random 1: {0}", random.next());
        Console.WriteLine("Random 2: {0}", random.next());
        Console.WriteLine("Random 3: {0}", random.next());

        RandomWordStream rws = new RandomWordStream();
        Console.WriteLine("Random word {0}: {1}",rws.length, rws.next());
        Console.WriteLine("Random word {0}: {1}",rws.length, rws.next());
        Console.WriteLine("Random word {0}: {1}",rws.length, rws.next());
        Console.WriteLine("Random word {0}: {1}",rws.length, rws.next());
        Console.WriteLine("Random word {0}: {1}",rws.length, rws.next());
        



    }
}