#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_RANKS 13
#define NUM_SUITS 4
#define NUM_CARDS 5
#define SUIT 1
#define RANK 0
#define INVALID_VALUE -1

// int num_in_rank[NUM_RANKS];
// int num_in_suit[NUM_SUITS];
int hand[NUM_CARDS][2];
bool straight, flush, four, three;
int pairs; /* can be 0, 1, or 2 */

void read_cards(void);
void analyze_hand(void);
void print_result(void);
bool card_in_hand(int rank, int suit) {
   for (int i = 0; i < NUM_CARDS; i++) {
      if (hand[i][RANK] == rank && hand[i][SUIT] == suit)
         return true;
   }
   return false;
}

int suit_num(char c)
{
   int suit;
   switch(c) {
      case 'c': case 'C': suit = 0; break;
      case 'd': case 'D': suit = 1; break;
      case 'h': case 'H': suit = 2; break;
      case 's': case 'S': suit = 3; break;
      default:            suit = INVALID_VALUE;
   }
   return suit;
}

int rank_num(char c)
{
   int rank;
   switch(c) {
      case '0':           exit(EXIT_SUCCESS);
      case '2':           rank = 0; break;
      case '3':           rank = 1; break;
      case '4':           rank = 2; break;
      case '5':           rank = 3; break;
      case '6':           rank = 4; break;
      case '7':           rank = 5; break;
      case '8':           rank = 6; break;
      case '9':           rank = 7; break;
      case 't': case 'T': rank = 8; break;
      case 'j': case 'J': rank = 9; break;
      case 'q': case 'Q': rank = 10; break;
      case 'k': case 'K': rank = 11; break;
      case 'a': case 'A': rank = 12; break;
      default:            rank = INVALID_VALUE;
   }
   return rank;
}

/* calls read_cards, analyze_hand, and print_result repeatedly */
int main(void)
{
   for (;;) {
      read_cards();
      analyze_hand();
      print_result();
   }
   
   return 0;
}

/* reads the cards into the external variables
 * num_in_rank and num_in_suit;
 * checks for bad cards and duplicate cards.
*/
void read_cards(void)
{
   // bool card_exists[NUM_RANKS][NUM_SUITS];
   char ch, rank_ch, suit_ch;
   int rank, suit, current_hand = 0;
   bool bad_card;
   int cards_read = 0;

   // for (rank = 0; rank < NUM_RANKS; rank++) {
   //    num_in_rank[rank] = 0;
   //    for (suit = 0; suit < NUM_SUITS; suit++) {
   //       card_exists[rank][suit] = false;
   //    }
   // }
   int i, j;
   for (suit = 0; suit < NUM_SUITS; suit++) {
      // num_in_suit[suit] = 0;

      while (cards_read < NUM_CARDS) {
         bad_card = false;
         printf("Enter a card: ");
         
         rank_ch = getchar();
         rank = rank_num(rank_ch);
         bad_card = rank == INVALID_VALUE;

         suit_ch = getchar();
         suit = suit_num(suit_ch);
         bad_card = suit == INVALID_VALUE;

         while ((ch = getchar()) != '\n') 
            if (ch != ' ') bad_card = true;

         if (bad_card)
            printf("Bad card; ignored.\n");
         else if (card_in_hand(rank, suit))
            printf("Duplicate card; ignored.\n");
         else {
            // num_in_rank[rank]++;
            // num_in_suit[suit]++;
            // card_exists[rank][suit] = true;
            
            j = current_hand;
            i = j - 1;
            while (j > 0 && hand[i][RANK] > rank) {
               hand[j][RANK] = hand[i][RANK];
               hand[j][SUIT] = hand[i][SUIT];
               i--;
               j--;
            }
            hand[j][RANK] = rank;
            hand[j][SUIT] = suit;
            current_hand++;
            cards_read++;
         }
      }
   }
}

bool is_flush(int hand[][2])
{
   int first_suit = hand[0][SUIT];
   for (int i = 1; i < NUM_CARDS; i++) {
      if (hand[i][SUIT] != first_suit) return false;
   }
   return true;
}

bool is_straight(int hand[][2])
{
   const int required_diff = 1;
   int prev_rank = hand[0][RANK], current_rank;
   for (int i = 1; i < NUM_CARDS; i++) {
      current_rank = hand[i][RANK];
      if (abs(current_rank - prev_rank) != required_diff) return false;
      prev_rank = current_rank;
   }
   return true;
}

int count_kinds(int hand[][2])
{
   int max_kind_count = -1;
   int card_rank, current_count;
   int i, j;
   for (i = 0; i < NUM_CARDS; i++) {
      card_rank = hand[i][RANK];
      current_count = 0;
      for (j = i + 1; j < NUM_CARDS; j++) {
         if (hand[j][RANK] == card_rank) current_count++;
      }
      if (current_count > max_kind_count) max_kind_count = current_count;
   }
   return max_kind_count;
}

int count_pairs(int hand[][2])
{
   int count = 0;
   int ret = 0;
   int i, j, card_rank;
   for (i = 0; i < NUM_CARDS; i++) {
      card_rank = hand[i][RANK];
      count = 0;
      for (j = i + 1; j < NUM_CARDS; j++) {
         if (hand[j][RANK] == hand[i][RANK]) count++;
      }
      if (count == 1) ret++;
   }
   return ret;
}

/* 
 * Determines whether the hand contains a straight, a flush, four-of-a-kind,
 * and/or three-of-a-kind; determines the number of pairs; stores the results into the 
 * external variables straight, flush, four, three, and pairs.
*/
void analyze_hand(void)
{
   printf("Cards we have on hand\n ");
   for (int i = 0; i < NUM_CARDS; i++) {
      printf("%d,%d\n", hand[i][RANK], hand[i][SUIT]);
   }
   printf("\n");

   // check for flush
   flush = is_flush(hand);
   // check for straight
   straight = is_straight(hand);
   // check for 4-of-a-kind, 3-of-a-kind, and pairs
   int kind_count = count_kinds(hand);
   four = kind_count == 4;
   three = kind_count == 3;
   pairs = count_pairs(hand);
}

/*
 * Prints the classification of the hand, based on the values of the external
 * variables straight, flush, four, three, and pairs
*/
void print_result(void)
{
   if (straight && flush)           printf("Straight flush");
   else if (four)                   printf("Four of a kind");
   else if (three && pairs == 1)    printf("Full house");
   else if (flush)                  printf("Flush");
   else if (straight)               printf("Straight");
   else if (three)                  printf("Three of a kind");
   else if (pairs == 2)             printf("Two pairs");
   else if (pairs == 1)             printf("Pair");
   else                             printf("High card");

   printf("\n\n");
}