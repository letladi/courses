/** Maintains a parts database (linked list version) */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../../util.h"

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

struct part *find_part(int number);
void insert(void);
void search(void);
void update(void);
void print(void);
void erase(void);

/*******************************************************************************************
 * main: Prompts the user to enter an operation code, then calls a function                *
 *       to perform the requested action. Repeats until the user enters the command 'q'.   *
 *       Prints an error message if the user enters an illegal code.                       * 
 ******************************************************************************************/
 int main(void)
 {
    char code;

    for (;;) {
       printf("Enter operation code: ");
       scanf(" %c", &code);
       while (getchar() != '\n') /* skips to end of line */
         ;
      switch (code) {
         case 'i': insert(); break;
         case 's': search(); break;
         case 'u': update(); break;
         case 'p': print(); break;
         case 'e': erase(); break;
         case 'q': return 0;
         default: printf("Illegal code\n");
      }
      printf("\n");
    }
 }

 /*******************************************************************************************
 * find_part: Looks up a part number in the inventory list. Returns a pointer to the node   *
 *            containing the part number; if the part number is not found, returns NULL.    *
 *******************************************************************************************/
struct part *find_part(int number)
{
   struct part *p;
   for (p = inventory; p != NULL && number > p->number; p = p->next)
      ;
   if (p != NULL && number == p->number)
      return p;

   return NULL;
}

/*******************************************************************************************
 * insert: Prompts the user for information about a new part and then inserts the part     *
 *         into the inventory list; the list remains sorted by part number. Prints an      *
 *         error message and returns prematurely if the part already exists or space       *
 *         could not be allocated for the part                                             * 
 ******************************************************************************************/
void insert(void)
{
   struct part *cur, *prev, *new_node;
   new_node = malloc(sizeof(struct part));
   if (new_node == NULL) {
      printf("Database is full; can't add more parts.\n");
      return;
   }

   printf("Enter part number: ");
   scanf("%d", &new_node->number);

   for (cur = inventory, prev = NULL; 
      cur != NULL && new_node->number > cur->number;
      prev = cur, cur = cur->next
   )
      ;
   if (cur != NULL && new_node->number == cur->number) {
      printf("Part already exists.\n");
      free(new_node);
      return;
   }
   // do {
      printf("Enter part name: ");
      read_line(new_node->name, NAME_LEN);
      // if (strlen(new_node->name)) break;
      // else {
      //    printf("\nName cannot be empty\n");
      // }
   // } while (1);  
   
   printf("Enter quantity on hand: ");
   scanf("%d", &new_node->on_hand);

   new_node->next = cur;
   if (prev == NULL)
      inventory = new_node;
   else 
      prev->next = new_node;
}

/*******************************************************************************************
 * search: Prompts the user to enter a part number, then looks up the part in the database *
 *         If the part exists, prints the name and quantity on hand; if not, prints an     *
 *         error message.                                                                  * 
 ******************************************************************************************/
void search(void)
{
   int number;
   struct part *p;

   printf("Enter part number: ");
   scanf("%d", &number);
   p = find_part(number);
   if (p != NULL) {
      printf("Part name: %s\n", p->name);
      printf("Quantity on hand: %d\n", p->on_hand);
   } else {
      printf("Part not found.\n");
   }
}

/*******************************************************************************************
 * update: Prompts the user to enter a part number. Prints an error message if the part    * 
 *         doesn't exist; otherwise, prompts the user to enter change in quantity on       *
 *         hand and udpates the database.                                                  *
 ******************************************************************************************/
void update(void)
{
   int number, change;
   struct part *p;

   printf("Enter part number: ");
   scanf("%d", &number);
   p = find_part(number);
   if (p != NULL) {
      printf("Enter change in quantity on hand: ");
      scanf("%d", &change);
      p->on_hand += change;
   } else {
      printf("Part not found.\n");
   }
}

/*******************************************************************************************
 * print: Prints a listing of all parts in the database, showing the part number,          *
 *        part name, and quantity on hand. Part numbers will appear in ascending order.    *
 ******************************************************************************************/
void print(void)
{
   struct part *p;
   printf("Part number" PART_SPACES "Part Name" NAME_SPACES "Quantity on Hand\n");
   for (p = inventory; p != NULL; p = p->next)
      printf("%11d" PART_SPACES "%-26s" "%14d\n",
         p->number, p->name, p->on_hand
      );
}

/*******************************************************************************************
 * erase: Prompts a user for a part number and then the given part if it exists,           *
 *        otherwise an error message is displayed.                                         *
 ******************************************************************************************/
void erase(void)
{
   int part_number;
   printf("Enter a part number to delete: ");
   scanf("%d", &part_number);

   struct part* pt = inventory;
   struct part* prev = NULL;
   while (pt) {
      if (pt->number == part_number) break;
      prev = pt;
      pt = pt->next;
   }

   if (pt) { // there's a part to be deleted...
      if (!prev) { // we must delete the head
         inventory = pt->next;
      } else {
         prev->next = pt->next; 
      }
      free(pt);
   } else { // no part with this number exists
      printf("Part does not exist.\n");
   }
}