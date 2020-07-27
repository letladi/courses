#include <stdio.h>
#include <ctype.h>

// a)
// void capitalize(char str[])
// {
//    int i = 0;
//    while (str[i]) {
//       str[i] = toupper(str[i]);
//       i++;
//    }
// }

// b)
void capitalize(char *str)
{
   while (*str) {
      *str = toupper(*str);
      str++;
   }
}

int main(void)
{
   char name[] = "letladi sebesho";
   capitalize(name);
   printf("%s\n", name);
}
