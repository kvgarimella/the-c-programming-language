#include <stdio.h>

int strlen_p(char *);

int main()
{

  char *s = "hello, there\0";
  // char s[] = "hello, there\0"; equivalent to above
  printf("%d\n", strlen_p(s));
  printf("%d\n", strlen_p(&s[0]));
  printf("%d\n", strlen_p("hello, world!"));
  return 0;
}

int strlen_p(char *s)
{
  int n;
  for (n = 0; *s != '\0'; s++)
  {
    n++;
  }
  return n;
}
