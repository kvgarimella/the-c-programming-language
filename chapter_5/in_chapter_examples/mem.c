#include <stdio.h>

#define ALLOCSIZE 10000

static char allocbuf[ALLOCSIZE];
static char *allocp =  allocbuf;

char *alloc(int n);
void afree(char *p);
// the pointer allocbuf currently points to zero.
// we could have also done.
// static char *allocbuf = &allocbuf[0];

int main()
{
  return 0;
}

char *alloc(int n)
{
  if (allocbuf + ALLOCSIZE - allocp >= n)
  {
    allocp += n; // increment pointer to new free loc
    return allocp - n; // return old pointer;
  }
  else
  {
    return 0; // not enough room in our buffer.
  }
}

void afree(char *p)
{
  if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
  {
    allocp = p;
  }
}
