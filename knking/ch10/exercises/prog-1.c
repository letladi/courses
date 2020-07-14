#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define STACK_SIZE 100

/* external variables */
char contents[STACK_SIZE];
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

void push(char i)
{
   if (is_full()) 
      stack_overflow();
   else 
      contents[top++] = i;
}

char pop(void)
{
   if (is_empty()) 
      stack_underflow();
   else 
      return contents[--top];
}

bool braces_match(char opening, char closing)
{
   switch(opening) {
      case '(': return closing == ')';
      case '[': return closing == ']';
      case '{': return closing == '}';
   }
   return false;
}

int main(void)
{
   printf("Enter parentheses and/or braces: ");
   char c;
   bool has_proper_nesting;

   while ((c = getchar()) != '\n') {
      switch(c) {
         case '(': case '[': case '{': 
            if (is_full()) stack_overflow();
            push(c); break;

         case ')': case ']': case '}':
            if (is_empty()) {
               has_proper_nesting = false;
               goto after_bracker_tests;
            } else {
               if (!braces_match(pop(), c)) {
                  has_proper_nesting = false;
                  goto after_bracker_tests;
               }
            }
         
         case ' ': case '\t': break; // do nothing in this case, just keep it moving

         default: 
            printf("'%c' is not a brace\n");
            exit(EXIT_FAILURE); 
      }
   }

   has_proper_nesting = is_empty();

   after_bracker_tests:
      printf("Parentheses/braces are ");
      printf(has_proper_nesting ? "nested properly\n" : "not nested properly\n");

   return 0;
}