/* Maintains a parts database (array version) */

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "readline.h"

#define NAME_LEN 25
#define NAME_SPACES "                " /* 25-9=16 spaces */
#define MAX_PARTS 100
#define INITIAL_INVENTORY_SIZE 10
#define PART_SPACES "   " /* 3 spaces */

#define TEST_PARTS_NUM 15



struct part {
   int number;
   char name[NAME_LEN + 1];
   int on_hand;
};

struct part test_inventory[TEST_PARTS_NUM] = {
   {1, "aa", 1},
   {2, "bb", 2},
   {3, "cc", 3},
   {4, "dd", 4},
   {5, "ee", 5},
   {6, "ff", 6},
   {7, "gg", 7},
   {8, "hh", 8},
   {9, "ii", 9},
   {10, "jj", 10},
   {11, "kk", 11},
   {12, "ll", 12},
   {13, "mm", 13},
   {14, "nn", 14},
   {15, "oo", 15}
};
int insert_i = 0;

int num_parts = 0; /* number of parts currently stored */
int inventory_size = INITIAL_INVENTORY_SIZE;

struct part *inventory;

int find_part(int number);
void insert(void);
void search(void);
void update(void);
void print(void);

/********************************************************************
 * main: Prompts the user to enter an operation code,               *
 *       then calls a function to perform the requested             *
 *       action. Repeats until the user enters the                  *
 *       command 'q'. Prints an error message if the user           *
 *       enters an illegal code.                                    *
 ********************************************************************/
 int main(void)
 {
    char code;
    inventory = malloc(inventory_size * sizeof(struct part));

    for (; insert_i < TEST_PARTS_NUM;) {
       insert();
       print();
    }

   //  for (;;) {
   //    printf("Enter operation code: ");
   //    scanf(" %c", &code);
   //    while (getchar() != '\n') /* skips to end of line */
   //       ;
   //    switch(code) {
   //       case 'i': insert(); break;
   //       case 's': search(); break;
   //       case 'u': update(); break;
   //       case 'p': print(); break;
   //       case 'q': return 0;
   //       default: printf("Illegal code\n");
   //    }
   //    printf("\n");
   // }
}

/***********************************************************************
 * find_part: Looks up a part number in the inventory array.           *
 *            Returns the array index if the part number is found;     *
 *            otherwise, returns -1.                                   *
 ***********************************************************************/
 int find_part(int number)
 {
    int i;

    for (i = 0; i < num_parts; i++)
      if (inventory[i].number == number) return i;

   return -1;
}

/***********************************************************************
 * insert: Prompts the user for information about a new part and then  *
 *         inserts the part into the database. Prints an error message *
 *         and returns prematurely if the part already exists or the   *
 *          database is full.                                          *
 ***********************************************************************/
//  void insert(void)
//  {
//     int part_number;
//    if (num_parts == inventory_size) {
//       inventory = realloc(inventory, inventory_size * 2);
//       if (inventory == NULL) {
//          printf("Database is full; can't add more parts.\n");
//          return;
//       } else {
//          inventory_size *= 2;
//       }
//    }

//    printf("Enter part number: ");
//    scanf("%d", &part_number);

//    if (find_part(part_number) >= 0) {
//       printf("Part already exists.\n");
//       return;
//    }

//    inventory[num_parts].number = part_number;
//    printf("Enter part name: ");
//    read_line(inventory[num_parts].name, NAME_LEN);
//    printf("Enter quantity on hand: ");
//    scanf("%d", &inventory[num_parts].on_hand);
//    num_parts++;
// }

 void insert(void)
 {
    int part_number;
   if (num_parts == inventory_size) {
      inventory = realloc(inventory, inventory_size * 2);
      if (inventory == NULL) {
         printf("Database is full; can't add more parts.\n");
         return;
      } else {
         inventory_size *= 2;
      }
   }

   inventory[num_parts].number = test_inventory[insert_i].number;
   strcpy(inventory[num_parts].name, test_inventory[insert_i].name);
   inventory[num_parts].on_hand = test_inventory[insert_i].on_hand;
   num_parts++; insert_i++;
}


/***********************************************************************
 * search: Prompts the user to enter a part number, then looks up the  *
           part in the database. If the part exists, prints the name   *
           and quantity on hand; if not, prints an error message.      *
 ***********************************************************************/
 void search(void)
 {
    int i, number;

    printf("Enter part number: ");
    scanf("%d", &number);
    i = find_part(number);
    if (i >= 0) {
      printf("Part name %s\n", inventory[i].name);
      printf("Quantity on hand: %d\n", inventory[i].on_hand);
   } else {
      printf("Part not found.\n");
   }
}

/***********************************************************************
 * update: Prompts the user to enter a part number. Prints an error    *
           message if the part doesn't exist; otherwise, prompts the   *
           user to enter change in quanity on hand and updates the     *
           database.
 ***********************************************************************/
 void update(void)
 {
    int i, number, change;

    printf("Enter part number: ");
    scanf("%d", &number);
    i = find_part(number);
    if (i >= 0) {
      printf("Enter change in quantity on hand: ");
      scanf("%d", &change);
      inventory[i].on_hand += change;
   } else {
      printf("Part not found.\n");
   }
}

/***********************************************************************
 * print: Prints a listing of all parts in the database, showing the   *
 *        part number, part name, and quantity on hand. Parts are      *
 *        printed in the order in which they were entered into the     *
 *        database.                                                    *
 ***********************************************************************/
 void print(void)
 {
    int i;
    printf("Part number" PART_SPACES "Part Name" NAME_SPACES "Quantity on Hand\n");
    for (i = 0; i < num_parts; i++) {
      printf(("%11d" PART_SPACES "%c%-26s" "%14d\n"),
         inventory[i].number, toupper(inventory[i].name[0]), (inventory[i].name + 1), inventory[i].on_hand
      );
   }
}
