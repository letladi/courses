#include <stdio.h>
#include <string.h>

int count_spaces(const char s[])
{
  int count = 0;
  while (*s) if (*s++ == ' ') count++;
  return count;
}

int main(void)
{
  printf("count_spaces('Letladi Sebesho') = %d\n", count_spaces(" Letladi Sebesho  "));
  return 0;
}
