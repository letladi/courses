#include <stdio.h>

int main(void)
{
   int d, i1, i2, i3, i4, i5, j1, j2, j3, j4, j5, check_n,
      first_sum, second_sum, total, computed_check_n;

   printf("Enter a UPC: ");
   scanf("%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d", 
      &d, 
      &i1, &i2, &i3, &i4, &i5,
      &j1, &j2, &j3, &j4, &j5,
      &check_n
   );

   first_sum = d + i2 + i4 + j1 + j3 + j5;
   second_sum = i1 + i3 + i5 +j2 + j4;
   total = 3 * first_sum + second_sum;
   computed_check_n = 9 - ((total - 1) % 10);
   if (check_n == computed_check_n)
      printf("VALID\n");
   else 
      printf("INVALID\n");

   return 0;
}