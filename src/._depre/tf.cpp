#include <iostream>
#include <string>
#include <cmath>
#include <set>

#include "tf.h"
#include <array>
#include "foo.h"
#include <sstream>

static std::set<tf_inputTy> results={};

void tf_saveResults(const tf_inputTy& input){
  //TODO save element-unique arrays (not the pointer)
  results.insert(tf_convertInput(input));

}
//depreciated
void tf_printResults(){
  long int i=0;
  std::cout<<"Total:" <<results.size()<<std::endl;
  for(std::set<tf_inputTy>::iterator ii=results.begin(); ii!=results.end();++ii){

    std::cout<<++i<<": ";
    for(const auto& s: *ii)
      std::cout << s << ' ';

    std::cout<<std::endl;
  }

}


//ATTENTION: use appropriate reference type to avoid copy
const tf_inputTy& tf_convertInput(const tf_inputTy& input){
  //  throw "Not implemented"
   return input;
}

/*
std::ostream& operator<< (std::ostream& out, tf_inputTy& input){
 for(const auto& s:  input)
    out << s << ' ';
  return out;
}
*/
std::ostream & operator << ( std::ostream & output, tf_inputTy & array){

  for (unsigned int i = 0; i < array.size(); i++)
    output << (i==0?"":",")<<array[i] ;
   return output;
}
 std::string tf_string(tf_inputTy& input){
  std::stringstream ss;
  ss<<input;
  return ss.str();
}
