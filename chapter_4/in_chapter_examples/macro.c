#include <stdio.h>

#define forever for(;;)
#define max(A,B) ((A) > (B) ? (A) : (B))
#define square(x) (x) * (x) // don't forget parens!
#define dprint(expr) printf(#expr " = %g\n", expr);
#define paste(front, back) front ## back
/*
dprint(x/y) ->
printf("x/y" " = %g\n", x/y) -> concat.
printf("x/y = %g\n", x/y)

*/

int main()
{
  //forever;
  double z = 3;
  double q = 1;
  int paste(name, 1);
  name1 = 3; 
  dprint(z/q);
  printf("%f\n", square(z + 1));
  printf("%d\n", max(2,3));
  return 0;
}
