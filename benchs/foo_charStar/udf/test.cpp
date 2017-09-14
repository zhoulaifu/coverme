#include <iostream>

extern "C" double foo_r(double*);

int main (){
    std::cout<<"Sanity Check"<<std::endl;
    double i1 []={3.14, 4.13};
    double i2 []={104.1, 2};
    double i3 []={104.5, 2000};

  //std::string s=tf_string(i1);
  // double x=foo_r(i1);

  //foo_raw(5);
  //     foo(i1);

    std::cout<<"foo_r({i1})="<<foo_r(i1)<<"; Expected: 10201"<< std::endl;
    std::cout<<"foo_r({i2})="<<foo_r(i2)<<"; Expected: 0"<<std::endl;

    std::cout<<"foo_r({i3})="<<foo_r(i3)<<" Expected: 0"<<std::endl;

    return 0;

}
