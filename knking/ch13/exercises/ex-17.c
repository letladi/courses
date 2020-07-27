#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

bool test_extension(const char *file_name, const char *extension)
{
   int len1 = strlen(file_name);
   int len2 = strlen(extension);
   int count = 0;

   const char *f = file_name + len1 - 1;
   const char *ext = extension + len2 - 1;
   
   while ((extension <= ext) && (file_name <= f)) {

      if (ext == extension) {
         return *(f - 1) == '.';
      } else if (toupper(*f) != toupper(*ext)) {
         return false;
      } else {
         --ext;
         --f;
      }
   }
   return false;
}

int main(void) 
{
   printf("test_extension('memo.txt', 'TXT') = %d\n", test_extension("memo.txt", "TXT"));
   return 0;
}