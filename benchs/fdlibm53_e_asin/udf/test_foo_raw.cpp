//g++ test_foo_raw.cpp ../foo.c ../libm.a 
#include <iostream>
#include <vector>

#include "fdlibm.h"
double foo_raw(double x);
 
int main(){
  double x = 3.1;
  double y=foo_raw(x);
  std::cout<<"Working...\n";
  //  std::cout<<"foo_raw(x)="<<y<<"  Expected (close to 0)"<<std::endl;
  std::cout<<"foo_raw(1.5)="<<foo_raw(1.5)<<"  Expected ( 1 )"<<std::endl;
  std::vector<double> input;
  input.push_back(1);
  input.push_back(1.5);
  input.push_back(2);
  input.push_back(2.5);
  input.push_back(3);
  input.push_back(3.5);
  input.push_back(-1.5);
  input.push_back(-3.5);
  input.push_back(-4.7);
  for (unsigned int i=0; i<input.size(); i++) {
    double x = input[i];
    std::cout<<"x="<<x<<std::endl;
    std::cout<<"foo_raw(x)="<<foo_raw(x)<<"  Expected = "<<std::endl<<std::endl;

  }
  

}
