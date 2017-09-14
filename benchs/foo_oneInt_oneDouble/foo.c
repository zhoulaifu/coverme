#include <cmath>
void foo_raw(int x, double y){
  if (x<=3)
    return;

  if (y<=5.1)
    return;

  return;

}


void foo(double * X){
  int x=(int)std::floor(X[0]);
  double y= X[1];
  foo_raw(x,y);
}
