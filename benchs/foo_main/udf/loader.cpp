#include <cmath>
#include <stdio.h>
int foo_raw(int argc, char** argv);
int N=2; int M=2;

// int load_1(double* X);
// char** load_2(double* X);

// int load_1(double * X){
//   return 100;
// }


void foo(double * X){
  //foo_raw(load_1(X),load_2(X));


    char  c[2][2];

  c[0][0]=(char)std::floor(X[1]);
  c[0][1]=(char)std::floor(X[2]);
  c[1][0]=(char)std::floor(X[3]);
  c[1][1]=(char)std::floor(X[4]);

  char *param[2]={c[0],c[1]};


  foo_raw(11, param);

}
