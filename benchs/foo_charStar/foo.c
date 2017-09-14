#include <cmath>

void foo_raw(char* a){
  //  if (a[0]=='h'){

  //  if (a[0]=='h' || a[1]=='s'){
    if (a[1]=='s' || a[0]=='h'){
    return;
  }
  return;
}

int N=2;
void foo(double * X){
  char  a[2];
  a[0]=(char)std::floor(X[0]);
  a[1]=(char)std::floor(X[1]);
  foo_raw(a);

}
