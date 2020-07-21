#include <stdio.h>

#define LEN 100

int main(void)
{
   char msg[LEN], c;
   char *p = msg, *end = (msg + LEN);
   int i = 0;

   printf("Enter a message: ");
   while ((c = getchar()) != '\n' && ((msg + i) < end)) {
      *(msg + i++) = c;
   }

   printf("Reversal is: ");
   while ((msg + i) > msg) {
      i--;
      printf("%c", *(msg + i));
   }
   printf("\n");

   return 0;
}