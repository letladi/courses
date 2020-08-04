#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_EXPR_LEN 100

void make_empty(void);
void stack_overflow(void);
void stack_underflow(void);
bool is_empty(void);
bool is_full(void);
void push(int);
int pop(void);
int evaluate_RPN_expression(const char *expression);

int main(void) 
{
   char c, expr[MAX_EXPR_LEN] = {'\0'};
   int i = 0;
   bool is_num, is_op;

   do {
      printf("Enter an RPN expression: ");
      while ((c = getchar()) != '\n') {
         if (c == 'q') exit(EXIT_SUCCESS);
         
         if (i > MAX_EXPR_LEN) {
            printf("Expression is too complex\n");
            exit(EXIT_FAILURE);
         } else {
            if (!isspace(c)) expr[i++] = c;
         }
      }
      printf("Value of expression: %d\n", evaluate_RPN_expression(expr));
      i = 0;
   } while (true); 

   return 0;
}

int evaluate_RPN_expression(const char *expr)
{
   char c;
   int n, ret;
   bool is_num, is_op;
   while (*expr) {
      c = *expr++;
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
            case '=': ret = pop(); goto after_evaluation;
            default: 
               printf("[%s] is not a valid expression, %d\n", expr);
               exit(EXIT_FAILURE);
         }
      }
   }
   after_evaluation:
   return ret;
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


