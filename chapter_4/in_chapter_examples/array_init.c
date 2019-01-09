#include <stdio.h>
#include <string.h>


int main()
{
  char s0[] = "hey";
  char s1[] = { 'h', 'e', 'y', '\0'};
  printf("%d\n", strlen(s0) == strlen(s1));
}
