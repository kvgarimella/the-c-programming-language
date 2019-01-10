#include <stdio.h>

void swap(int, int);
void true_swap(int *, int *);

int main()
{
  int x = 10, y = 5;
  swap(x,y);
  printf("%d %d\n", x, y);
  true_swap(&x, &y);
  printf("%d %d\n", x, y);
}

// wont work because only copies of x and y are passed into
// this implementation of swap
void swap(int x, int y)
{
  int temp;

  temp = x;
  x    = y;
  y    = temp;
}

// here we pass in pointers to the memory locs of x and y.
// then we dereference them using *x and *y. swap their values.
// and it swaps the true values of x and y.
void true_swap(int *x, int *y)
{
  int temp;

  temp = *x;
  *x = *y;
  *y = temp;
}
