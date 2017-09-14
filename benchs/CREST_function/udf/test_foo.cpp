#include <iostream>
int foo_raw(short a);

void foo(double * X);

int main(){
  short a=2;
  int b=foo_raw(a);
  std::cout<<"foo_raw(a)="<<b<<"  Expected 1"<<std::endl;
  std::cout<<"foo_raw(a+1)="<<foo_raw(a+1)<<"  Expected 0"<<std::endl;

}
