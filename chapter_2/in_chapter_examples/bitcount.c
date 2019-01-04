#include <stdio.h>


// count number of one bits.

int bitcount(unsigned);

int main()
{
  unsigned x = 1444;
  int num_one_bits = bitcount(x);
  printf("%d\n", num_one_bits);
  return 0;
}

int bitcount(unsigned x)
{
  int b;

  for (b = 0; x!= 0; x >>= 1)
  {
    if (x & 01)
    {
      b++;
    }
  }
  return b;
}
