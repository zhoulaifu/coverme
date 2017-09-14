#include <cmath>
#include <stdio.h>
#include <stdlib.h>
double foo_raw (int x,double y);


void foo(double * X){
  int x=0;
  float f = X[0];
  if (not std::isnan(f) and (not std::isinf(f)))
     x = (int)f;

  foo_raw(x,X[1]);
}
