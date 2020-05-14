#include <stdio.h>
#include "lines.h"

#define TAB '\t'
#define SPACE ' '
#define TABSIZE 4

int main()
{
   char line[MAXLINE];
   int readLen, c;
   while ((readLen = getLine(line, MAXLINE)) > 0) {
      size_t spaceCnt = 0;
      for (int i = 0; i < readLen; i++) {
         c = line[i];
         if (spaceCnt >= TABSIZE) {
            spaceCnt -= TABSIZE;
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
