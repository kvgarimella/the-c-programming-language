#include <stdio.h>

int main()
{
  // this is a nice case where we need to include the io library or else
  // EOF is not defined.
  printf("We are going to print the value of EOF.\n");

  printf("The value of EOF is: %d\n", EOF);

  printf("If you want to print the integer value of any character, remember to");
  printf(" use single quotes -> printf(\'c\') where c is some character\n");
}
