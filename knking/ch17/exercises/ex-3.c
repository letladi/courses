#include <stdio.h>
#include <stdlib.h>

int *create_array(int n, int initial_value)
{
   int *ret = malloc(n*sizeof(int));
   if (ret) {
      for (int i = 0; i < n; i++) {
         ret[i] = initial_value;
      }
   } 
   return ret;
}