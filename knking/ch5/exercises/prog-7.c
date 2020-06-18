#include <stdio.h>

int main(void)
{
   int a, b, c, d;
   printf("Enter four integers: ");
   scanf("%d %d %d %d", &a, &b, &c, &d);

   int max = a, min = a ;
   // find max 
   if (b > max || c > max) max = c > b ? c : b;
   if (d > max) max = d;

   // find min
   if (b < min || c < min) min = c < b ? c : b;
   if (d < min) min = d;

   printf("Largest: %d\n", max);
   printf("Smallest: %d\n", min);

   return 0;
}