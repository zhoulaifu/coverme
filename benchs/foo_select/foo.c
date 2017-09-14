
#include <stdio.h>

//http://lists.cs.uiuc.edu/pipermail/llvmdev/2013-April/061156.html
double foo_raw(double x)
{
  int u = x<=0? 99:42;
  /* printf ("%d",u); */
  if (u>0)
    return -1; 

  return x > -1 ? 123: 321;
}

