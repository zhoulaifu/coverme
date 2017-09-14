#include <cmath>
#include <stdio.h>
extern "C"{
double foo_raw ( double x);
}

void foo(double * X){
  foo_raw(X[0]);
}
