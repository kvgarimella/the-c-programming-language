#include <stdio.h>

int main()
{
  // first enum has value 0, next is 1, and so on.
  enum booleans { NO, YES };
  printf("%d\n", NO);

  // you can also specify the values:
  enum escapes { BELL = '\a', BACKSPACE = '\b', TAB = '\t' };
  enum months { JAN = 1, FEB, MARCH, APRIL };
  printf("April: %d\n", APRIL);

  int lower, step, upper;
  char c, line[1000];

  // you can also do

  int i = 2;
  float eps =1.0e-5;

  // cstring

  char messages[] = "hello, world";
  printf("%s\n", messages);


  return 0;
}
