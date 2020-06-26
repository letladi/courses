#include <stdio.h>

int main(void)
{
   int num1, denom1, num2, denom2, result_num, result_denom;
   char sign;

   printf("Enter two fractions separated by a plus sign: ");
   scanf("%d / %d %c %d / %d", &num1, &denom1, &sign, &num2, &denom2);

   if (denom1 == 0 || denom2 == 0) {
      printf("Error: a fraction may not have a zero denominator\n");
   } else {

      switch(sign) {
         case '-': case '+':
            result_num = num1 * denom2 + num2 * denom1;
            result_denom = denom1 * denom2;
            break;
         case '*':
            result_num = num1 * num2;
            result_denom = denom1 * denom2;
            break;
         case '/':
            result_num = num1 * denom2;
            result_denom = denom1 * num2;
            break;
      }
      printf("%d/%d %c %d/%d =  %d/%d\n", num1, denom1, sign, num2, denom2, result_num, result_denom);
   }

   return 0;
}