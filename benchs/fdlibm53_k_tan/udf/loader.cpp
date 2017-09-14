#include <cmath>
#include <stdio.h>
#include <stdlib.h>
double foo_raw ( double x,double y, int z);


void foo(double * X){
  int z= (int)std::floor(X[2]);
  foo_raw(X[0],X[1],z);
}
