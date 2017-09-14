#include <cmath>
#include <stdio.h>
#include <math.h>
int main(){
  printf("%c\n",(char) 246 );
  printf("%d\n", (unsigned char) (246) );
  double whole = -135656454645645.45;
  int integral =((long) whole ) % 256;
  double fraction = whole - ((long)whole);
  printf("%f\n", fraction );
  printf("%d\n", integral );
  char c = 200;
  if (c<0){
      printf("NEGATIVE !!!!!!!!!!!!!!!!!!!!!!!!! %c\n ", c);
    }


  /*
  double somenumber = 1e-20;
  double integralPart;
  double fractionalPart = modf(somenumber, &integralPart);
  printf ("%g\n",integralPart);
  printf ("%g\n",fractionalPart);
  */

}
