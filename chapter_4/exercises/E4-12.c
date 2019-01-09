#include <stdio.h>
#include <limits.h>
#include <string.h>

void itoa(int n, char s[], int i, int sign);
void reverse (char[]);


int main()
{
  char s[1000];
  int n = -23343243;
  int i = 0;
  int sign = 1;

  itoa(n, s, i, sign);
  printf("%s\n", s);
  return 0;
}

void itoa(int n, char s[], int i, int sign)
{
  if ((i == 0) && (sign = n) < 0)
  {
    n = -n;
  }

  if (n / 10)
  {
    s[i++] = n % 10 + '0';
    itoa(n / 10, s, i, sign);
  }
  else
  {
    s[i++] = n + '0';
    if (sign < 0)
    {
      s[i++] = '-';
    }
    s[i] = '\0';
    reverse(s);
  }
}

void reverse(char s[])
{
  int c, i, j;

  for (i = 0, j = strlen(s) - 1; i < j; i++,j--)
  {
    c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
}
