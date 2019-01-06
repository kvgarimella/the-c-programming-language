#include <stdio.h>
#define LOWER_LIM 1000
void escape(char[], char[]);
void unescape(char[], char []);

int main()
{
  char t[LOWER_LIM] = "Hey \t there.\n\0";
  char s[LOWER_LIM * 2];
  escape(s, t);
  printf("%s\n", t);
  printf("%s\n", s);
  char tt[LOWER_LIM] = "Hey \\t there.\\n\0";
  unescape(s,tt);
  printf("%s\n", tt);
  printf("%s\n", s);
  return 0;
}

void escape(char s[], char t[])
{
  int i, j, c;
  i = j =  0;

  while ((c = t[i]) != '\0')
  {
    switch (c)
    {
      case '\a':
        s[j++] = '\\';
        s[j++] = 'a';
        break;
      case '\b':
        s[j++] = '\\';
        s[j++] = 'b';
        break;
      case '\f':
        s[j++] = '\\';
        s[j++] = 'f';
        break;
      case '\n':
        s[j++] = '\\';
        s[j++] = 'n';
        break;
      case '\r':
        s[j++] = '\\';
        s[j++] = 'r';
        break;
      case '\t':
        s[j++] = '\\';
        s[j++] = 't';
        break;
      case '\v':
        s[j++] = '\\';
        s[j++] = 'v';
        break;
      case '\\':
        s[j++] = '\\';
        s[j++] = '\\';
        break;
      case '\?':
        s[j++] = '\\';
        s[j++] = '?';
        break;
      case '\'':
        s[j++] = '\\';
        s[j++] = '\'';
        break;
      case '\"':
        s[j++] = '\\';
        s[j++] = '\"';
        break;
      default:
        s[j++] = c;
        break;
    }
    ++i;
  }
  s[j] = '\0';
}

void unescape(char s[], char t[])
{
  int i, j, c;
  i = j = 0;

  while ((c = t[i]) != '\0')
  {
    switch(c)
    {
      case '\\':
          switch(t[++i])
          {
            case 'a':
              s[j++] = '\a';
              break;
            case 'b':
              s[j++] = '\b';
              break;
            case 'f':
              s[j++] = '\f';
              break;
            case 'n':
              s[j++] = '\n';
              break;
            case 'r':
              s[j++] = '\r';
              break;
            case 't':
              s[j++] = '\t';
              break;
            case 'v':
              s[j++] = '\v';
              break;
            case '\\':
              s[j++] = '\\';
              break;
            case '?':
              s[j++] = '\?';
              break;
            case '\'':
              s[j++] = '\'';
              break;
            case '\"':
              s[j++] = '\"';
              break;
        }
        ++i;
        break;
      default:
        s[j++] = c;
        ++i;
        break;
    }
  }
  s[j] = '\0';
}
