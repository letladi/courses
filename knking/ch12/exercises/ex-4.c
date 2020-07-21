#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define STACK_SIZE 100

/* external variables */
int contents[STACK_SIZE];
int *top_ptr = contents;

void make_empty(void)
{
   top_ptr = contents;
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
   return top_ptr == contents;
}

bool is_full(void)
{
   return top_ptr == (contents + STACK_SIZE);
}

void push(int i)
{
   if (is_full()) stack_overflow();
   else *top_ptr++ = i;
}

int pop(void)
{
   if (is_empty()) stack_underflow();
   else return *--top_ptr;
}

int length(void)
{
   return top_ptr - contents;
}

int main(void)
{
   int n = 10;
   int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
   for (int i = 0; i < n; i++) push(a[i]);
   printf("from stack: ");
   while (!is_empty()) printf("%d ", pop());
   printf("\n");

   return 0;
}
// ✔️