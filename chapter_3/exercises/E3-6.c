#include <stdio.h>
#include <limits.h>
#include "../in_chapter_examples/reverse.c"


void itoa(int n, char s[], int min_width);

int main()
{
  char s[1000];
  int n = 12;
  int min_width = 10;
  itoa(n, s, min_width);
  printf("%s\n", s);
  return 0;
}

void itoa(int n, char s[], int min_width)
{
  int i, sign, largest;

  if ((sign = n) < 0)
  {
    if (n == INT_MIN)
    {
      n = INT_MAX;
      largest = 1;
    }
    else
    {
      n = -n;
    }
  }
  i = 0;
  do
  {
    if (largest && i == 0)
    {
      s[i++] = n % 10 + '1';
    }
    else
    {
      s[i++] = n % 10 + '0';
    }
  } while ((n /= 10) > 0);
  if (sign < 0)
  {
    s[i++] = '-';
  }
  while (i <= min_width)
  {
    s[i++] = ' ';
  }
  s[i] = '\0';
  reverse(s);
}
