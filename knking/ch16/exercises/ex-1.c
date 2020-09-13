/* 
   the declarations are both legal and can both appear in a program together.
   This is because the integers x and y both live in their respective structures.
*/
#include <stdio.h>

struct { int x, y; } x = {2};
struct { int x, y; } y = {0, 2};

int main(void)
{
   printf("x.x = %d\n", x.x);
   printf("y.x = %d\n", y.x);
   return 0;
}