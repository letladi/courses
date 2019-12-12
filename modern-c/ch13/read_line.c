#include <string.h>

int read_line(char *str, int n, char *prompt)
{
  printf("%s: ", prompt);
  int count = 0;
  char ch;
  char res[n];
  while ((ch = getchar()) != '\n' && count < n) {
    res[count] = ch;
    count++;
  }
  res[count] = '\0';
  strcpy(str, res);

  return count;
}
