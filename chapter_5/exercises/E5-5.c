#include <stdio.h>
#include <string.h>

#define MAXSIZE

void _strncpy(char *s, char *t, int n);
void _strncat(char *s, char *t, int n);
int  _strncmp(char *s, char *t, int n);

int main()
{
  char s[MAXSIZE] = "abc";
  char t[MAXSIZE] = "abcd";

  int n = 4;
  // printf("before: %s\n", s);
  // _strncat(s, t, n);
  int cmp = _strncmp(s, t, n);
  int actual_cmp = strncmp(s, t, n);
  printf("%d\n", actual_cmp);
  printf("%d\n", cmp);
  if (cmp == actual_cmp)
  {
    printf("correct\n");
  }
  else
  {
    printf("incorrect\n");
  }
  return 0;
}

// copies at most n characters of t to s
void _strncpy(char *s, char *t, int n)
{
  int i = 0;

  while (i < n)
  {
    if (*t == '\0')
    {
      break;
    }
    *s++ = *t++;
    i++;
  }
  *s = '\0';
}

// concats at most n characters of t onto s
void  _strncat(char *s, char *t, int n)
{
  int i = 0;

  while (*s)
  {
    s++;
  }
  while (i < n)
  {
    if (*t == '\0')
    {
      break;
    }
    *s++ = *t++;
    i++;
  }
  *s = '\0';
}

int _strncmp(char *s, char *t, int n)
{
  int i = 0;
  for (; *s == *t && i < n; s++,t++, i++)
  {
    if (*s == '\0' && *t == '\0')
    {
      return 0;
    }
  }

  return *s - *t;
}
