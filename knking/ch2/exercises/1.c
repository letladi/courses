#include <stdio.h>

int main(void)
{
   char c = '*';
   printf("%8c\n", c);
   printf("%7c\n", c);
   printf("%6c\n", c);
   printf("%c%4c\n", c, c);
   printf("%2c%2c\n", c, c);
   printf("%3c\n", c);
   
   return 0;
}