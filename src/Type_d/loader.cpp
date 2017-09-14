#include <cmath>
#include <stdio.h>
extern "C"{
double foo_i ( double x);
}

void foo(double * X){
  foo_i(X[0]);
}
