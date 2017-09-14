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
  std::cout<<"foo_raw(1.5)="<<foo_raw(1.5)<<"  Expected ( close to 0.5 )"<<std::endl;
  std::vector<double> input;
  input.push_back(1);
  input.push_back(1.5);
  input.push_back(2);
  input.push_back(2.5);
  input.push_back(3);
  input.push_back(3.1);
  input.push_back(3.14);
  input.push_back(3.141);
  input.push_back(3.1415);
  for (unsigned int i=0; i<input.size(); i++) {
    double x = input[i];
    std::cout<<"x="<<x<<std::endl;
    std::cout<<"foo_raw(x)="<<foo_raw(x)<<"  Expected = "<< std::sin(x)<<std::endl<<std::endl;
    std::cout<<"sin(x)="<<sin(x)<<"  Expected = "<< std::sin(x)<<std::endl<<std::endl;
}  
  
  
  

  

}
