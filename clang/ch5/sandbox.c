#include <stdio.h>

int main()
{
   int m[2][5] = {
      {1, 2, 3, 4, 5},
      {6, 7, 8, 9, 10}
   };

   for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 5; j++) {
         printf("%hi, %hi\n", &m[i][j] , (j + *(m + i)));
      }
   }
}