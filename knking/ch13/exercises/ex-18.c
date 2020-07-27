#include <stdio.h>
#include <string.h>

void remove_filename(char *url)
{
   size_t len = strlen(url);
   char *p = (url + len - 1);
   while (p > url) {
      if (*p == '/') {
         if (*(p - 1) == '/' && *(p - 2) == ':') break; 

         *p = '\0';
      }
      p--;
   }
}

int main(void)
 {
    char url[] = "http://www.knking.com/index.html";
    printf("before: %s\n", url);
    remove_filename(url);
    printf("after: %s\n", url);

    return 0;
 }