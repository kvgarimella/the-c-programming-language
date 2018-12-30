#include <stdio.h>

#define TABSTOP 3
#define LIMIT 1000

/*
Write a program detab that replaces tabs in the input with the proper number of
blanks to space to the next tab stop. Assume a fixed set of tab stops every n columns
*/

int get_line(char s[], int lim);
void detab(char s[], char detabbed[], int tabstop);

int main()
{
  char line[LIMIT];
  char detabbed[LIMIT];
  int len;
  while((len = get_line(line, LIMIT)) > 0)
  {
    detab(line, detabbed, TABSTOP);
    printf("%s\n", detabbed);
  }
}

int get_line(char s[], int lim)
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

void detab(char s[], char detabbed[], int tabstop)
{
  int c, i, j, curr_tab_stop;

  i             = 0;
  j             = 0;
  curr_tab_stop = 0;

  while ((c = s[i++]) != '\0')
  {
    if (c == '\t')
    {
      while (curr_tab_stop <= tabstop)
      {
        ++curr_tab_stop;
        detabbed[j++] = ' ';
      }
    }
    else
    {
      ++curr_tab_stop;
      detabbed[j++] = c;
    }
    curr_tab_stop = curr_tab_stop % tabstop; // make sure tab stop wraps
  }
  detabbed[j] = '\0';
}
