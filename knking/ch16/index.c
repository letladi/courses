#include <stdio.h>
#include <string.h>

typedef struct {
   int number;
   char name[20];
   int on_hand;
} Part;

struct part {
   int number;
   char name[20];
   int on_hand;
};

void print_part(struct part p)
{
   printf("Part number: %d\n", p.number);
   printf("Part name: %s\n", p.name);
   printf("Quantity on hand: %d\n", p.on_hand);
}

struct part build_part(int number, const char *name, int on_hand)
{
   struct part p;

   p.number = number;
   strcpy(p.name, name);
   p.on_hand = on_hand;
   return p;
}

int main(void)
{
   struct name {
      char name[10];
   } st1, st2 = { .name = "Letladi"};

   st1 = (struct name) { .name = "Sebesho"};
   printf("name 1 = %s\n", st1.name);
   st1.name[3] = 'x';
   printf("name 2 = %s\n", st2.name);
   printf("name 1 again = %s\n", st1.name);
   return 0;
}
