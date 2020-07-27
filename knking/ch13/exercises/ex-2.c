/**
 * a) is illegal. p is a pointer to a character, putchar expects 
 * an actual character.
 * b) is legal. Output: "a"
 * c) legal. Output: "abc"
 * d) illegal, *p is a character, puts expects a string
*/

#include <stdio.h>

int main(void)
{
   char *p = "abc";
   // a) ✔️
   // putchar(p);
   // b) ✔️
   // putchar(*p);
   // c) ✔️
   // puts(p);
   // d)
   // puts(*p);

   return 0;
}