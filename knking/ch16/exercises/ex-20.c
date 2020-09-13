#include <stdio.h>

enum {NORTH, SOUTH, EAST, WEST} direction;

int main(void)
{
   int x = 1, y = 2;
   direction = SOUTH;
   switch(direction) {
      case NORTH: y--; break;
      case SOUTH: y++; break;
      case EAST: x++; break;
      case WEST: x--; break;
   }

   printf("x = %d, y = %d\n", x, y);

   return 0;
}