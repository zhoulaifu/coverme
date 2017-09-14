#include <iostream>

extern "C" double foo_r(double*);

int main (){
    std::cout<<"Sanity Check"<<std::endl;
    double i1 []={0.1};
    double i2 []={2.5};

  //std::string s=tf_string(i1);
  // double x=foo_r(i1);

  //foo_raw(5);
  //     foo(i1);

    std::cout<<"foo_r({i1})="<<foo_r(i1)<<"; Expected: 36"<< std::endl;
    std::cout<<"foo_r({i2})="<<foo_r(i2)<<"; Expected: 0"<<std::endl;



    return 0;

}
