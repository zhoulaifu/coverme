#include <iostream>
extern "C" double foo_r(double *);
int main (){
double i1 []={3.0,2.7};
  std::cout<<"foo_r("<<i1[0]<<","<<i1[1]<<")="<<foo_r(i1)<<std::endl;
   double i2 [] ={5.0,6.9};
   std::cout<<"foo_r("<<i2[0]<<","<<i2[1]<<")="<<foo_r(i2)<<std::endl;

  return 0;
}
