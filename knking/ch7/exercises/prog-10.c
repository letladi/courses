#include <stdio.h>
#include <ctype.h>

int main(void)
{
   int v_count = 0;
   char c;
   printf("Enter a sentence: ");
   while (1) {
      scanf("%c", &c);
      if (c == '\n') break;
      c = toupper(c);
      switch(c) {
         case 'A': case 'B': case 'C': case 'E': case 'I': case 'O':
            v_count++;
      }
   }

   printf("Your sentence contains %d vowels\n", v_count);

   return 0;
}