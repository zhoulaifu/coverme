#include "fdlibm.h"
#include <stdio.h>

int main(){
  double x = 23;
  double y = sin(x);
  printf("%f , %f \n", x,y);

  return 0;

}
