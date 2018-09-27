#include <stdio.h>

#define INWORD 1
#define LONGESTWORD 15

int main()
{
  int curr_length, total, i, j, c, curr_state, max;
  curr_length = total = curr_state = max = 0;

  // initialize array: Longest word can be length 15.
  int length_words[LONGESTWORD];
  for(i = 0; i < LONGESTWORD; ++i) {
    length_words[i] = 0;
  }

  while ((c = getchar()) != EOF) {
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
      if (curr_state != INWORD) {
        curr_state = INWORD;
        curr_length = 1;
      }
      else {curr_length += 1;}
    }
    if (c == '\n' || c == '\t' || c == ' ') {
      if (curr_state == INWORD) {
        ++length_words[curr_length];
        ++ total;
        curr_state = 0;
      }
      curr_length = 0;
    }
  }
  printf("\nEOF found; now producing historgrams..\n\n");

  printf("Horizontal Histogram:\n");
  for(i = 0; i < LONGESTWORD; ++i) {
    printf("%2d:", i);
    for(j = 0; j < length_words[i]; ++j) {
      putchar('#');
    }
    putchar('\n');
  }

  printf("\nVertical Histogram:\n");
  for(i = 0; i < LONGESTWORD; ++i) {
    if (length_words[i] > max) {
      max = length_words[i];
    }
  }
  for(i = max - 1; i >= 0; --i) {
    for(j = 0; j < LONGESTWORD; ++j) {
      if (length_words[j] > i) {
        printf(" #  ");
      } else {
        printf("    ");
      }
    }
    putchar('\n');
  }
  for(i = 0; i < LONGESTWORD; ++i) {
    printf("%2d  ", i);
  }
  putchar('\n');

}
