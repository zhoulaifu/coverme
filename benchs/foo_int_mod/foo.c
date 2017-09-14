#include <iostream>
#include <cmath>

//user-raw function
bool foo_raw(int i){

  if (i % 30 ==20)
        return true;

  if (i % 3 ==2)
      return false;


  return true;
}


int d2i(double x){
  return (int)(std::floor(x));
}

void foo(double* X){
  int i = d2i(X[0]);
  foo_raw(i);
}

