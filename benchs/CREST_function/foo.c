#include <cmath>

short dbl(short x) {
  return 2*x;
}

int foo_raw(short a){

  if (dbl(a) + 3 == 9) {
    return 0;
  } else {
    return 1;
  }
}



/* From Crest Bench
#include <crest.h>
#include <stdio.h>

short dbl(short x) {
  return 2*x;
}

int main(void) {
  short a;
  CREST_short(a);
  if (dbl(a) + 3 == 9) {
    return 0;
  } else {
    return 1;
  }
}
*/
