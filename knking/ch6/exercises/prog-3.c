#include <stdio.h>

int main(void) 
{
   int m, n;
   printf("Enter a fraction: ");
   scanf("%d / %d", &m, &n);
   int old_m = m, old_n = n; 
   while (m > 0) {
      int temp = m;
      m = n % m;
      n = temp;
   }
   int gcd = n;

   printf("In lowest terms: %d/%d\n", old_m / gcd, old_n / gcd);

   return 0;
}