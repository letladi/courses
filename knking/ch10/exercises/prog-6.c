#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void make_empty(void);
void stack_overflow(void);
void stack_underflow(void);
bool is_empty(void);
bool is_full(void);
void push(int);
int pop(void);

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
                  n = pop();
                  push(n + pop());
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
         if (!is_op) goto after_evaluator;
      }
      after_expression:
         printf("Value of expression: %d\n", pop());

   } while (true); 

   after_evaluator:
      return 0;
}


#define STACK_SIZE 100
/* external variables */
int contents[STACK_SIZE];
int top = 0;

void make_empty(void)
{
   top = 0;
}

void stack_underflow()
{
   printf("cannot read empty stack. Exiting...\n");
   exit(EXIT_FAILURE);
}

void stack_overflow()
{
   printf("cannot add to full stack. Exiting...\n");
   exit(EXIT_FAILURE);
}

bool is_empty(void)
{
   return top == 0;
}

bool is_full(void)
{
   return top == STACK_SIZE;
}

void push(int i)
{
   if (is_full()) stack_overflow();
   else contents[top++] = i;
}

int pop(void)
{
   if (is_empty()) stack_underflow();
   else return contents[--top];
}


