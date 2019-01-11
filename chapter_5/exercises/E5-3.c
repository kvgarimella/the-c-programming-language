#include <stdio.h>

void str_cat(char s[], char t[]);
void str_cat_ptr(char *s, char *t);


int main()
{
  char s[100] = "hello, \0";
  char t[] = "world. how are you doing?\0";
  // str_cat(s, t);
  str_cat_ptr(s,t);
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

void str_cat_ptr(char *s, char *t)
{
  while (*s != '\0')
  {
    ++s;
  }
  while ((*s++ = *t++) != '\0') {}
}
