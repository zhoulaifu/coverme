#ifndef _TF_H_
#define _TF_H_
#include <array>
#include <string>
#include <iostream>
#include "foo.h"
//typedef std::array<double,2> tf_inputTy;
//typedef void tf_outputTy;

//analysis result
void tf_saveResults(const tf_inputTy&);
void tf_printResults();

//analysis input
const tf_inputTy& tf_convertInput(const tf_inputTy&);

std::string tf_string(tf_inputTy& input);

std::ostream & operator << ( std::ostream & output, tf_inputTy & array);


#endif

/* old one used in single variable

void tf_saveResults(double);
int tf_convert(double);
void tf_printResults();
*/
