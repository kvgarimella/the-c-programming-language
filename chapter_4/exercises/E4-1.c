#include <stdio.h>
#include <string.h>

int strrindex(char source[], char searchfor[]);

char pattern[] = "ould";

int main()
{
  char line[] = "could and would\0";
  printf("%s\n", line);
  int index = strrindex(line, pattern);
  printf("%d <- index\n", index);
  return 0;
}

int strrindex(char s[], char t[])
{
  int i, j, k;

  for (i = strlen(s) - 1; i > 0; i--)
  {
    for (j = i, k = strlen(t) - 1; k > 0 && s[j] == t[k]; j--, k--) {}

    if (k == 0)
    {
      return i - (strlen(t) - 1);
    }
  }
  return -1;
}
