#include <stdio.h>

#define N1 5
#define N2 10

int *find_middle(int a[], int n)
{
   return a + (n / 2);
}

int main(void)
{
   int a[N1] = {1, 2, 3, 4, 5};
   int b[N2] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
   printf("middle of a: %d\n", *find_middle(a, N1));
   printf("middle of b: %d\n", *find_middle(b, N2));
   return 0;
}