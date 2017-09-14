#include <cmath>
#include <stdio.h>
int foo_raw(int argc, char** a){

  if (argc>10){
    printf("Good!!!!!!!!!!!!!!!!!!!!!!\n");
  }

  //  if ( a[0][0]=='h' || a[1][0]=='i'){
  //   return;
  //  }
  fprintf(stderr, "argc=%d,\n a=%c,%c, %c, %c\n", argc, a[0][0],a[0][1],a[1][0],a[1][1]);

  return 0;
}

/*
int N=2; int M=2;
void foo(double * X){
  char  c[2][2];

  c[0][0]=(char)std::floor(X[0]);
  c[0][1]=(char)std::floor(X[1]);
  c[1][0]=(char)std::floor(X[2]);
  c[1][1]=(char)std::floor(X[3]);
  //break the system

  int x=2014;
  int y = x;
  if (x==y){ x = y;}

  char *param[2]={c[0],c[1]};
  foo_raw(param);

}
*/
