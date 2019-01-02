#include <stdio.h>

int atoi(char s[]);

int main()
{
  int result;
  char s[] = "345\0";

  result = atoi(s);
  printf("atoi result: %d\n", result);
}

int atoi(char s[])
{
  int i, n;

  n = 0;
  i = 0;
  while (s[i] != '\0')
  {
    n = 10 * n + (s[i++] - '0');
  }
  return n;
}
