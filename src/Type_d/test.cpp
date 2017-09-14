#include <iostream>
extern "C" double foo_r(double *);
int main (){
double i1 []={3.0};
  std::cout<<"foo_r("<<i1[0]<<")="<<foo_r(i1)<<std::endl;
   double i2 [] ={5.0};
   std::cout<<"foo_r("<<i2[0]<<")="<<foo_r(i2)<<std::endl;

  return 0;
}
