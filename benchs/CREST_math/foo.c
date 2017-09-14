#include <cmath>

int foo_raw  (int a, int b, int c, int d, int e){
  if (3*a + 3*(b - 5*c) + (b+c) - a == d - 17*e) {
    return 1;
  } else {
    return 0;
  }
}

void foo(double * X){
  int a=(int) std::floor(X[0]);
  int b=(int) std::floor(X[1]);
  int c=(int) std::floor(X[2]);
  int d=(int) std::floor(X[3]);
  int e=(int) std::floor(X[4]);
  foo_raw(a,b,c,d,e);
}


/* From Crest Bench
#include <crest.h>

int main(void) {
  int a, b, c, d, e;
  CREST_int(a);
  CREST_int(b);
  CREST_int(c);
  CREST_int(d);
  CREST_int(e);
  if (3*a + 3*(b - 5*c) + (b+c) - a == d - 17*e) {
    return 1;
  } else {
    return 0;
  }
}

*/
