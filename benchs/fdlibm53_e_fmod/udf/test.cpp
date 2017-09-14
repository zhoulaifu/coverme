#include <iostream>

extern "C" double foo_r(double*);

int main (){
    std::cout<<"Sanity Check"<<std::endl;
    double i1 []={0,2.5};
    double i2 []={0.785398163397448,5.6};
    double i3 []={0.79,-290.45};
// 1: [0.0]                                      -> 0.0
// 2: [1.0]                                      -> 0.0
// 3: [2.6180339999999998]                       -> 0.0
// 4: [-20.033025685813769]                      -> 0.0
// 5: [-19.033025685813769]                      -> 0.0


    std::cout<<"foo_r({i1})="<<foo_r(i1)<<";  Expected::  0 (first time pass)"<< std::endl;
    std::cout<<"--------------------"<<std::endl;
    std::cout<<"foo_r({i2})="<<foo_r(i2)<<"; Expected:: 0 (first time pass)"<< std::endl;
    std::cout<<"--------------------"<<std::endl;
    std::cout<<"foo_r({i3})="<<foo_r(i3)<<"; Expected:: 0 (first time pass)"<< std::endl;

    return 0;

}
