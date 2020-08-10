/*
   "ident "foo"" ❌ #pragma ident "foo"
*/

#include <stdio.h>

#define IDENT(x) PRAGMA(ident #x)
#define PRAGMA(x) _Pragma(#x)

int main(void)
{
   int foo = 2;
   IDENT(foo);

   return 0;
}