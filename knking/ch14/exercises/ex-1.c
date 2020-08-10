#include <stdio.h>
// a)
#define cube(x) ((x)*(x)*(x))
// b)
#define mod4(x) ((x) % 4)
// c)
#define strange_product(x,y) ((int) (((x) * (y)) < 100))

/*
   - cube always works for numbers; assuming the final's product is not 
   larger than the largest number that can be stored.
   - mod4 works for integer values
   - strange_product works for number values
   - all three functions fail if given an argument that is not a number
*/

int main(void)
{
   printf("cube(3) = %d\n", cube(3));
   printf("mod4(10) = %d\n", mod4(10));
   printf("strange_product(10, 9) = %d\n", strange_product(10, 9));

   return 0;
}