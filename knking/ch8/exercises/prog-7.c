#include <stdio.h>
#define LEN 5
int main(void)
{
   int nums[LEN][LEN] = {0};
   for (int i = 0; i < LEN; i++) {
      printf("Enter row %d: ", i + 1);
      for (int j = 0; j < LEN; j++) {
         scanf(" %d", &nums[i][j]);
      }
      printf("\n");
   }

   int sum = 0;
   printf("Row totals: ");
   for (int i = 0; i < LEN; i++) {
      for (int j = 0; j < LEN; j++) {
         sum += nums[i][j];
      }  
      printf("%d ", sum);
      sum = 0;
   }
   printf("\n");

   printf("Column totals: ");
   for (int i = 0; i < LEN; i++) {
      for (int j = 0; j < LEN; j++) {
         sum += nums[j][i];
      }
      printf("%d ", sum);
      sum = 0;
   }
   printf("\n");

   return 0;
}