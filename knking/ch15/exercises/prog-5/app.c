#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"

int main(void)
{
   char c;
   int n;
   bool is_num, is_op;

   do {
      printf("Enter an RPN expression: ");
      while (true) {
         scanf(" %c", &c);
         // if (c == ' ' || c == '\t' || c == '\n') continue; // skip whitespace
         if (is_full()) {
            printf("Expression is too complex\n");
            exit(EXIT_FAILURE);
         }
         is_num = '0' <= c && c <= '9';
         if (is_num) {
            push(c - '0');
         } else {
            is_op = true;
            switch(c) {
               case '+':
                  push(pop() + pop());
                  break;
               case '-':
                  n = pop();
                  push(pop() - n);
                  break;
               case '*':
                  n = pop();
                  push(pop() * n);
                  break;
               case '/':
                  n = pop();
                  push(pop() / n);
                  break;
               case '=': goto after_expression;
               default: is_op = false; break;
            }
         }
         if (!is_op) {
            goto after_evaluator;
         }
      }
      after_expression:
         printf("Value of expression: %d\n", pop());

   } while (true);

   after_evaluator:
      return 0;
}
