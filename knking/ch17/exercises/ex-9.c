/**
 * True. (&x) is a pointer to x. (&x)->a accesses is a pointer operator
 * to access a property of x
 */

#include <stdio.h>

struct x {
   int i;
} xie = {10};

int main(void)
{
   printf("x.i = %d\n", xie.i);
   printf("(&x)->i = %d\n", (&xie)->i);

   return 0;
}