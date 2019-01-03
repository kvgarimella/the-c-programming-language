#include <stdio.h>

/*
deletes any character in s1 that matches nay character
in s2.
*/

void squeeze_alt(char s1[], char s2[]);

int main()
{
  char s1[] = "hello\0";
  char s2[] = "hi there\0";
  squeeze_alt(s1, s2);
  printf("%s\n", s1);
  return 0;

}

void squeeze_alt(char s1[], char s2[])
{
  int i, j, k, c1, c2;

  i = j = 0;
  while ((c1 = s1[i]) != '\0')
  {
    for (k = 0; (c2 = s2[k]) != '\0'; k++)
    {
      if (c2 == c1)
      {
        break;
      }
    }
    if (c2 == '\0')
    {
      s1[j++] = s1[i];
    }
    ++i;
  }
  s1[j] = '\0';
}
