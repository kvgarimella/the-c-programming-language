#include <stdio.h>

#define swap(t,x,y) t (temp); (temp) = (x); (x) = (y); (y) = (temp);

int main()
{
  int x = 5;
  int y = 6;
  printf("x: %d\ny: %d\n", x, y);
  printf("swapping..\n");
  swap(int, x, y);
  printf("x: %d\ny: %d\n", x, y);
  return 0;
}
