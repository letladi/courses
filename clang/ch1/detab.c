#import <stdio.h>
#define SPACE_TAB_EQUIVALENT 4
 // n should be a symbolic parameter
int main()
{
   int c;
   while ((c = getchar()) != EOF) {
      if (c == '\t') {
         int i = 0; while (i++ < SPACE_TAB_EQUIVALENT) printf("%c", ' ');
      }
      printf("%c", c);
   }
}
