/**
 * Output: 
 * Answer: 3
 *  * ✔️
 * one function, f1, has a local variable initialized to zero, which it passed to a function pointer it takes 
 * as an argument and increment the said local variable, if by passing the local variable to passed in function, the result is not zero.
 * [the program tests the values f2(0), f2(1), f2(2), and so on, stopping when f2 returns zero. It then prints the argument that was passed
 * to f2 to make it return zero]
 */

#include <stdio.h>

int f1(int (*f)(int));
int f2(int i);

int main(void)
{
   printf("Answer: %d\n", f1(f2));
   return 0;
}

int f1(int (*f)(int))
{
   int n = 0;
   while ((*f)(n)) n++;
   return n;
}

int f2(int i)
{
   return i*i + i - 12;
}

