#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

bool test_extension(const char *file_name, const char *extension)
{
  int ext_len = strlen(extension);
  int file_name_len = strlen(file_name);

  if (ext_len >= file_name_len) return false;

  while (ext_len) {
    char a = toupper(file_name[--file_name_len]);
    char b = toupper(extension[--ext_len]);
    if (a != b) return false;
  }
  return file_name[--file_name_len] == '.';
}

int main(void)
{
  return 0;
}
