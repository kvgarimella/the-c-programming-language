#include <stdio.h>
#include <limits.h>
#include "reverse.c"

void itoa(int n, char s[]);

int main()
{
  char s[1000];
  int n = -24;
  itoa(n, s);
  printf("%s\n", s);
  return 0;
}

void itoa(int n, char s[])
{
  int i, sign;

  if ((sign = n) < 0)
  {
    n = -n;
  }
  i = 0;
  do
  {
    s[i++] = n % 10 + '0';
  } while((n /= 10) > 0);
  if (sign < 0)
  {
    s[i++] = '-';
  }
  s[i] = '\0';
  reverse(s);
}
