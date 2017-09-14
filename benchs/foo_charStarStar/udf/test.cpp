#include <iostream>

extern "C" double foo_r(double*);

int main (){
    std::cout<<"Sanity Check"<<std::endl;
    double i1 []={44890, 4.13,8766,3890};
    double i2 []={105.1, 111,246,999.8};
    double i3 []={0, 88.99,105.88,99};

  //std::string s=tf_string(i1);
  // double x=foo_r(i1);

  //foo_raw(5);
  //     foo(i1);

    std::cout<<"foo_r({i1})="<<foo_r(i1)<<"; Expected: ?"<< std::endl;
    std::cout<<"foo_r({i2})="<<foo_r(i2)<<"; Expected: 1"<<std::endl;

    std::cout<<"foo_r({i3})="<<foo_r(i3)<<" Expected: 0"<<std::endl;

    return 0;

}
