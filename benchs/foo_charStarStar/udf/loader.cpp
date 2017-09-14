#include <cmath>
#include <stdio.h>
void foo_raw(char** a);
int N=2; int M=2;


void foo(double * X){
  char  c[2][2];

  c[0][0]=(char)std::floor(X[0]);
  c[0][1]=(char)std::floor(X[1]);
  c[1][0]=(char)std::floor(X[2]);
  c[1][1]=(char)std::floor(X[3]);

  char *param[2]={c[0],c[1]};
  foo_raw(param);

}
