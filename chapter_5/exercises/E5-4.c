#include <stdio.h>
#include <string.h>

int strend(char *s, char *t);

int main()
{
  char s[] = "endsfriend";
  char t[] = "ends";
  int x = strend(s, t);
  if (x)
  {
    printf("match\n");
  }
  else
  {
    printf("not match\n");
  }
  return 0;
}

int strend(char *s, char *t)
{
  int len_s = strlen(s) - 1;
  int len_t = strlen(t) - 1;

  if (len_t > len_s)
  {
    return 0;
  }

  int start_idx = 0;
  while (start_idx != (len_s - len_t))
  {
    start_idx++;
    s++;
  }

  while (*s++ == *t++)
  {
    if (*s == '\0')
    {
      return 1;
    }
  }
  return 0;



}
