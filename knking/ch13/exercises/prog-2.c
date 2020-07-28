#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_REMIND 50
#define MIN_IN_HR 60
#define MSG_LEN 60
#define TIME_LEN 5

int read_line(char str[], int n);
int get_minutes_from_midnight(char str[]);
int timecmp(int t1, int t2);
int daycmp(char *, char *);

int main(void)
{
   char reminders[MAX_REMIND][MSG_LEN + TIME_LEN + 3];
   char day_str[3], msg_str[MSG_LEN + 1];
   int day, i, j, hr, min, time, num_remind = 0;

   for ( ; ; ) {
      if (num_remind == MAX_REMIND) {
         printf("-- No space left -- \n");
         break;
      }

      printf("Enter day, 24-hour time and reminder: ");
      scanf("%2d", &day);

      // a)
      if (day < 0 || day > 31) {
         printf("day value must be between 1 and 31, you entered %d. Please try again...\n", day);
         continue;
      }

      if (day == 0) break;

      scanf(" %2d:%2d", &hr, &min);
      
      sprintf(day_str, "%2d", day);
      sprintf(msg_str, " %.2d:%.2d  ", hr, min);
      read_line(msg_str + TIME_LEN + 1, MSG_LEN);

      time = hr * MIN_IN_HR + min;
      int day_cmp, time_cmp;
      for (i = 0; i < num_remind; i++) {
         day_cmp = daycmp(day_str, reminders[i]);
          if (day_cmp < 0) break;
          else if (day_cmp == 0) {
             time_cmp = timecmp(time, get_minutes_from_midnight(reminders[i]));
            while (
               i < num_remind &&
               (day_cmp == 0) &&
               (time_cmp = timecmp(time, get_minutes_from_midnight(reminders[i]))) > 0
            ) i++;
            break;
          }
      }
        
      for (j = num_remind; j > i; j--)
         strcpy(reminders[j], reminders[j - 1]);

      strcpy(reminders[i], day_str);
      strcat(reminders[i], msg_str);

      num_remind++;
   }

   printf("\nDay Reminder\n");
   for (i = 0; i < num_remind; i++) printf(" %s\n", reminders[i]);

   return 0;
}

int read_line(char str[], int n)
{
   int ch, i = 0;
   while ((ch = getchar()) != '\n')
      if (i < n) str[i++] = ch;
   str[i] = '\0';
   return i;
}

int get_minutes_from_midnight(char str[])
{
   int time = 0, hr = 0, min = 0;
   int i = 0;
   while (str[i] != ':') i++;

   int j = i - 1;
   hr += str[j--] - '0';
   hr += (str[j] - '0') * 10;
   time += hr * MIN_IN_HR;
   j = i + 2;
   min += str[j--] - '0';
   min += (str[j] - '0') * 10;
   time += min;

   return time;
}

int get_day(char str[])
{
   int i = 0, ret = 0;
   while (!isdigit(str[i])) i++;

   if (str[i] == '\0') return -1;

   if (isdigit(str[i + 1])) {
      ret += (str[i] - '0') * 10;
      i++; 
   }

   ret += str[i] - '0';
   return ret;
}

int daycmp(char t1[], char t2[])
{
   return get_day(t1) - get_day(t2);
}

int timecmp(int t1, int t2)
{
   return t1 - t2;
}