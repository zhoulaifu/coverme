#include <cmath>
#include <stdio.h>
#include <stdlib.h>
double foo_raw ( double x,double y);


void foo(double * X){
  foo_raw(X[0],X[1]);
}
