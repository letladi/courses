#include <stdio.h>

#define LEN 100

int main(void)
{
   char msg[LEN], c;
   char *p = msg;

   printf("Enter a message: ");
   while ((c = getchar()) != '\n' && (p < (msg + LEN))) {
      *p++ = c;
   }

   printf("Reversal is: ");
   while (p > msg) printf("%c", *--p);
   printf("\n");

   return 0;
}