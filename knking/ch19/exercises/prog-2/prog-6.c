#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "stackADT.h"

int main(void) 
{
   char c;
   int n;
   bool is_num, is_op;
   Stack s = create();

   if (!s) {
      printf("Error initializing calculator\n");
      exit(EXIT_FAILURE);
   }

   do {
      printf("Enter an RPN expression: ");
      while (true) {
         scanf(" %c", &c);
         if (is_full(s)) {
            printf("Expression is too complex\n");
            exit(EXIT_FAILURE);
         }
         is_num = '0' <= c && c <= '9';
         if (is_num) {
            push(s, c - '0');
         } else { 
            is_op = true;
            switch(c) {
               case '+':
                  n = pop(s);
                  push(s, n + pop(s));
                  break;
               case '-':
                  n = pop(s);
                  push(s, pop(s) - n);
                  break;
               case '*':
                  n = pop(s);
                  push(s, pop(s) * n);
                  break;
               case '/':
                  n = pop(s);
                  push(s, pop(s) / n);
                  break;
               case '%':
                  n = pop(s);
                  push(s, pop(s) % n);
               case '=': goto after_expression;

               default: 
                  printf("Invalid op '%c'\n", c);
                  exit(EXIT_FAILURE);
            }
         }
      }
      after_expression:
         if (is_empty(s)) {
            printf("Invalid expression\n");
            exit(EXIT_FAILURE);
         }
         printf("Value of expression: %d\n", pop(s));

   } while (true); 

   return 0;
}