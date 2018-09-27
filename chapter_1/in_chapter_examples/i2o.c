#include <stdio.h>

int main()
{
  int c;

  // version 1: EOF is equal to the integer value of -1
  // c = getchar();
  // while (c != EOF) {
  //   putchar(c);
  //   c = getchar();
  // }


  printf("On linux,unix, use control + d to get EOF\n\n");
  // version two. We find the value of getchar on the fly
  while ((c = getchar()) != EOF) {
    putchar(c);
  }

  printf("\nDone with that while loop....\n");

  

}
