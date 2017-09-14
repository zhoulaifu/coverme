#include <cmath>
#include <stdio.h>
#include <stdlib.h>
double foo_raw ( double x,double* y);


void foo(double * X){
  double y[1];
  y[0]=X[1];
  foo_raw(X[0],y);
}
