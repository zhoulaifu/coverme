#include <iostream>
void foo_raw(char* a[]);
void foo(double*);

int main(){
  std::cout<<"start"<<std::endl;
  char c[2][2]={
    {'a','b'},
    {'c','d'}
  };
  char** param = new char*[2]; // create your own pointer array
  param[0] = &c[0][0]; // assign the first element of each char array
  param[1] = &c[1][0];
  std::cout<<"mid"<<std::endl;
  foo_raw(param);
  std::cout<<"mid2"<<std::endl;
  double X[4];
  X[0]=0;X[1]=36;X[2]=46;X[3]=56;
  foo(X);

}
