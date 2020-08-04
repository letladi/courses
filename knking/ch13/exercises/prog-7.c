#include <stdio.h>

int main(void)
{
   int num;
   printf("Enter a two-digit number: ");
   scanf("%d", &num);

   char *digit_names[] = {
      "zero", "one", "two", "three", "four", "five",
      "six", "seven", "eight", "nine", "ten",
      "eleven", "twelve", "thirteen", "fourteen", "fifteen",
      "sixteen", "seventeen", "eighteen", "nineteen"
   };
   char *ten_names[] = {
      "", "ten", "twenty", "thirty", "fourty", "fifty",
      "sixty", "seventy", "eighty", "ninety"
   };

   int tens = num / 10;
   int units = num % 10;
   _Bool has_tens = tens != 0;
   _Bool between_10_and_20 = tens == 1;

   if (has_tens) {
      switch(tens) {
         case 1: printf("%s", digit_names[units + 10]); break;
         default: printf("%s", ten_names[tens]); break;
      }
      if (!between_10_and_20 && units != 0) {
         printf("-");
      }
   } 
   if (!between_10_and_20 && (num % 10 != 0)) {
      printf("%s", digit_names[units]); 
   }
   
   printf("\n");

   return 0;
}