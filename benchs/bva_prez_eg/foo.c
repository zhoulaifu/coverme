#include <stdio.h>

void foo(double x){
  if (x<=1.0)
    x++;
  double y = x*x;
  if (y==4.0)
    printf ("abort\n");
}
    
