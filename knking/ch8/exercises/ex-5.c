#include <stdio.h>
#define FIB_COUNT 40

int main(void)
{
   long fib_numbers[FIB_COUNT] = { 0, 1 };
   for (int i = 2; i < FIB_COUNT; i++) {
      fib_numbers[i] = fib_numbers[i - 2] + fib_numbers[i - 1];
   }

   return 0;
}