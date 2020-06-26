#include <stdio.h>

int main(void)
{
   _Bool in_word;
   char c;
   float len = 0, avg = 0, total = 0, num_words = 0;
   while (1) {
      c = getchar();
      switch(c) {
         case ' ': 
            if (in_word) {
               in_word = 0;
               total += len;
               num_words++;
               len = 0;
            }
            break;

         case '\n': 
            if (in_word) {
               total += len;
               num_words++;
            } 
            goto after_while;

         default: 
            if (!in_word) {
               len = 1;
               in_word = 1;
            } else {
               len++;
            }
            break;
      }
   }

   after_while:
      avg = total / num_words;
      printf("Average word length: %.1f\n", avg);

   return 0;
}