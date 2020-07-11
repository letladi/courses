#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#define DIE_SIDE_CNT 6
#define WINNING_MSG "You win!\n"
#define LOSING_MSG "You lose!\n"


int roll_dice(void)
{
   return (1 + (rand() % DIE_SIDE_CNT)) + (1 + (rand() % DIE_SIDE_CNT));
}

bool play_game()
{
   int current_roll, point;

   bool has_won, 
        has_lost, 
        on_first_roll;

   while (true) {
      current_roll = roll_dice();
      printf("You rolled: %d\n", current_roll);
      if (on_first_roll) {
         if (current_roll == 7 || current_roll == 11) {
            printf(WINNING_MSG);
            has_won = true;
         } else if (current_roll == 2 || current_roll == 3 || current_roll == 12) {
            printf(LOSING_MSG);
            has_lost = true;
         } else {
            point = current_roll;
            printf("Your point is %d\n", point);
         }
         on_first_roll = false;
      } else {
         if (current_roll == point) {
            printf(WINNING_MSG);
            has_won = true;
         } else if (current_roll == 7) {
            printf(LOSING_MSG);
            has_lost = true;
         }
      }

      if (has_won || has_lost) return has_won;
   }
}

int main(void)
{
   int num_wins = 0, num_losses = 0;
   bool has_won;
   char user_response;
   srand(time(NULL));
   play_game();

   while (true) {
      has_won = play_game();
      if (has_won) num_wins++;
      else num_losses++;

      printf("Play again? ");
      scanf(" %c", &user_response);
      printf("\n");

      printf("user response: %c\n", user_response);

      if (user_response != 'y' && user_response != 'Y') break;
   }

   printf("Wins: %d, Losses: %d\n", num_wins, num_losses);

   return 0;
}