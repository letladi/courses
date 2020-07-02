#include <stdio.h>

int main(void)
{
   int a[] = {4, 9, 1, 8, [0] = 5, 7};
   printf("a.length = %lu\n", sizeof(a) / sizeof(a[0]));
   return 0;
}