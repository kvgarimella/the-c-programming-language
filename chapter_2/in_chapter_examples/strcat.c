#include <stdio.h>

void str_cat(char s[], char t[]);

int main()
{
  char s[100] = "hello, \0";
  char t[] = "world. how are you doing?\0";
  str_cat(s, t);
  printf("%s\n", s);
}

void str_cat(char s[], char t[])
{
  int i, j;

  i = j = 0;
  while (s[i] != '\0')
  {
    i++;
  }
  while ((s[i++] = t[j++]) != '\0')
    ;
}
