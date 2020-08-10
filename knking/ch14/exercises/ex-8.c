#include <stdio.h>

#define VAL(x) x
#define STR(x) #x
#define STR2(x) STR(x)
#define COMBINE(a, b, c, d) (a b c d)
// #define LINE_FILE ("Line " STR( __LINE__) " of file " STR(__FILE__)) // first incorrect solution
// #define LINE_FILE COMBINE("Line ",STR(__LINE__)," of file ",STR(__FILE__)) // second incorrect solution
// #define LINE_FILE COMBINE("Line ",STR(__LINE__)," of file ",STR(__FILE__))
// #define LINE_FILE ("Line " STR2( __LINE__) " of file " STR2(__FILE__)) // correct, but shows filename with double quotes
// #define LINE_FILE ("Line " STR2( __LINE__) " of file " VAL(__FILE__)) // ✔️
// #define LINE_FILE ("Line " STR2( __LINE__) " of file " __FILE__) // ✔️✔️
#define LINE_FILE ("Line " STR( __LINE__) " of file " __FILE__) // ✔️✔️✔️

int main(void)
{
   printf("LINE_FILE = %s\n", LINE_FILE);
   return 0;
}