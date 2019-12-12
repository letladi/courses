#include <stdio.h>
#include <string.h>

void remove_filename(char *url)
{
  int len = strlen(url);
  while (len--) {
    if (url[len] == '/') {
      url[len] = '\0';
      break;
    }
  }
}

int main(void)
{
  char url[] = "http://www.knking.com/index.html";
  remove_filename(url);
  printf("url = %s\n", url);
}
