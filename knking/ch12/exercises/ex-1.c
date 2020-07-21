/**
 * a) 14 ✔️
 * b) 34 ✔️
 * c) 4 ✔️
 * d) yes ✔️
 * e) no ✔️
 */ 

#include <stdio.h>

int main(void)
{
   int a[] = {5, 15, 34, 54, 14, 2, 52, 72};
   int *p = &a[1], *q = &a[5];

   printf("a) *(p+3) = %d\n", *(p+3));
   printf("b) *(q-3) = %d\n", *(q-3));
   printf("c) q - p = %ld\n", q - p);
   printf("d) ");
   printf(p < q ? "true" : "false");
   printf("\ne) ");
   printf(*p < *q ? "yes": "no");
   printf("\n");
   return 0;
}