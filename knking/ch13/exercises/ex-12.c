#include <stdio.h>
#include <string.h>

void get_extension(const char* file_name, char *extension)
{
   size_t name_len = strlen(file_name);
   int n = name_len - 1;
   int ext_start_i;
   while (n) {
      if (file_name[n] == '.') {
         ext_start_i = n + 1;
          break;
      }
      n--;
   }
   if (n < 2) { // either there is no . (n == 0) or . is in index=0 (n == 1)
      strcpy(extension, "");
   } else {
      strcpy(extension, &file_name[n]);
   }
}

int main(void)
{
   char ext1[10];
   get_extension("memo.txt", ext1);
   printf("ext1 = %s\n", ext1);

   return 0;
}