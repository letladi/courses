#include <stdio.h>
#include <string.h>

void build_index_url(const char *domain, char *index_url)
{
  strcat(index_url, "http://www.");
  strcat(index_url, domain);
  strcat(index_url, "/index.html");
}

int main(void)
{
  char *king = "knking.com", index[40];
  build_index_url(king, index);

  printf("build_index_url('knking') = %s\n", index);

  return 0;
}
