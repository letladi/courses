#include <stdio.h>

int main()
{
   int c, nc = 0;

   while ((c = getchar()) != EOF) {
      if (c == ' ' || c == '\n' || c == '\t') {
         if (nc) putchar('\n');
         nc = 0;
      } else {
         putchar(c);
         nc++;
      }
   }
}
