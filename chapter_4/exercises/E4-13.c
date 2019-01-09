#include <stdio.h>
#include <limits.h>
#include <string.h>

void reverse (char[]);
void reverse_recurse(char s[], int i, int j);


int main()
{
  char s[] = "hey there.\0";
  reverse(s);
  reverse_recurse(s, 0, strlen(s) - 1);
  printf("%s\n", s);
  return 0;
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

void reverse_recurse(char s[], int i, int j)
{
  int temp;
  if (i < j)
  {
    temp = s[i];
    s[i] = s[j];
    s[j] = temp;
    reverse_recurse(s, ++i, --j);
  }
}
