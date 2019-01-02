#include <stdio.h>

int main()
{
  int x;

  int n = 5;

  x = n++;
  printf("x = n++; -> x = %d, n = %d\n", x, n);

  n = 5;

  x = ++n;
  printf("x = ++n; -> x = %d, n = %d\n", x, n);

  return 0;
}
