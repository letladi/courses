#include <stdio.h>
#include <stdbool.h>
#define EMPTY_SPOT 0

int main(void)
{
   printf("This program creates a magic square of the specified size.");

   int n;
   bool is_even = false;

   do {
      if (is_even) {
         printf("\nIncorrect size entry. Please enter an odd number between 1 and 99: ");
      } else {
         printf("\nThe size must be an odd number between 1 and 99. Enter size of magic square: ");
      }
      scanf(" %d", &n);
      is_even = n % 2 == 0;
   } while (is_even);

   int magic_square[n][n];
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) magic_square[i][j] = EMPTY_SPOT;
   }

   int x = 1, n_squared = n * n;
   int row = 0 , col = n / 2;
   int r, c;
   bool row_in_range, col_in_range;
   
   while (x <= n_squared) {
      r = row;
      c = col;

      if (x == 1) {
         magic_square[row][col] = x++;
      } else {
         // get next index, up and to the right of the current one
         row--;
         col++;
         row_in_range = (0 <= row && row < n);
         col_in_range = (0 <= col && col < n);

         if (!row_in_range || !col_in_range) {
            row = row_in_range ? row : (n - 1);
            col = col_in_range ? col : 0;
         } 

         if (magic_square[row][col] != EMPTY_SPOT) {
            row = r + 1;
            col = c;
         } 
         magic_square[row][col] = x++;
      }
   }

   for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
         printf("%4d", magic_square[i][j]);
      }
      printf("\n");
   }

   return 0;
}