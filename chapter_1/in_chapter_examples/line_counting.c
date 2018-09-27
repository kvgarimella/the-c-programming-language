#include <stdio.h>

int main()
{
  double numlines;
  int c;

  while ((c = getchar()) != EOF) {

    // you have to use single quotes as they represent the integer value of the
    // newline character. For example we know A = 65...
    if (c == '\n') {
      ++ numlines;
    }

  }
  // printf("Integer value of newline is %d\n", '\n');
  printf("Number of lines in this program: %.0f\n", numlines);
}
