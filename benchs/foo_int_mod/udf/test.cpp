#include <iostream>


extern "C" double foo_r(double*);
// void foo(double*);

//bool foo_raw(int i);
  //    return true;


int main (){
  /*
     printf ("foo_r(3.0)=%f (expected, if bench=foo,  16)\n",foo_r(3.0));
     printf ("foo_r(5.0)=%f (expected, if bench=foo,  4)\n",foo_r(5.0));
     printf ("foo_r(20.0)=%f\n ",foo_r(20.0));
  */
  std::cout<<"Sanity Check"<<std::endl;
  double i1 []={3};
  double i2 []={5};
  double i3 []={20.0};

  //std::string s=tf_string(i1);
  // double x=foo_r(i1);

  //foo_raw(5);
  //     foo(i1);

  std::cout<<"foo_r({"<<3.0<<"})="<<foo_r(i1)<<"; Expected: 4"<< std::endl;
  std::cout<<"foo_r({"<<5.0<<"})="<<foo_r(i2)<<"; Expected: 0"<<std::endl;
  std::cout<<"Sanity Check 3::"<<std::endl;
  std::cout<<"foo_r({"<<20.0<<"})="<<foo_r(i3)<<" Expected: 0"<<std::endl;

  return 0;
}
