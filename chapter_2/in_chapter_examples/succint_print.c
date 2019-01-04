#include <stdio.h>

int main()
{
  int n = 40;
  int a[n];
  int i;
  for (i = 0; i < n; ++i)
  {
    a[i] = i;
  }

  for (i = 0; i < n; ++i)
  {
    printf("%d%c", a[i], (i % 10 == 9 || i == n - 1) ? '\n' : ' ');
  }

  // n = 1;
  printf("You have %d item%c.\n", n, (n == 1) ? '\0' : 's');
}
