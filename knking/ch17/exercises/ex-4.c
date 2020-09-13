#include <stdio.h>
#include <stdlib.h>

struct point { int x, y; };
struct rectangle { struct point upper_left, lower_right; };
struct rectangle *p;

int main(void)
{
   p = malloc(sizeof(struct rectangle));
   p->upper_left = (struct point){10, 25};
   p->lower_right = (struct point){20, 15};
   
   printf("p.upper_left: (%d,%d)\n", p->upper_left.x, p->upper_left.y);
   printf("p.lower_right: (%d,%d)\n", p->lower_right.x, p->lower_right.y);

   return 0;
}