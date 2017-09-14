//#include <cmath>
#define __LITTLE_ENDIAN
#include "fdlibm.h"
#include <stdio.h>
double sin(double);
int main(){
  //  double x = 23.0;
  double x=3.14;
  double y = sin(x);
  printf("%f , %f \n", x,y);

  return 0;

}
