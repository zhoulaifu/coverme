#include <cmath>
int foo_raw(short a);

void foo(double * X){
  short a=(short) std::floor(X[0]);
  foo_raw(a);
}
