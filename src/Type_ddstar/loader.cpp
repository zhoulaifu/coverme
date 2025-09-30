#include <cmath>
#include <stdio.h>
extern "C"{
double foo_i ( double x,double* y);
}

void foo(double * X){
	double y[1];
	y[0]=X[1];

	foo_i(X[0],y);
	
}
