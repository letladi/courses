#include <stdio.h>

#define IN 1 /* inside a word */
#define OUT 0 /* outside a word */

/* count lines, words, and characters in input */

int main()
{
   int c, nl, nw, nc, state;

   state = OUT;
   nl = nw = nc = 0;

   while ((c = getchar()) != EOF) {
      nc++;
      if (c == '\n') ++nl;

      if (c == ' ' || c == '\n' || c == '\t') state = OUT;
      else if (state == OUT) {
         state = IN;
         nw++;
      }
   }

   printf("%d %d %d\n", nl, nw, nc);
}

/* exercise 1-11.
- I would be interested to input many spaces and see how the program under those circumstances
- I would enter input that fills only one line,
- input wilt multiple single character words,
- input with multiple lines.
*/
