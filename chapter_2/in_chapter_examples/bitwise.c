#include <stdio.h>
#include <math.h>
#define OCTBASE 8


void octtobin(char s[]);

int main()
{



  int x = 6; //0110
  int y = 6; //0110




  int z;
  z = x ^ y;
  printf("%d\n", z); // 0000

  z = x | y;
  printf("%d\n", z); //0110

  z = ~x;
  printf("%d\n", z);

  char s[] = "0177\0";
  octtobin(s);


  int n = 349;
  n = n & 0177;
  printf("int n = 349; n = n & 0177; n is now %d\n", n); // should be 93

  x = 0;
  int SET_ON = 0177;
  x = x | SET_ON;
  printf("%d\n", x); // should be 127

  x = 1; // 01
  y = 2; // 10
  printf("x = 1; y = 2\n");
  printf("x && y -> %d\n",x && y);
  printf("x & y  -> %d\n",x & y );

  x = 5;
  printf("x: %d\n", x);
  x = x << 2;
  printf("x << 2 (shift bits left twice, pad w/ zeros): %d\n", x);


  printf("x: %d\n", x);
  x = x >> 1;
  printf("x >> 1 (shift right once.): %d\n", x);

  x = 5;
  printf("x: %d\n", x);
  x = x >> 1;
  printf("x >> 1: %d\n", x);

  signed int q;
  q = -5;
  printf("q: %d\n", q);
  q = q >> 1;
  printf("q >> 1: %d\n", q);


  x = 31;
  x = x & ~077;
  printf("%d\n", x);
  return 0;
}


// did not need to write this. could have just called printf("%d\n");
void octtobin(char s[])
{
  int i, k, integer_value;

  i = 0;
  while (s[i++] != '\0') {}
  i -=2;

  // printf("%d\n", i);

  k = 0;
  integer_value = 0;
  while (i > 0)
  {
    integer_value = integer_value + pow(OCTBASE, k++) * (s[i] - '0');
    i--;
  }
  printf("oct: %s -> dec: %d\n", s, integer_value);
}
