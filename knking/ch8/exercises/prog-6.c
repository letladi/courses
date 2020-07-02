#include <stdio.h>
#include <ctype.h>
#define MSG_LEN 1000

int main(void)
{
   printf("Enter message: ");
   int msg[MSG_LEN];
   char c;
   int n = 0;
   while (n < MSG_LEN) {
      c = getchar();
      if (c == '\n') break;
      c = toupper(c);
      switch(c) {
         case 'A': c = '4'; break;
         case 'B': c = '8'; break;
         case 'E': c = '3'; break;
         case 'I': c = '1'; break;
         case 'O': c = '0'; break;
         case 'S': c = '5'; break;
      }
      msg[n++] = c;
   }
   printf("In B1FF-speak: ");
   for (int i = 0; i < n; i++) {
      printf("%c", msg[i]);
   }
   printf("!!!!!!!!!!\n");

   return 0;
}