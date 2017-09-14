

/* @(#)s_sin.c 1.3 95/01/18 */
/*
 * ====================================================
 * Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
 *
 * Developed at SunSoft, a Sun Microsystems, Inc. business.
 * Permission to use, copy, modify, and distribute this
 * software is freely granted, provided that this notice 
 * is preserved.
 * ====================================================
 */

/* sin(x)
 * Return sine function of x.
 *
 * kernel function:
 *	__kernel_sin		... sine function on [-pi/4,pi/4]
 *	__kernel_cos		... cose function on [-pi/4,pi/4]
 *	__ieee754_rem_pio2	... argument reduction routine
 *
 * Method.
 *      Let S,C and T denote the sin, cos and tan respectively on 
 *	[-PI/4, +PI/4]. Reduce the argument x to y1+y2 = x-k*pi/2 
 *	in [-pi/4 , +pi/4], and let n = k mod 4.
 *	We have
 *
 *          n        sin(x)      cos(x)        tan(x)
 *     ----------------------------------------------------------
 *	    0	       S	   C		 T
 *	    1	       C	  -S		-1/T
 *	    2	      -S	  -C		 T
 *	    3	      -C	   S		-1/T
 *     ----------------------------------------------------------
 *
 * Special cases:
 *      Let trig be any of sin, cos, or tan.
 *      trig(+-INF)  is NaN, with signals;
 *      trig(NaN)    is that NaN;
 *
 * Accuracy:
 *	TRIG(x) returns trig(x) nearly rounded 
 */
#define __LITTLE_ENDIAN

#include "fdlibm.h"
#include <stdio.h>

	double foo_raw(double x)
{
	double y[2],z=0.0;
	int n, ix;
        //        printf("******added something in s_sin.c so it can be reflected in  libm.a!\n");
    /* High word of x. */
	ix = __HI(x);
        
    /* |x| ~< pi/4 */
	ix &= 0x7fffffff;
	if(ix <= 0x3fe921fb) {
          printf ("A1\n");
          return __kernel_sin(x,z,0);

        }
    /* sin(Inf or NaN) is NaN */
	else if (ix>=0x7ff00000) {
          
          printf ("   A2\n");
          
          return x-x;
        }
    /* argument reduction needed */
	else {
         
        

	    n = __ieee754_rem_pio2(x,y);
            printf ("  n = %d\n", n);
            printf ("  n&3 = %d\n", n&3);
              //change this to reflect logic otherwise, 'return do not work'
            if ((n&3)==0){
              printf ("    A4\n");
              return  __kernel_sin(y[0],y[1],1);
            }
            else if ((n&3)==1){
              printf ("           A5\n");
              return  __kernel_cos(y[0],y[1]);
            }
            else if ((n&3) ==2){
              printf ("                       A6\n");
              return -__kernel_sin(y[0],y[1],1);
            }
            else{
              printf ("                                     A7\n");
              return -__kernel_cos(y[0],y[1]);
            }
            /*original code uses 'switch'
	    switch(n&3) {

            case 0: return  __kernel_sin(y[0],y[1],1);
		case 1: return  __kernel_cos(y[0],y[1]);
		case 2: return -__kernel_sin(y[0],y[1],1);
		default:
			return -__kernel_cos(y[0],y[1]);
	    }
            */
	}
}

