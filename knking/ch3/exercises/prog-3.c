#include <stdio.h>

int main(void)
{
   int gs1N, groupN, pubN, itemN, checkN;
   printf("Enter ISBN: ");
   scanf("%d - %d - %d - %d - %d", &gs1N, &groupN, &pubN, &itemN, &checkN);
   printf("GS1 prefix: %d\n", gs1N);
   printf("Group identifier: %d\n", groupN);
   printf("Publisher code: %d\n", pubN);
   printf("Item number: %d\n", itemN);
   printf("Check digit: %d\n", checkN);

   return 0;
}