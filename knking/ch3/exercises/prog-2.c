#include <stdio.h>

int main(void)
{
   int id;
   float price;
   int d, m, y;

   printf("Enter item number: ");
   scanf("%d", &id);
   printf("Enter unit price: ");
   scanf("%f", &price);
   printf("Enter purchase date (mm/dd/yyyy): ");
   scanf("%d / %d / %d", &m, &d, &y);
   printf("Item\t\tUnit\t\tPurchase\n");
   printf("\t\tPrice\t\tDate\n");
   printf("%-d\t\t$ %4.2f\t\t%d/%d/%d\n", id, price, m, d, y);
}