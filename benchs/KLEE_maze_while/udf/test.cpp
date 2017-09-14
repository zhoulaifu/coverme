#include <iostream>

extern "C" double foo_r(double*);

int main (){
    std::cout<<"Sanity Check"<<std::endl;
    double i1 []={0.1,120.5,77};
    double i2 []={100.2,119.4,77};
    double i3 []={119.5,6,6};
    double i4 []={119.5,119.4,6.6};
    double i5 []={119.5,119.4,119.9};
    double i6 []={6.6,119.4,119.9};
    double i7 []={6.6,6.6,119.9};
    double i8 []={6.6,118,119.9};




  //std::string s=tf_string(i1);
  // double x=foo_r(i1);

  //foo_raw(5);
  //     foo(i1);

    std::cout<<"foo_r({i1})="<<foo_r(i1)<<"; Expected: ?1"<< std::endl;
    /*
    std::cout<<"foo_r({i2})="<<foo_r(i2)<<"; Expected: ?0"<<std::endl;
    std::cout<<"foo_r({i3})="<<foo_r(i3)<<"; Expected: ?"<<std::endl;
    std::cout<<"foo_r({i4})="<<foo_r(i4)<<"; Expected: ?"<<std::endl;
    std::cout<<"foo_r({i5})="<<foo_r(i5)<<"; Expected: ?"<<std::endl;
    std::cout<<"foo_r({i6})="<<foo_r(i6)<<"; Expected: ?"<<std::endl;
    std::cout<<"foo_r({i7})="<<foo_r(i7)<<"; Expected: ?"<<std::endl;
    std::cout<<"foo_r({i8})="<<foo_r(i8)<<"; Expected: ?"<<std::endl;
    */


    return 0;

}
