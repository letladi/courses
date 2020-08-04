#include <stdio.h>
#include <string.h>

#define LEN 100

void reverse(char *message);

int main(void)
{
   char msg[LEN] = {0}, c;
   char *p = msg;

   printf("Enter a message: ");
   while ((c = getchar()) != '\n' && (p < (msg + LEN))) {
      *p++ = c;
   }

   printf("Reversal is: ");
   reverse(msg);
   printf("%s\n", msg);

   return 0;
}

void reverse(char *message)
{
   char *p = message + strlen(message) - 1;
   char temp;
   while (p > message) {
      temp = *p;
      *p = *message;
      *message = temp;
      p--; message++;
   }
}