/**
 * a) is illegal ✔️
 * d) is also illegal because it is not a pointer to an array ❌ For a pointer p, p[0] is the same as (p + 0), and so d) is valid and true
 * b), c) are both is true ✔️
 * 
 * 
 */
#include <stdio.h>

int main(void)
{
   int n = 10, *p;
   int a[n];
   p = a;
   // a)
   printf("%d\n", p == a[0]);
   // b)
   printf("%d\n", p == &a[0]);
   // c)
   printf("%d\n", *p == a[0]);
   // d)
   printf("%d\n", p[0] == a[0]);

   return 0;
}