#include <stdio.h>

/*
prints input one word per line. This completes 1.5
*/

int main()
{
  int c, in_word;

  in_word = 0;


  while((c = getchar()) != EOF) {
    if (c == '\n' || c == ' ' || c == '\t') {
      if (in_word == 0) {}
      else {
        putchar('\n');
        in_word = 0;
      }
    }
    else {
      in_word = 1;
      putchar(c);
    }
  }
}
