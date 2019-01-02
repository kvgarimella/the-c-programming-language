#include <stdio.h>
#include <ctype.h>
#define LIMIT 1000

int lower(int c);
int built_in_lower(int c);
void get_line(char from[]);
void lower_string(char from[], char to[]);

int main()
{
  int c;
  int lowered;
  char from[LIMIT], to[LIMIT];

  printf("Input a string of characters to lower. Then hit enter.\n");
  get_line(from);
  lower_string(from, to);

  printf("Lower case: %s\n", to);
  return 0;
}

void get_line(char from[])
{
  int c, i;

  i = 0;
  while ((c = getchar()) != EOF && c != '\n')
  {
    from[i++] = c;
  }
  from[i] = '\0';
}

void lower_string(char from[], char to[])
{
  int i = 0;
  while (from[i] != '\0')
  {
    to[i] = lower(from[i]);
    i++;
  }
  to[i] = '\0';
}

int lower(int c)
{
  if (c >= 'A' && c <= 'Z')
  {
    return c + ('a' - 'A'); // 'a' - 'A' -> fixed distance between upper and lower
  }
  printf("lowered: %c", c);
  return c;
}

int built_in_lower(int c)
{
  if (isdigit(c))
  {
    return tolower(c);
  }
  return c;
}
