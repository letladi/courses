#include <stdio.h>

int main(void)
{
   int r00, r01, r02, r03;
   int r10, r11, r12, r13;
   int r20, r21, r22, r23;
   int r30, r31, r32, r33;

   printf("Enter the numbers from 1 to 16 in any order:\n");
   scanf("%d%d%d%d", &r00, &r01, &r02, &r03);
   scanf("%d%d%d%d", &r10, &r11, &r12, &r13);
   scanf("%d%d%d%d", &r20, &r21, &r22, &r23);
   scanf("%d%d%d%d", &r30, &r31, &r32, &r33);

   printf("%2d %2d %2d %2d\n", r00, r01, r02, r03);
   printf("%2d %2d %2d %2d\n", r10, r11, r12, r13);
   printf("%2d %2d %2d %2d\n", r20, r21, r22, r23);
   printf("%2d %2d %2d %2d\n", r30, r31, r32, r33);

   printf("Row sums: %d %d %d %d\n", 
      r00 + r01 + r02 + r03,
      r10 + r11 + r12 + r13,
      r20 + r21 + r22 + r23,
      r30 + r31 + r32 + r33
   );
   printf("Column sums: %d %d %d %d\n",
      r00 + r10 + r20 + r30,
      r01 + r11 + r21 + r31,
      r02 + r12 + r22 + r32,
      r03 + r13 + r23 + r33
   );
   printf("Diagonal sums: %d %d\n",
      r00 + r11 + r22 + r33,
      r03 + r12 + r21 + r30
   );

   return 0; 
}