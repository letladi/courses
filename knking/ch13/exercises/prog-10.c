#include <stdio.h>
#include <ctype.h>

#define WORD_LEN 100

void reverse_name(char *name)
{
   int i = 0;
   while (isspace(name[i])) i++;
   char initial = name[i];
   while (!isspace(name[i])) i++;
   while (isspace(name[i])) i++;
   int j = 0;
   while (name[i]) {
      name[j] = name[i];
      i++; j++;
   }
   name[j++] = ',';
   name[j++] = ' ';
   name[j++] = initial;
   name[j++] = '.';
   name[j] = '\0';
}

int main(void)
{
   char c, name[WORD_LEN] = {};
   int i = 0;

   printf("Enter a first and last name: ");
   
   while ((c = getchar()) != '\n') {
      name[i++] = c;
   }
   name[i] = '\0';
   reverse_name(name);
   printf("%s\n", name);

   return 0;
}