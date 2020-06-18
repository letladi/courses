/*
   the statement is legal
   the if statement is not executed when n is 5
*/

#include <stdio.h>

int main(void)
{
   int n = 5;
   if (n == 1 - 10)
      printf("n is between 1 and 10\n");

   return 0;
}