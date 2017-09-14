
#include <stdio.h>

double foo_raw(double x)
{
  if (x<0){
    printf("A1!!\n");
    if (x>1)
      printf("Another impossible case!!\n");
      
  }
  double y=x*x;
  if (y<=-1){
    printf("Impossible!!\n");
  }
  else{
    if (y >=1){
      printf("OK!\n");
    }
    }

  if (y<=0.01)
    printf(" Possible!!\n");

    
  return 0;
}

