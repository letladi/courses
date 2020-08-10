#include <stdio.h>

#define PRINT_INT(n) printf(#n " = %d\n", n)
#define MK_ID(n) i##n

#define GENERIC_MAX(type) \
type type##__max(type x, type y) \
{                                \
   return x > y ? x : y;         \
}                                \

#define ECHO(s)   \
   do {           \
      gets(s);    \
      puts(s);    \
   } while (0)    \

int main(void)
{
   printf("standard: %ld\n", __STDC_VERSION__);

   return 0;
}