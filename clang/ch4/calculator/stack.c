#include <stdio.h>
#include "stack.h"

#define MAXVAL 100 // maximum depth of val stack
int sp = 0; // next free stack position
double val[MAXVAL]; // value stack

void push(double f)
{
   if (sp < MAXVAL) val[sp++] = f;
   else
      printf("error: stack full, can't push %g\n", f);
}

double pop(void)
{
   if (sp > 0) return val[--sp];
   else {
      printf("error: stack empty\n");
      return 0.0;
   }
}

double top(void)
{
   if (sp > 0) return val[sp - 1];
   else {
      printf("error: stack empty\n");
      return 0.0;
   }
}

void clear()
{
   int sp = 0;
}

void swap_top()
{
   if (sp > 1) {
      double temp = val[sp - 1];
      val[sp - 1] = val[sp - 2];
      val[sp - 2] = temp;
   } else printf("error: no elements to swap");
}
