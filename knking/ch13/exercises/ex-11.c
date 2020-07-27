#include <stdio.h>
#include <stdbool.h>
// #include <string.h>

int strcmp(char *s, char *t)
{
   while (*s && *t) {
      if (*s != *t) return *s - *t;
      s++; t++;
   }
   return *s - *t;
}

int main(void)
{
   printf("'a' == 'b' => %d\n", strcmp("a", "b"));
   printf("'letladi' == 'sebesho' => %d\n", strcmp("letladi", "sebesho"));
   printf("'macbook-pro' == 'mac' => %d\n", strcmp("macbook-pro", "mac"));

   return 0;
}