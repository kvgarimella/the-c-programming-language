#include <stdio.h>
#include <math.h>

unsigned getbits(unsigned, int, int);

int main()
{
  unsigned x;
  int p, n;

  x = 1234;                                           // 00000000000000000000010011010010
  p = 6;
  n = 3;
  unsigned y;
  printf("Original: %d\n", x);
  printf("x >> (p + 1 - n): %d\n", x >> (p + 1 - n)); // 00000000000000000000000001001101
  printf("~(~0 << n): %d\n", ~(~0 << n));             // 00000000000000000000000000000111
  y = getbits(x, p, n);
  printf("(x >> (p + 1 - n)) & ~(~0 << n): %d\n", y); // 00000000000000000000000000000101

  return 0;
}

unsigned getbits(unsigned x, int p, int n)
{
  return (x >> (p + 1 - n)) & ~(~0 << n);
}
