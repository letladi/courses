#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#define LEN 10
#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3
#define MOVE_COUNT 4
#define FIRST_STEP 'A'
#define LAST_STEP 'Z'
#define EMPTY_VAL '.'

int main(void)
{
   char walk[LEN][LEN];
   for (int i = 0; i < LEN; i++) {
      for (int j = 0; j < LEN; j++) walk[i][j] = EMPTY_VAL;
   }

   srand((int) time(NULL));
   int nextDir, stepNum, firstDir;
   bool can_move = true;
   int repeating_attempt = 0, row = 0, col = 0;
   int new_row = row, new_col = col;

   walk[row][col] = FIRST_STEP;
   stepNum = 1;

   while (1) {
      choose_move:
         nextDir = rand() % MOVE_COUNT;
         firstDir = nextDir;
         repeating_attempt = 1;

      // loop until we can make a legal move
      while (1) {
         find_new_position:
            switch(nextDir) {
               case UP:
                  new_row = row - 1; break;
               case DOWN:
                  new_row = row + 1; break;
               case LEFT:
                  new_col = col - 1; break;
               case RIGHT:
                  new_col = col + 1; break;
            }
            
         bool new_positions_in_range = (0 <= new_row && new_row < LEN) && (0 <= new_col && new_col < LEN);
         bool spot_empty = walk[new_row][new_col] == EMPTY_VAL;
         // 1. verify that we can make the move (range-wise), 
         if (new_positions_in_range && spot_empty) {
            // 2. if we can make the move and the spot is empty, fill with next letter
            walk[new_row][new_col] = FIRST_STEP + stepNum++;
            // 3. if the recently filled letter is the last one, 'Z', break out of both loops
            if (walk[new_row][new_col] == LAST_STEP) goto after_walk_generation;
            col = new_col;
            row = new_row;
            break;
         } else {
            // 4. if we can't make the move range-wise or the spot is not empty
            // 5. go to the next direction clockwise
            nextDir = (nextDir + 1) % MOVE_COUNT;
            // 6. if our next direction is the same as the first, the move is not possible
            // we must therefore break out of the loop
            if ((nextDir == firstDir) && repeating_attempt >= MOVE_COUNT) {
               goto after_walk_generation;
            }
            // 7. note that we are about to repeat moves
            repeating_attempt++;
            // 8. reset new row and column values
            new_row = row;
            new_col = col;
         }
         
      }
   }
   after_walk_generation:
      for (int i = 0; i < LEN; i++) {
         for (int j = 0; j < LEN; j++) {
            printf("%c ", walk[i][j]);
         }
         printf("\n");
      }

   return 0;
}