#include <cmath>
#include <stdio.h>
void foo_raw(char** a){
  //  if (a[0]=='h'){

  //  if (a[0]=='h' || a[1]=='s'){
    if ( a[0][0]=='h' || a[1][0]=='i'){
      return;
    }
    fprintf(stderr, "%c, %c, %c, %c\n", a[0][0],a[0][1],a[1][0],a[1][1]);

  return;
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
