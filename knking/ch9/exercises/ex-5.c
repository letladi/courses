#include <stdio.h>

int num_digits(long long n)
{
   int cnt = 0;
   do {
      cnt++;
      n /= 10;
   } while (n > 0);
   return cnt;
}