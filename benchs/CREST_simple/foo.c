#include <stdio.h>
#include <cmath>
int foo_raw(int a, int b){
  b = 3 * a + 2;
  if (b == 8) {
    printf("8\n");
  } else {
    printf("not 8\n");
  }
  return 0;
}

void foo(double* X){
  int a=(int) std::floor(X[0]);
  int b=(int) std::floor(X[1]);
  foo_raw(a,b);
}







/*from CREST https://github.com/jburnim/crest/blob/master/test/simple.c
int main(void) {
  int a, b;
  CREST_int(a);
  b = 3 * a + 2;
  if (b == 8) {
    printf("8\n");
  } else {
    printf("not 8\n");
  }
  return 0;
}
*/
