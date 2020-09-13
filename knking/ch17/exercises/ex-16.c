#include <stdio.h>

int sum(int (*f)(int), int start, int end)
{
   int ret = 0;
   while (start <= end) ret += f(start++);
   return ret;
}

int squared(int i)
{
   return i * i;
}

int main(void)
{
   printf("sum(squared, 1, 5) = %d\n", sum(squared, 1, 5));
   return 0;
}