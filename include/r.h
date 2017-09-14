#ifndef R_H
#define R_H
//use extern because this function is to called by python ctypes.


extern "C" double foo_r(double[]);
extern "C" void call_tf_printResults();

#endif
