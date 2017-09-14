#include <cmath>
#include <set>
#include <iostream>
#include "tf.h"

static std::set<int> results={};

void tf_saveResults(double x){
  results.insert(tf_convert(x));

}
int tf_convert(double x){
  return (int) std::floor(x);
}

void tf_printResults(){
  long int i=0;
  std::cout<<"Total:" <<results.size()<<std::endl;
  for(std::set<int>::iterator ii=results.begin(); ii!=results.end();++ii){
    std::cout<<++i<<": "<<*ii<<std::endl;
  }

}
