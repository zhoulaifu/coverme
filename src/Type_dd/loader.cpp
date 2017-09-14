#include <cmath>
#include <stdio.h>
extern "C"{
double foo_i ( double x,double y);
}

void foo(double * X){
  foo_i(X[0],X[1]);
}
