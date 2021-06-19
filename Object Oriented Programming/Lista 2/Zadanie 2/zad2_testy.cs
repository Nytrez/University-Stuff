using System;

class zad2_testy { 
  static void Main() {
    Array newArr = new Array(-5, 5);
    Console.WriteLine("\nArray (-5, 5):");
    for(int i=0; i<11; i++) {
      Console.Write("{0} ", newArr.list[i]);
    }
     Console.WriteLine("\nOld start: {0}", newArr.get(newArr.start));
      Console.WriteLine("Old end: {0}", newArr.get(newArr.start+newArr.size-1));
    
    Console.WriteLine("\nAdd to array 13 on index 7 and 15 on index -6::");
    newArr.insert_value(7, 13);
    newArr.insert_value(-7, 15);
    Console.WriteLine("New size: {0}", newArr.size);
    for(int i=0; i<newArr.size; i++) {
      Console.Write("{0} ", newArr.list[i]);
    }

    Console.WriteLine("\nNew start: {0}", newArr.get(newArr.start));
    Console.WriteLine("New end: {0}\n", newArr.get(newArr.start+newArr.size-1));
  }
}