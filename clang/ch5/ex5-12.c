#include <stdio.h>
#include <stdlib.h>
#include "../ch1/lines.h"

#define TAB '\t'
#define SPACE ' '
#define DEFAULT_TAB_SIZE 4

int main(int argc, char* argv[])
{
   char line[MAXLINE];
   int numstops = DEFAULT_TAB_SIZE;
   int startafter = 0;
   if (argc >= 2 && isdigit(argv[1][0])) {
      while ((++argv)[0]) {
         switch(argv[0][0]) {
            case '-': startafter = atoi(argv[0][1]); break;
            case '+': numstops = atoi(argv[0][1]); break;
         }
      }
   }

   int readLen, c;
   while ((readLen = getLine(line, MAXLINE)) > 0) {
      size_t spaceCnt = 0;
      for (int i = 0; i < readLen; i++) {
         c = line[i];

         if (startafter > 0) {
            putchar("%c", c);
            startafter--;
            continue;
         }

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
