#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_REMIND 50 /* maximum number of reminders */
#define MSG_LEN 60 /* max length of reminder message */

int read_line(char str[], int n);

typedef struct item {
   int len;
   char value[];
} item;

int main(void)
{
   // char *reminders[MAX_REMIND];
   item *reminders[MAX_REMIND];
   char day_str[3], msg_str[MSG_LEN+1];
   int day, i, j, num_remind = 0;

   for (;;) {
      if (num_remind == MAX_REMIND) {
         printf("-- No space left --\n");
         break;
      }

      printf("Enter day and reminder: ");
      scanf("%2d", &day);
      if (day == 0) break;
      sprintf(day_str, "%2d", day);
      read_line(msg_str, MSG_LEN);

      for (i = 0; i < num_remind; i++) {
         // if (strcmp(day_str, reminders[i]) < 0) break;
         if (strcmp(day_str, reminders[i]->value)) break;
      }

      for (j = num_remind; j > i; j--) {
         reminders[j] = reminders[j-1];
      }

      // reminders[i] = malloc(2 + strlen(msg_str) + 1);
      reminders[i] = malloc(sizeof(item) + 2 + strlen(msg_str) + 1);
      if (reminders[i] == NULL) {
         printf("-- No space left --\n");
         break;
      }

      strcpy(reminders[i]->value, day_str);
      strcat(reminders[i]->value, msg_str);

      num_remind++;
   }

   printf("\nDay Reminder\n");
   for (i = 0; i < num_remind; i++) {
      printf(" %s\n", reminders[i]->value);
   }

   return 0;
}

int read_line(char str[], int n)
{
   int ch, i = 0;
   while ((ch = getchar()) != '\n' && (i < n)) {
      str[i++] = ch;
   }
   str[i] = '\0';
   return i;
}