#import <stdio.h>
#include <stdlib.h>

#define SPACE_TAB_EQUIVALENT 4
 // n should be a symbolic parameter
int main(int argc, char *argv[])
{
   int c, numstops = SPACE_TAB_EQUIVALENT;
   if (argc > 1 && isdigit(argv[1][0])) {
      numstops = atoi(argv[1][0]);
   }
   while ((c = getchar()) != EOF) {
      if (c == '\t') {
         int i = 0; while (i++ < numstops) printf("%c", ' ');
      }
      printf("%c", c);
   }
}
