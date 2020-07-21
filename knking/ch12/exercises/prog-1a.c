#include <stdio.h>

#define LEN 100

int main(void)
{
   char msg[LEN], c;
   int count = 0;

   printf("Enter a message: ");
   while ((c = getchar()) != '\n' && (count < LEN)) {
      msg[count++] = c;
   }

   printf("Reversal is: ");
   while (count > 0) printf("%c", msg[--count]);
   printf("\n");

   return 0;
}