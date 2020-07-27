#include <stdio.h>

int count_spaces(const char *s)
{
   int count = 0;
   while (*s) {
      if (*s == ' ') count++;
      s++;
   }
   return count;
}
// ✔️

int main(void)
{
   printf("count_spaces('letladi') = %d\n", count_spaces("letladi"));
   printf("count_spaces('letladi sebesho') = %d\n", count_spaces("letladi sebesho"));
   return 0;   
}