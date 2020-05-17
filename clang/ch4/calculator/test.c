#include <stdio.h>

void fn() {
   static int c;
   printf("c = %c (number %d)\n", c, c);
   c = 's';
}

int main()
{
   fn();
   fn();
}
