#include <math.h>
#include <stdio.h>
int main() {
   int low, number, originalNumber, rem, count = 0;
   double result = 0.0;
   
   scanf("%d", &low);
   
   for (number = low + 1; number < low+1000; ++number) {
      originalNumber = number;

     
      while (originalNumber != 0) {
         originalNumber /= 10;
         ++count;
      }

      originalNumber = number;

      
      while (originalNumber != 0) {
         rem = originalNumber % 10;
         result += pow(rem, count);
         originalNumber /= 10;
      }

      
      if ((int)result == number) {
         printf("%d ", number);
         return 0;
      }

      
      count = 0;
      result = 0;
   }

   printf("BRAK");

   return 0;
}