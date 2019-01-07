#include <stdio.h>

int main()
{
  int a[5] = {3,4,5,6,7};
  int b[5] = {8,10,11,5,12};

  int m, n;
  m = n = 5;

  int i, j;

  int num_checks = 0;

  for (i = 0; i < n; i++)
  {
    for (j = 0; j < m; j++)
    {
      num_checks++;
      if (a[i] == b[j])
      {
        goto found;
      }
    }
  }

  found:
    {
      printf("Found one. ");
      printf("Number of checks: %d\n", num_checks);
    }

  return 0;
}
