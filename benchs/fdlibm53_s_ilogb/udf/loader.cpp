#include <cmath>
#include <stdio.h>
int foo_raw ( double x);


void foo(double * X){
  foo_raw(X[0]);
}
