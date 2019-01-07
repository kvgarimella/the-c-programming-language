#include <stdio.h>
#include <string.h>

int trim(char[]);

int main()
{
  char s[] = "hey. let\'s delete trailing blanks.\t  \0";
  printf("Length before: %lu\n", strlen(s));
  int n = trim(s);
  printf("%s\n", s);
  printf("Length after: %d\n", n);
}

int trim(char s[])
{
  int n;

  for (n = strlen(s) - 1; n >=0; n--)
  {
    if (s[n] != ' ' && s[n] != '\t' && s[n] != '\n')
    {
      break;
    }
  }
  s[n+1] = '\0';
  return n;

}
