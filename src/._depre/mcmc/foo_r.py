import os
import sys

import matplotlib
import numpy as np
import matplotlib.pyplot as plt
import scipy.optimize as op

X  = []
tol=1e-12

import ctypes
from ctypes import cdll

lib=cdll.LoadLibrary("../foo_r/libfoo_r.so")
lib.foo_r.argtypes=(ctypes.c_double,)
lib.foo_r.restype = ctypes.c_double
foo_r=lib.foo_r

def callback_global(x,f,accepted):
    global X
    X=[]
    if f<tol**2:
        X.append(x)
        conclusion= '==> good'
    else:
        conclusion= '==> not good enough'
    print("MCMC Sampling:: At x=%.5e,  f=%.5e,  accepted=%d %s" % (x,f, int(accepted), conclusion ))
    
def demo(niter=10,method='powell'):
    res=op.basinhopping(foo_r,10,callback=callback_global,minimizer_kwargs={'method':method},niter=niter,stepsize=5)
    print
    print res

if __name__ == "__main__":
#    for i in range(10):
#        print foo_r(i)
    demo()


