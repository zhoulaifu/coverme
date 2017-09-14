#include <iostream>

extern "C" double foo_r(double*);

int main (){
    std::cout<<"Sanity Check"<<std::endl;
    double i1 []={2,9};
    double i2 []={2,4.9};
    double i3 []={0,0};

  //std::string s=tf_string(i1);
  // double x=foo_r(i1);

  //foo_raw(5);
  //     foo(i1);

    std::cout<<"foo_r({"<<i1[0]<<","<<i1[1]<<"})="<<foo_r(i1)<<"; Expected: 0"<< std::endl;
    std::cout<<"foo_r({"<<i2[0]<<","<<i2[1]<<"})="<<foo_r(i2)<<"; Expected: 0"<<std::endl;

  std::cout<<"foo_r({"<<i3[0]<<","<<i3[1]<<"})="<<foo_r(i3)<<" Expected: 36"<<std::endl;

  return 0;

}
