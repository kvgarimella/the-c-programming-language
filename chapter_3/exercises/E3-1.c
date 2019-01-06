#include <stdio.h>

int binsearch(int, int[], int);

int main()
{
  int x = 6;
  int i = 10;
  int v[i];
  for (i = 0; i < 10; i++)
  {
    v[i] = i*2;
  }
  int idx = binsearch(x, v, i);
  printf("%d\n", idx);
  return 0;
}

int binsearch(int x, int v[], int n)
{
  int low, mid, high;

  low = 0;
  high = n - 1;

  while (low < high)
  {
    mid = (low + high) / 2;
    if (x <= v[mid])
    {
      high = mid;
    }
    else
    {
      low = mid + 1;
    }
  }

  return x == v[low] ? low : -1;
}
