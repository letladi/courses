#include <stdio.h>

void swap(int *p, int *q)
{
   int temp = *p;
   *p = *q;
   *q = temp;
}

int main(void)
{
   int i = 5, j = 10;
   printf("Before swap: i = %d, j = %d\n", i, j);
   swap(&i, &j);
   printf("After swap: i = %d, j = %d\n", i, j);

   return 0;
}
// ✔️