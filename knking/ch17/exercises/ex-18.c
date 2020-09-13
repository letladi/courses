#include <stdlib.h>

#define NAME_LEN 25
#define NAME_SPACES "                " /* 25-9=16 spaces */
#define MAX_PARTS 100
#define PART_SPACES "   " /* 3 spaces */

struct part {
   int number;
   char name[NAME_LEN+1];
   int on_hand;
   struct part *next;
};

struct part *inventory = NULL; /* points to first part */

int compare_parts(const void *p, const void *q)
{
   const struct part *p1 = p;
   const struct part *q1 = q;

   if (p1->number < q1->number)
      return 1;
   else if (p1->number == q1->number)
      return 0;
   else 
      return -1;
}