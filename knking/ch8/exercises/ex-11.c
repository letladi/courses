#include <stdio.h>

#define ROWS 8
#define COLS 8

int main(void)
{
   char checker_board[ROWS][COLS];

   for (int i = 0; i < ROWS; i++) {
      for (int j = 0; j < COLS; j++) {
         checker_board[i][j] = ((i + j) % 2 == 0) ? 'B' : 'R';
      }
   }

   return 0;
}