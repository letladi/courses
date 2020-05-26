#import <stdio.h>
#include <stdlib.h>

#define SPACE_TAB_EQUIVALENT 4
 // n should be a symbolic parameter
int main(int argc, char *argv[])
{
   int c, numstops = SPACE_TAB_EQUIVALENT;
   int startafter = 0;
   if (argc >= 2 && isdigit(argv[1][0])) {
      while ((++argv)[0]) {
         switch(argv[0][0]) {
            case '-': startafter = atoi(argv[0][1]); break;
            case '+': numstops = atoi(argv[0][1]); break;
         }
      }
   }
   while ((c = getchar()) != EOF) {
      if (startafter) {
         startafter--;
         printf("%c", c);
         continue;
      }
      if (c == '\t') {
         int i = 0; while (i++ < numstops) printf("%c", ' ');
      } else {
         printf("%c", c);
      }
   }
}
