#include <stdio.h>
#define LEN 5

#define QUIZ_VALUES 4
#define QUIZ_TOTAL 0
#define QUIZ_AVG 1
#define QUIZ_LOW_SCORE 2
#define QUIZ_HIGH_SCORE 3
#define QUIZ_SCORE_MAX 100

int main(void)
{
   double grades[LEN][LEN] = {0};
   double quiz_data[LEN][QUIZ_VALUES] = {
      { [QUIZ_LOW_SCORE] = QUIZ_SCORE_MAX },
      { [QUIZ_LOW_SCORE] = QUIZ_SCORE_MAX },
      { [QUIZ_LOW_SCORE] = QUIZ_SCORE_MAX },
      { [QUIZ_LOW_SCORE] = QUIZ_SCORE_MAX },
      { [QUIZ_LOW_SCORE] = QUIZ_SCORE_MAX }
   };
   for (int i = 0; i < LEN; i++) {
      printf("Enter student %d grades for quiz [1, 2, 3, 4, 5]: ", i + 1);
      for (int j = 0; j < LEN; j++) {
         scanf(" %lf", &grades[i][j]);
      }
      printf("\n");
   }

   double total = 0, 
      avg = 0,
      quiz_score = 0;
      
   printf("Student | Total | Average\n");
   for (int i = 0; i < LEN; i++) {
      for (int j = 0; j < LEN; j++) {
         total += grades[i][j];
         quiz_score = grades[j][i];
         if (quiz_score < quiz_data[i][QUIZ_LOW_SCORE]) {
            quiz_data[i][QUIZ_LOW_SCORE] = quiz_score;
         }
         if (quiz_score > quiz_data[i][QUIZ_HIGH_SCORE]) {
            quiz_data[i][QUIZ_HIGH_SCORE] = quiz_score;
         }
         quiz_data[i][QUIZ_TOTAL] += quiz_score;
      }
      quiz_data[i][QUIZ_AVG] = quiz_data[i][QUIZ_TOTAL] / LEN;

      avg = total / LEN;
      printf("%-8d|%7.1f|%8.1f\n", i + 1, total, avg);

      avg = total = quiz_score = 0;
   }

   printf("\nQuiz | Average | Lowest Score | Highest Score\n");
   for (int i = 0; i < LEN; i++) {
      printf(
         "%4d | %7.1f | %12.1f | %13.1f\n", 
         i + 1, 
         quiz_data[i][QUIZ_TOTAL] / LEN, 
         quiz_data[i][QUIZ_LOW_SCORE],
         quiz_data[i][QUIZ_HIGH_SCORE]
      );
   }

   return 0;
}