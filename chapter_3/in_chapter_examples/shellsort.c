#include <stdio.h>

void shellsort(int[], int);

int main()
{
  int i, j;
  i = 10;
  int v[i];
  j = 1;
  for (i = 0; i < 10; i++)
  {
    v[i] = j * i;
    j *= -1;
  }
  shellsort(v, i);
  for (i = 0; i < 10; i++) {
    printf("%d ", v[i]);
  }
  putchar('\n');
}

void shellsort(int v[], int n)
{
  int gap, i, j, temp;

  for (gap = n / 2; gap > 0; gap /= 2)
  {
    for (i = gap; i < n; i++)
    {
      for (j = i - gap; j >= 0 && v[j]>v[j+gap]; j-=gap)
      {
        temp = v[j];
        v[j] = v[j + gap];
        v[j + gap] = temp;
      }
    }
  }
}
