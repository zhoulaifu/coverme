#include <cmath>
#include <stdio.h>
void foo_raw ( char* program);
static const int ITERS=3;

void foo(double * X){

  char program[ITERS];
  for (int i = 0; i<ITERS; i++){
    program[i]=static_cast<char>(std::floor(X[i]));
    //    if (program[i]<0){
    //  printf("NEGATIVE !!!!!!!!!!!!!!!!!!!!!!!!! %c\n ", program[i]);
    //}
  }
  foo_raw(program);
}

/*
 int main(){
   double X[2];
   X[0]=1.2;
   X[1]=118;

   printf("First call Expected: show nothing\n");
   foo(X);
   X[1]=78;
   printf("Second call Expected: show nothing\n");
   foo(X);
   X[0]=119.8;
   printf("Third call Expected: show something\n");
   foo(X);
   X[1]=5000;
   printf("Last call. Expected: show something\n");
   foo(X);

 }
*/
