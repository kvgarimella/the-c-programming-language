#include <stdio.h>

int main()
{
  int curr_length, total, array_size, i, c;
  curr_length = total = 0;
  array_size = 15;


  int length_words[array_size];

  for(i = 0; i < array_size; ++i) {
    length_words[i] = 0;
  }

  while ((c = getchar()) != EOF) {
    if (c == '\n' || c == '\t' || c == ' ') {
      ++length_words[curr_length];
      if (curr_length > 0) {
        ++ total;
      }
      curr_length = 0;

    } else {
      curr_length += 1;
    }
  }
  printf("\nLength of words.\n");
  for(i = 0; i < array_size; ++i) {
    printf("%d: %d\n", i, length_words[i]);
  }

}
