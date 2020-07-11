#include <stdio.h>

int gcd(int m, int n)
{
   return n > 0 ? gcd(n, m % n) : m;
}

int main(void)
{
   printf("gcd(%d,%d) = %d\n",28, 12, gcd(28, 12));
   return 0;
}