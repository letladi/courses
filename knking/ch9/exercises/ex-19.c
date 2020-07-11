// the function prints an integer as a binary number
#include <stdio.h>

void pb(int n)
{
   if (n != 0) {
      pb(n / 2);
      putchar('0' + n % 2);
   }
}

int main(void)
{
   printf("pb(150) = ");
   pb(150);
   printf("\n");
   return 0;
}