#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct point { int x, y; };
struct rectangle { struct point upper_left, lower_right; };

// a)
int area(struct rectangle r)
{
   int width = abs(r.lower_right.x - r.upper_left.x);
   int height = abs(r.lower_right.y - r.upper_left.y);
   return width * height;
}

// b)
struct point center(struct rectangle r)
{
   return (struct point) {
      .x = (r.upper_left.x + r.lower_right.x) / 2,
      .y = (r.upper_left.y + r.lower_right.y) / 2,
   };
}

// c)
struct rectangle transform(struct rectangle r, int x, int y)
{
   r.upper_left.x += x; r.lower_right.x += x;
   r.upper_left.y += y; r.lower_right.y += y;

   return r;
}

// d)
bool contains(struct rectangle r, struct point p)
{
   return (
      r.upper_left.x <= p.x && p.x <= r.lower_right.x &&
      r.upper_left.y <= p.y && p.y <= r.lower_right.y
   );
}

int main(void)
{
   // a)
   struct point a = {10, 10};
   struct point b = {80, 52};
   struct rectangle rect = { .upper_left = a, .lower_right = b };

   printf("area = %d\n", area(rect));
   struct point c = center(rect);
   printf("center = (%d, %d)\n", c.x, c.y);
   struct rectangle moved = transform(rect, 80, 80);
   printf("new position x1,y1: (%d,%d); x2,y2: (%d,%d)\n", moved.upper_left.x, moved.upper_left.y, moved.lower_right.x, moved.lower_right.y);

   printf("(30, 40) in rect? %s\n", contains(rect, (struct point){30, 40}) ? "Yes" : "No");
   printf("(30, 60) in rect? %s\n", contains(rect, (struct point){30, 60}) ? "Yes" : "No");

   return 0;
}