#include <stdlib.h>
#include <stdio.h>

void* my_malloc(long long int n)
{
   void* ret = malloc(n);
   if (ret == NULL) {
      printf("could not allocate space. Exiting...\n");
      exit(EXIT_SUCCESS);
   } else {
      return ret;
   }
}

int main(void)
{
   int* p = my_malloc(500);
   *p = 55;
   printf("size of p: %lu; *p = %d\n", sizeof(*p), *p);

   return 0;
}