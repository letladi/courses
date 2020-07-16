#include <stdio.h>
#include <stdbool.h>

#define MAX_DIGITS 10
#define DEC_DIGIT_CNT 10
#define NUM_SEGMENTS 11
#define H_SEGMENT_CNT 4
#define V_SEGMENT_CNT 1
#define NUM_ROWS 5

#define SEG_0 0
#define SEG_1 1
#define SEG_2 2
#define SEG_3 3
#define SEG_4 4
#define SEG_5 5
#define SEG_6 6
#define SEG_7 7
#define SEG_8 8
#define SEG_9 9
#define SEG_10 10   

#define SPACE_4 "    "
#define SINGLE_SPACE " "
#define BAR_SYM "|"
#define UNDERSCORE_4 "____"

/*
   A number has 11 segments and 5 rows
         0  ____  row 0
      1, 2 |    | row 1
   3, 4, 5 |____| row 2
      6, 7 |    | row 3
  8, 9, 10 |____| row 4                   
*/
const bool segments[DEC_DIGIT_CNT][NUM_SEGMENTS] = {
   {1 , 1, 1, 1, 0, 1, 1, 1, 1, 1, 1}, // 0
   {0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1}, // 1
   {1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 0}, // 2
   {1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 1}, // 3
   {0, 1, 1, 1, 1, 1, 0, 1, 0, 0, 1}, // 4
   {1, 1, 0, 1, 1, 0, 0, 1, 0, 1, 1}, // 5
   {1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1}, // 6
   {1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1}, // 7
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, // 8
   {1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1} // 9
};

int numbers[MAX_DIGITS] = {0};

void print_num_row(int n, int row)
{
   // each column must occupy a fix amount of space 6 spaces
   switch(row) {
      case 0: 
         if (segments[n][SEG_0]) printf(SINGLE_SPACE UNDERSCORE_4);
         else printf(SINGLE_SPACE SPACE_4);
         printf(SINGLE_SPACE);
         break; 
      case 1:
         if (segments[n][SEG_1]) printf(BAR_SYM);
         else printf(SINGLE_SPACE);
         
         printf(SPACE_4);

         if (segments[n][SEG_2]) printf(BAR_SYM);
         else printf(SINGLE_SPACE);
         break; 
      case 2:
         if (segments[n][SEG_3]) printf(BAR_SYM);
         else printf(SINGLE_SPACE);
         if (segments[n][SEG_4]) printf(UNDERSCORE_4);
         else printf(SPACE_4);

         if (segments[n][SEG_5]) printf(BAR_SYM);
         else printf(SINGLE_SPACE);
         break; 
      case 3:
         if (segments[n][SEG_6]) printf(BAR_SYM);
         else printf(SINGLE_SPACE);

         printf(SPACE_4);
         if (segments[n][SEG_7]) printf(BAR_SYM);
         else printf(SINGLE_SPACE);
         break; 
      case 4:
         if (segments[n][SEG_8]) printf(BAR_SYM);
         else printf(SINGLE_SPACE);
         if (segments[n][SEG_9]) printf(UNDERSCORE_4);
         else printf(SPACE_4);

         if (segments[n][SEG_10]) printf(BAR_SYM);
         else printf(SINGLE_SPACE);
         break;
   }
}

void clear_digits_array(int arr[MAX_DIGITS])
{
   for (int i = 0; i < MAX_DIGITS; i++) {
      arr[i] = 0;
   }
}

int main(void)
{
   printf("Enter a number: ");
   char c;
   bool is_num;
   int read = 0;
   clear_digits_array(numbers);

   while ((c = getchar()) != '\n' && (read < MAX_DIGITS)) {
      is_num = '0' <= c && c <= '9';
      if (is_num) {
         numbers[read++] = c - '0';
      }
   }  

   for (int i = 0; i < NUM_ROWS; i++) {
      for (int j = 0; j < read; j++) {
         print_num_row(numbers[j], i);
         printf(SINGLE_SPACE);
      }
      printf("\n");
   }
   printf("\n");

   return 0;
}