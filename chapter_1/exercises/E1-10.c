#include <stdio.h>

int main()
{
  int c;

  while ((c = getchar()) != EOF) {
    if (c == '\t') {
      printf("\\t");
    }
    // so this won't work because the terminal takes care of backspace...
    if (c == '\b') {
      printf("\\");
      printf("b");
    }
    if (c == '\\') {
      printf("\\\\");
    }
    putchar(c);
  }
}
