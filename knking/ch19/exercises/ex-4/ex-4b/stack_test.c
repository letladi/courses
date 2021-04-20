#include <stdio.h>
#include <assert.h>
#include "../stack.h"

int main(void)
{
   Stack s = create(sizeof(double));
   double a = 10;
   double b = 20;
   double c = 30;
   double d = 40;
   double e = 50;
   double f = 60;

   assert(is_empty(s));

   push(s, &a);
   assert(top(s) == &a);
   assert(!is_empty(s));
   push(s, &b);
   assert(top(s) == &b);
   push(s, &c);
   assert(top(s) == &c);
   push(s, &d);
   assert(top(s) == &d);
   push(s, &e);
   assert(top(s) == &e);
   assert(!is_full(s));

   push(s, &f);

   assert(!is_full(s));

   assert(pop(s) == &f);

   make_empty(s);

   assert(is_empty(s));
   assert(!is_full(s));

   printf("The stack works!!\n");

   return 0;
}
