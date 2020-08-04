#include <stdio.h>
#include <ctype.h>

double compute_average_word(const char *sentence)
{
   double avg = 0, len = 0;
   int count = 0;
   char c;
   while (*sentence) {
      if (isspace(*sentence)) {
         avg += len;
         len = 0; count++;
      } else {
         len++;
      }
      sentence++;
   }

   if (len > 0) {
      avg += len;
      count++;
   }
   
   return avg / count;
}

int main(void)
{
   printf("four five six letladi = %.2lf\n", compute_average_word("four five six letladi"));

   return 0;
}