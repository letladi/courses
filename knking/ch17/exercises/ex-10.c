#include <stdio.h>

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

void print_part(struct part *p)
{
   printf("Part number: %d\n", p->number);
   printf("Part name: %s\n", p->name);
   printf("Quantity on hand: %d\n", p->on_hand);   
}
