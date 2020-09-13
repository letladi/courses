#include <stdio.h>
#include <stdbool.h>

#define COLOR_SCALE_FACTOR 0.7

struct color {
   int red;
   int green;
   int blue;
};

int correct_color_value(int val)
{
   if (val < 0) val = 0;
   else if (val > 255) val = 255;

   return val;
}

// a)
struct color make_color(int red, int green, int blue)
{
   return (struct color) {
      .red = correct_color_value(red),
      .green = correct_color_value(green),
      .blue = correct_color_value(blue),
   };
}

// b)
int getRed(struct color c)
{
   return c.red;
}

// c)
bool equal_color(struct color c1, struct color c2)
{
   return c1.red == c2.red &&
      c1.green == c2.green &&
      c1.blue == c2.blue;
}

// d)
bool is_black(struct color c)
{
   return c.red == 0 && c.green == 0 && c.blue == 0;
}

bool is_one_or_two(int i)
{
   return 0 < i && i < 3;
}

struct color brighter(struct color c)
{
   if (is_black(c)) return (struct color){ 3, 3, 3 };
   else {
      if (is_one_or_two(c.red)) c.red = 3;
      if (is_one_or_two(c.green)) c.green = 3;
      if (is_one_or_two(c.blue)) c.blue = 3;
   }

   c.red = correct_color_value(c.red / COLOR_SCALE_FACTOR);
   c.green = correct_color_value(c.green / COLOR_SCALE_FACTOR);
   c.blue = correct_color_value(c.blue / COLOR_SCALE_FACTOR);

   return c;
}

// e)
struct color darker(struct color c)
{
   c.red = correct_color_value(c.red * COLOR_SCALE_FACTOR);
   c.green = correct_color_value(c.green * COLOR_SCALE_FACTOR);
   c.blue = correct_color_value(c.blue * COLOR_SCALE_FACTOR);

   return c;
}

int main(void)
{
   struct color c1 = make_color(155, 120, 55);
   printf("c1.red = %d, c1.green = %d, c1.blue = %d\n", c1.red, c1.green, c1.blue);
   struct color d1 = make_color(-20, 275, 20);
   printf("d1.red = %d, d1.green = %d, d1.blue = %d\n", d1.red, d1.green, d1.blue);
   struct color c2 = make_color(155, 120, 55);
   printf("c1 == c2? %s\n", equal_color(c1, c2) ? "Yes": "No");

   struct color bc1 = brighter(c1);
   printf("bc1.red = %d, bc1.green = %d, bc1.blue = %d\n", bc1.red, bc1.green, bc1.blue);

   struct color bc2 = brighter((struct color){ 220, 100, 2 });
   printf("bc2.red = %d, bc2.green = %d, bc2.blue = %d\n", bc2.red, bc2.green, bc2.blue);

   struct color dd1 = darker((struct color){ 120, 150, 15 });
   printf("dd1.red = %d, dd1.green = %d, dd1.blue = %d\n", dd1.red, dd1.green, dd1.blue);

   return 0;
}