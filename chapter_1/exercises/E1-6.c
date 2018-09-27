#include <stdio.h>

int main()
{

  printf("Remember that control + D on linux/unix is EOF...\n\n");
  printf("%d\n", getchar() != EOF);
}
