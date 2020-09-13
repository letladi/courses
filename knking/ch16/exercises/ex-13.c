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

/**
 * a) legal
 * b) legal
 * c) illegal
 * s.u.rectangle.height = 25;
 * d) legal
 * e) illegal
 * s.u.circle.radius = 5;
 * f) illegal
 * s.u.circle.radius = 5;
*/  

int main(void) 
{
   // s.shape_kind = RECTANGLE; // a)
   // s.center.x = 10; // b) 
   // s.height = 25; // c)
   // s.u.rectangle.width = 8; // d)
   // s.u.circle = 5; // e)
   // s.u.radius = 5; f)
}