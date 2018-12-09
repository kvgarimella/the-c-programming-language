#include <stdio.h>
#define MAXLINE 1000

void reverse(char s[]);
int getLine(char s[], int lim);

int main()
{
  char line[MAXLINE];
  int len;
  while((len = getLine(line, MAXLINE)) > 0) {
    reverse(line);
    printf("Reversed: %s\n", line);
  }
}

int getLine(char s[], int lim)
{
  int c, i;
  for (i = 0; i < lim - 1 && (c=getchar()) != EOF && c != '\n'; ++i)
  {
    s[i] = c; // filling an array of characters with current line.
  }
  if (c == '\n')
  {
    s[i] = c;
    ++i;
  }
  s[i] = '\0'; // NUL byte. You can find length of string by searching for
               // first occurence of '\0'
  return i; // returns length of line.

}

void reverse(char s[])
{
  char temp;
  int i = 0;
  int j = 0;

  // Find length of the string.
  while(s[j] != '\0') {
    ++j;
  }
  --j;
  // in place reverse.
  while (i < j) {
    temp = s[i];
    s[i] = s[j];
    s[j] = temp;
    ++i;
    --j;
  }
}
