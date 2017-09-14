#include <cmath>
#include <stdio.h>
double foo_raw ( double x);


void foo(double * X){
  foo_raw(X[0]);
}
