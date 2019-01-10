#include <stdio.h>

int strlen_2(char *s);

int main()
{
  char *s = "hello, there\0";
  printf("%d\n", strlen_2(s));
}

int strlen_2(char *s)
{
  char *p = s;

  while (*p != '\0')
  {
    p++;
  }
  return p - s;
}
