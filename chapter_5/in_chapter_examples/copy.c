#include <stdio.h>

void strcpy_array(char *s, char *t);
void strcpy_pointer(char *s, char *t);
void strcpy_pointer2(char *s, char *t);
void strcpy_pointer3(char *s, char *t);

int main()
{
  return 0;
}

void strcpy_array(char *s, char *t)
{
  int i = 0;
  while ((s[i] = t[i]) != '\0')
  {
    i++;
  }
}

void strcpy_pointer(char *s, char *t)
{
  while ((*s = *t) != '\0')
  {
    ++s;
    ++t;
  }
}

void strcpy_pointer2(char *s, char *t)
{
  while ((*s++ = *t++) != '\0') {}
}

void strcpy_pointer3(char *s, char *t)
{
  while ((*s++ = *t++)) {}
}
