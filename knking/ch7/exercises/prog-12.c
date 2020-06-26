#include <stdio.h>

int main(void)
{
   printf("Enter an expression: ");
   float result, f2;
   char op, c;
   scanf(" %f", &result);
   while (1) {
      scanf(" %c", &op);
      after_op:
      scanf(" %f", &f2);
      
      switch(op) {
         case '-': result -= f2; break;
         case '+': result += f2; break;
         case '/': result /= f2; break;
         case '*': result *= f2; break;
      }
      after_eval:
      c = getchar();
      switch(c) {
         case '\n': 
            goto after_expr;
         case ' ': case '\t': 
            goto after_eval;
         case '-': case '+': case '/': case '*': 
            op = c;
            goto after_op;
      }
   }
   

   after_expr: 
      printf("Value of expression: %.2f\n", result);

   return 0;
}