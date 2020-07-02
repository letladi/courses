#include <stdio.h>
#include <stdbool.h>
#define DEC_COUNT 10

int main(void)
{
   int digit_seen[DEC_COUNT] = {0};
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

   printf("Digit      : ");
   for (int i = 0; i < DEC_COUNT; i++) {
      printf("%3d ", i);
   }
   printf("\n");

   printf("Occurrences: ");
   for (int j = 0; j < DEC_COUNT; j++) {
      printf("%3d ", digit_seen[j]);
   }
   printf("\n");
      
   return 0;
}