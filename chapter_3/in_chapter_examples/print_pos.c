#include <stdio.h>

int main()
{
  int n = 10;
  int i = 1;
  int k;
  int a[10];

  for (k = 0; k < 10; k++)
  {
    a[k] = i*k;
    i *= -1;
  }

  for (i = 0; i < n; i++)
  {
    if (a[i] < 0)
    {
      continue; // causes next iteration of loop automatically.
    }
    printf("%d\n", a[i]);
  }
}
