#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> // for atof()
#include <math.h>

#include "getch.h"
#include "getop.h"
#include "stack.h"

#define MAXOP 100 // maximum of operand/operator
#define LAST '$'
#define EXP 'e'
#define SINE 's'

// reverse Polish calculator
int main()
{
   int type;
   double op2;
   char s[MAXOP];
   double last = 0.0;
   while ((type = getop(s)) != EOF) {
      switch (type) {
         case NUMBER: push(atof(s)); break;
         case LAST: push(last); break;
         case '+': push(pop() + pop()); break;
         case '*': push(pop() * pop()); break;
         case '-':
            op2 = pop();
            push(pop() - op2);
            break;
         case '/':
            op2 = pop();
            if (op2 != 0.0) push(pop() / op2);
            else printf("error: zero divisor\n");
            break;
         case '%':
            op2 = pop();
            if (op2 != 0.0) push((int)pop() % (int)op2);
            else printf("error: zero division is undefined\n");
            break;
         case '^':
            op2 = pop();
            push(pow(pop(), op2));
            break;
         case EXP:
            push(exp(pop()));
            break;
         case SINE:
            push(sin(pop()));
            break;
         case '\n':
            last = pop();
            printf("\t%.8g\n", last);
            break;
         default:
            printf("error: unknown command %s\n", s);
            break;
      }
   }
   return 0;
}
