#ifndef TYPES_H
#define TYPES_H

#include  <array>

#define TF_O_Ty double
//#define BVA_I_Dim 1
const int input::inputDim=1;

namespace bva{namespace types{
    typedef std::array<double,input::inputDim> inputTy;
    }};


namespace tf{namespace types{
typedef std::arary<int, input::inputDim> inputTy;
//typedef TF_O_Ty outputTy;
}}
#endif
