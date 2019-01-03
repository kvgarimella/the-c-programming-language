#include <stdio.h>
#include <string.h>

/*
write a function that returns the first location (index)
in the string s1 where any character from s2 occurs, or a -1
if s1 contains no characters from s2.
*/


int any(char[], char[]);


int main()
{
  char s[] = "hello\0";
  char t[] = "a\0";
  char *ptr;
  int  loc;

  ptr = strpbrk(s, t);
  loc = any(s, t);
  printf("%s\n", ptr);
  printf("%d\n", loc);

  return 0;
}

int any(char s1[], char s2[])
{
  int i, j, k, c1, c2;

  i = 0;
  while ((c2 = s2[i++]) != '\0')
  {
    k = 0;
    for (j = 0; (c1 = s1[j]) != '\0'; j++)
    {
      if (c1 == c2)
      {
        return k;
      }
      k++;
    }
  }
  return -1;
}
