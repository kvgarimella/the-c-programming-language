#include <stdio.h>

int inital_lower(int);
int final_lower(int);

int main()
{
  int c = 'Q';
  int init_lower_c = inital_lower(c);
  int final_lower_c = final_lower(c);
  printf("%c -> %c -> %c\n", c, init_lower_c, final_lower_c); 
  return 0;
}

int inital_lower(int c)
{
  if (c >= 'A' && c <= 'Z')
  {
    return c + ('a' - 'A'); // 'a' - 'A' -> fixed distance between upper and lower
  }
  printf("lowered: %c", c);
  return c;
}

int final_lower(int c)
{
  return (c >= 'A' && c <= 'Z') ? c + ('a' - 'A') : c;
}
