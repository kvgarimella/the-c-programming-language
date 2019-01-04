#include <stdio.h>
#include <math.h>

/*
Write a program setbits(x,p,n,y) that returns x
with the n bits that begin at the position p set
to the rightmost n bits of y, leaving the other bits
unchanged
*/

unsigned setbits(unsigned, int, int, unsigned);

int main()
{
  unsigned x, y, z;
  int p, n;
  x = 1234;
  y = 3863;
  p = 6;
  n = 3;

  printf("x: %u\n", x);                   // 00000000000000000000010011010010
  printf("y: %u\n", y);                   // 00000000000000000000111100010111
  printf("p, n: %d, %d\n", p, n);
  z = setbits(x,p,n,y);
  printf("After Setting Bits: %u\n", z);  // 00000000000000000000010011110010


  return 0;
}
unsigned setbits(unsigned x, int p, int n, unsigned y)
{

  // step one. turn the bits at p -> p-n OFF in x;
  // step two. isolate the bits from y
  // pad (shift) the y bits by (p + 1 - n).
  // add the two together.
  // for now, let's make two unsigned vars and work with them.

  unsigned cx;
  unsigned cy;

  cx = x ^ (((x >> (p + 1 - n)) & ~(~0 << n)) << (p + 1 - n));
  cy = (~(~0 << n) & y) << (p + 1 - n);
  return cx + cy;
}
