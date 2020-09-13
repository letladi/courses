/**
 */

#include <math.h>

struct point { int x, y; };

enum s_kind { RECTANGLE, CIRCLE };

struct shape {
   int shape_kind; /** RECTANGLE or CIRCLE */
   struct point center; /* coordinates of center */
   union {
      struct {
         int height, width;
      } rectangle;
      struct {
         int radius;
      } circle; 
   } u;
} s;

// a) 
double area(struct shape s)
{
   if (s.shape_kind == RECTANGLE) {
      return s.u.rectangle.height * s.u.rectangle.width;
   } else {
      return pow(s.u.circle.radius, 2) * M_PI;
   }
}

// b)
struct shape move(struct shape s, double x, double y)
{
   struct shape ret = s;
   ret.center.x += x;
   ret.center.y += y;
   return ret;
}

// c)
struct shape scale(struct shape s, double c)
{
   struct shape ret = s;
   if (ret.shape_kind == RECTANGLE) {
      ret.u.rectangle.height *= c;
      ret.u.rectangle.width *= c;
   } else {
      ret.u.circle.radius *= c;
   }

   return ret;
}

int main(void)
{
   
}