#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *concat(const char *s1, const char *s2)
{
   char *result;

   result = malloc(strlen(s1)+strlen(s2)+1);
   if (result == NULL) {
      printf("Error: malloc failed in concat\n");
      exit(EXIT_FAILURE);
   }
   strcpy(result, s1);
   strcpy(result, s2);
   return result;
}

int main(void)
{
   struct point { int x, y; } *p;
   p = calloc(1, sizeof(struct point));
   printf("p: (%d,%d)\n", p->x, p->y);

   return 0;
}