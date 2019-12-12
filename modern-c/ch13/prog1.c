#include <stdio.h>
#include <string.h>
#include "./read_line.c"

int main(void)
{
  char word[20], smallest_word[20], largest_word[20];
  int iteration = 0, word_len;
  while ((word_len = read_line(word, 20, "Enter word"))) {
    if (iteration++) {
      if (strcmp(word, smallest_word) < 0) strcpy(smallest_word, word);
      else if (strcmp(word, largest_word) > 0) strcpy(largest_word, word);
    } else {
      strcpy(smallest_word, word);
      strcpy(largest_word, word);
    }

    if (word_len == 4) break;
  }

  printf("Smallest word = %s\n", smallest_word);
  printf("Largest word = %s\n", largest_word);

  return 0;
}
