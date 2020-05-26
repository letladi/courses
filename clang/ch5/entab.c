#include <stdio.h>
#include <stdlib.h>
#include "../ch1/lines.h"

#define TAB '\t'
#define SPACE ' '
#define DEFAULT_TAB_SIZE 4

int main(int argc, char* argv[])
{
   char line[MAXLINE];
   int readLen, c, numstops = DEFAULT_TAB_SIZE;
   if (argc >= 2 && isdigit(argv[1][0])) {
      numstops = atoi(argv[1][0]);
   }
   while ((readLen = getLine(line, MAXLINE)) > 0) {
      size_t spaceCnt = 0;
      for (int i = 0; i < readLen; i++) {
         c = line[i];
         if (spaceCnt >= numstops) {
            spaceCnt -= numstops;
            putchar(TAB);
         }

         if (c == SPACE) spaceCnt++;
         else {
            if (spaceCnt) {
               putchar(SPACE);
               spaceCnt = 0;
            }
            putchar(c);
         }
      }
   }
}
