#include <stdio.h>

int digit(long long n, int k)
{
   int d;
   int cnt = 0;
   do {
      d = n % 10;
      n /= 10;
      cnt++;

      if (cnt == k) return d;

   } while (n > 0);

   return 0;
}

// ✔️
/*

int digit(int n, int k)
{
   int i;
   for (i = 1; i < k; i++) n /= 10;
   return n % 10;
}

*/

int main(void)
{
   printf("digit(829, 1) = %d\n", digit(829, 1));
   printf("digit(829, 2) = %d\n", digit(829, 2));
   printf("digit(829, 3) = %d\n", digit(829, 3));
   printf("digit(829, 4) = %d\n", digit(829, 4));

   return 0;
}