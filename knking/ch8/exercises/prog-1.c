#include <stdio.h>
#include <stdbool.h>

int main(void)
{
   int digit_seen[10] = {0};
   bool has_repeats = false;
   int digit;
   long n;

   printf("Enter a number: ");
   scanf("%ld", &n);

   while (n > 0) {
      digit = n % 10;
      if (!has_repeats) {
         has_repeats = digit_seen[digit] >= 1;
      }
      
      digit_seen[digit]++;
      n /= 10;
   }

   if (has_repeats) {
      printf("Repeated digit(s): ");
      for (int i = 0; i < 10; i++) {
         if (digit_seen[i] > 1)  printf("%d ", i);
      }
      printf("\n");
   } else {
      printf("No repeated digit\n");
   }
      
   return 0;
}