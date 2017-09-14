#include <stdio.h>
void foo(double x){
  if (x<=1){
    printf ("0T\n");
    x++;
  } else {
    printf ("0F\n");
  }
  if (x*x*x==4){
    printf ("1T\n");
    x--;
  }
  else {    printf ("1F\n");}
  return;
}
