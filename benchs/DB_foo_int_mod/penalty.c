//#include <cstdio.h>

#include <stdio.h>
//TODO decomment
#include "foo.h"
#include "foo_r.h"
//#include "penalty.h"
#include <stdio.h>
//Use global var is simpler to implement, but also means that I should not apply this in a multithreadly to simultanously track more  than one function 

double __r; //representing func.
double __d; //for depth

void __pen(double x, double y){
     printf ("x=%f\n", x);
     printf ("y=%f\n", y);
     __d++;
     __r*=(x-y)*(x-y);
     
}

//double initPen(){return 1;}


//This func. might be called N times, where N is the number of sampling.
double foo_r(double x){
   //  printf ("Hello, I am here!!!!!!!!!!!!!!!File foo_r.c\n");
  __d=0;
  __r=1;        
  foo(x); //which invokes __pen in its body
  
    printf ("__r=%f\n", __r);
     printf ("__d=%f\n", __d);
     
  return __r;
}
/*
int test(){
  printf ("foo_r(3.0)=%f (expected: 16)\n",foo_r(3.0));
  printf ("foo_r(5.0)=%f (expected: 4)\n",foo_r(5.0));

}
*/
