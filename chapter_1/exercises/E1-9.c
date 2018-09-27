#include <stdio.h>


#define SPACE 32
int main()
{
  int c;


  // version 1: works fine but a lot of repeated ' '
  // while((c = getchar()) != EOF) {
  //
  //   if (c == ' ') {
  //     while ((c = getchar()) == ' ')
  //       ;
  //     putchar(' ');
  //   }
  //   putchar(c);
  // }


  // version 2: I used a symbolic constant. 32 is the integer value of space
  while ((c = getchar()) != EOF) {
    if (c == SPACE) {
      while ((c = getchar()) == SPACE)
        ;
      putchar(SPACE);
    }
    putchar(c);
  }


}
