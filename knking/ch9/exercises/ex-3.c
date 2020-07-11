#include <stdio.h>

int gcd(int a, int b)
{
   if (b == 0) return a;
   else return gcd(b, a % b);
}

int main(void)
{
   printf("gcd(%d,%d) = %d\n",28, 12, gcd(28, 12));
   return 0;
}

