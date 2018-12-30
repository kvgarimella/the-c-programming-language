#include <stdio.h>
#include <limits.h>
#include <float.h>

/*

determine the ranges of char, short, int, and long variables

*/

void signed_range();
void unsigned_range();
void signed_min();

int main()
{
  unsigned_range();
  putchar('\n');
  putchar('\n');
  signed_range();
  putchar('\n');
  putchar('\n');
  signed_min();

}

void signed_range()
{
  signed char  h, h_next;
  signed short i, i_next;
  signed int   j, j_next;
  signed long  k, k_next;


  int iter;

  h = 1;
  i = 1;
  j = 1;
  k = 1;

  printf("Computing Max of Signed Data Types...\n");
  for(iter = 0; iter < 64; iter++)
  {
    if (2 * h - 1 > h_next)
    {
      h_next = 2 * h - 1;
    }
    if (2 * i - 1 > i_next)
    {
      i_next = 2 * i - 1;
    }
    if (2 * j - 1 > j_next)
    {
      j_next = 2 * j - 1;
    }
    if (2 * k - 1 > k_next)
    {
      k_next = 2 * k - 1;
    }
    h*=2;
    i*=2;
    j*=2;
    k*=2;
  }
  printf("Comparing computed max vs. given max...\n");
  printf("char : %d vs. %d\n", h_next, CHAR_MAX);
  printf("short: %d vs. %d\n", i_next, SHRT_MAX);
  printf("int  : %u vs. %u\n", j_next, INT_MAX);
  printf("long : %lu vs. %lu\n", k_next, LONG_MAX);
}

void unsigned_range()
{
  unsigned char  h, h_next;
  unsigned short i, i_next;
  unsigned int   j, j_next;
  unsigned long  k, k_next;


  int iter;

  h = 1u;
  i = 1u;
  j = 1u;
  k = 1u;

  printf("Computing Max of Unsigned Data Types...\n");
  for(iter = 0; iter < 64; iter++)
  {
    if (2 * h - 1 > h_next)
    {
      h_next = 2 * h - 1;
    }
    if (2 * i - 1 > i_next)
    {
      i_next = 2 * i - 1;
    }
    if (2 * j - 1 > j_next)
    {
      j_next = 2 * j - 1;
    }
    if (2 * k - 1 > k_next)
    {
      k_next = 2 * k - 1;
    }
    h*=2;
    i*=2;
    j*=2;
    k*=2;
  }
  printf("Comparing computed max vs. given max...\n");
  printf("char : %d vs. %d\n", h_next, UCHAR_MAX);
  printf("short: %d vs. %d\n", i_next, USHRT_MAX);
  printf("int  : %u vs. %u\n", j_next, UINT_MAX);
  printf("long : %lu vs. %lu\n", k_next, ULONG_MAX);
}

void signed_min()
{
  signed char  h, h_next, h_min;
  short i, i_next, i_min;
  int   j, j_next, j_min;
  long  k, k_next, k_min;


  int iter;

  h = -1;
  i = -1;
  j = -1;
  k = -1;

  printf("Computing Min of Signed Data Types...\n");
  for(iter = 0; iter < 64; iter++)
  {
    
    h_next = 2 * h;
    if (h_next < h)
    {
      h_min = h_next;
    }

    i_next = 2 * i;
    if (i_next < i)
    {
      i_min = i_next;
    }

    j_next = 2 * j;
    if (j_next < j)
    {
      j_min = j_next;
    }

    k_next = 2 * k;
    if (k_next < k)
    {
      k_min = k_next;
    }

    h*=2;
    i*=2;
    j*=2;
    k*=2;

  }
  printf("Comparing computed min vs. given min...\n");
  printf("char : %d vs. %d\n", h_min, CHAR_MIN);
  printf("char : %d vs. %d\n", i_min, SHRT_MIN);
  printf("char : %i vs. %i\n", j_min, INT_MIN);
  printf("char : %ld vs. %ld\n", k_min, LONG_MIN);
}
