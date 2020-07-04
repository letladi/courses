#include <stdio.h>
#include <ctype.h>
#define NUM_LEN 15

int main(void)
{
   char num_chars[NUM_LEN];
   
   printf("Enter phone number: ");
   int count = 0;
   char c;
   while (1) {
      c = getchar();
      if (c == '\n') break;
      c = toupper(c);

      switch (c) {
         case 'A': case 'B':case 'C': c = '2'; break;
         case 'D': case 'E': case 'F': c = '3'; break;
         case 'G': case 'H': case 'I': c = '4'; break;
         case 'J': case 'K': case 'L': c = '5'; break;
         case 'M': case 'N': case 'O': c = '6'; break;
         case 'P': case 'R': case 'S': c = '7'; break;
         case 'T': case 'U': case 'V': c = '8'; break;
         case 'W': case 'X': case 'Y': c = '9'; break;
      }
      num_chars[count++] = c;
   }

   int j = 0;
   while (j <= count) {
      printf("%c", num_chars[j++]);
   }
   printf("\n");
   
   return 0;
}