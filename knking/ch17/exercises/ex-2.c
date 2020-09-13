#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// char* duplicate(char val[])
// {
//    char *dup = malloc(strlen(val));
//    if (dup == NULL) {
//       return NULL;
//    } else {
//       strcpy(dup, val);
//       return dup;
//    }
// }

char *duplicate(const char *s)
{
   char *temp = malloc(strlen(s) + 1);
   if (temp == NULL) return NULL;
   strcpy(temp, s);
   return temp;
}