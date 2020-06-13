/* (where 's' is space)
   (a) ssss86, 1040 ✔️
   (b) 0.30253e+2 ❌ 3.02530e+01
   (c) 83.1620 ✔️
   (d) 9.97e-7 ❌1e-06
*/
#include <stdio.h>

int main(void)
{
   printf("%6d, %4d\n", 86, 1040);
   printf("%12.5e\n", 30.253);
   printf("%.4f\n", 83.162);
   printf("%-6.2g\n", .0000009979);

   return 0;
}