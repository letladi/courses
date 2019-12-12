#include <stdio.h>
#include <string.h>

void get_extension(const char* file_name, char *extension)
{
  char dot = '.';
  int iteration = 0;
  while (*file_name) {
    if (dot == *file_name && iteration) {
      strcpy(extension, ++file_name);
      break;
    }
    file_name++;
    iteration++;
  }

  if (!*file_name) {
    strcpy(extension, "");
  }
}

int main(void)
{
  char *extension;
  get_extension("file.cpp", extension);
  printf("get_extension('.gitignore') = %s\n", extension);

  return 0;
}
