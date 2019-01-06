#include <stdio.h>
#include <time.h>

int binsearch(int, int[], int);

int main()
{
  int x = 100;
  int i = 10000;
  int v[i];
  for (i = 0; i < 10000; i++)
  {
    v[i] = i*2;
  }
  clock_t start = clock();
  int idx = binsearch(x, v, i);
  clock_t end = clock();
  float seconds = (float) (end - start) / CLOCKS_PER_SEC;
  printf("%d <- index. Elapsed time: %f\n", idx, seconds);

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
