#include <stdio.h>
#include <ctype.h>

void expand(char[], char[]);

int main()
{
  char s1[100] = "a-z0-9\0";
  char s2[1000];
  expand(s1, s2);
  printf("%s\n", s2);
  return 0;
}

void expand(char s1[], char s2[])
{
  int i, j, c, next_digit, next_char;
  i = j = next_digit = next_char = 0;

  for (i = 0; s1[i] != '\0'; ++i)
  {
    c = s1[i];
    if (isdigit(c) && s1[i + 1] == '-' && isdigit(s1[i + 2]))
    {
      s2[j++] = c;
      i+=2;
      next_digit = c + 1;
      while (next_digit != s1[i])
      {
        s2[j++] = next_digit;
        next_digit++;
      }
      s2[j++] = next_digit;
    }
    else if (isalpha(c) && s1[i + 1] == '-' && isalpha(s1[i + 2]))
    {
      s2[j++] = c;
      i+=2;
      next_char = c + 1;
      while (next_char != s1[i])
      {
        s2[j++] = next_char;
        next_char++;
      }
      s2[j++] = next_char;
    }
    else
    {
      s2[j++] = c;
    }
  }
  s2[j] = '\0';
}
