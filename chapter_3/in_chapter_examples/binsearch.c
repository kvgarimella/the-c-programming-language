#include <stdio.h>
#include <time.h>

// binary search: fina x in v[0] <= v[1] <= ... <= v[n - 1]

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
  int low, high, mid;

  low = 0;
  high = n - 1;
  while (low <= high)
  {
    mid = (low + high) / 2;
    if (x < v[mid])
    {
      high = mid - 1;
    }
    else if (x > v[mid])
    {
      low = mid + 1;
    }
    else
    {
      return mid;
    }
  }
  return -1;
}
