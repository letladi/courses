#include <stdio.h>
#include "../ch1/lines.h"
#include "../ch3/to_int.c"
#include "../util.h"
#include "alloc.h"
#define MAXLINES 30
#define LINE_LIMIT 1000
#define DEFAULT_TAIL_VAL 10

int main(int argc, char* argv[])
{
   char *lines[MAXLINES], line[LINE_LIMIT];
   int linelen = 0, lineN = 0;
   while ((linelen = getLine(line, LINE_LIMIT)) > 0) {
      lines[lineN] = alloc(linelen + 1);
      strcpy(lines[lineN], line);
      lineN++;
   }  

   int tail = DEFAULT_TAIL_VAL;
   if (argc >= 2) {
      tail = to_int(argv[1]);
   }

   while (lineN) {
      --lineN;
      int i = 0;
      while (lines[lineN][i]) {
         putchar(lines[lineN][i]);
         i++;
      }
      if (--tail <= 0) break;
   } 

}
