import matplotlib
import numpy as np
import matplotlib.pyplot as plt
import scipy.optimize as op

X  = []
tol=1e-7

def foo(x):
    if (x<=7):
        x+=1
    return x

def foo_(x):
    __r=1.0

    __r*=(x-7.0)*(x-7.0)
    if (x<=7):
        x+=1
    return (__r,x)


def foo_r(x):
    __r,=foo_(x)
    return __r


def callback_global(x,f,accepted):
    global X
    X=[]
    if f<tol**2:
        X.append(x)
        conclusion= '==> good'
    else:
        conclusion= '==> not good enough'
    print("MCMC Sampling:: At x=%.10f,  f=%.10f,  accepted=%d %s" % (x,f, int(accepted), conclusion ))
    
def demo(niter=5,method='powell'):
    res=op.basinhopping(foo_r,10,callback=callback_global,minimizer_kwargs={'method':method},niter=niter,stepsize=1)
    print
    print res

if __name__ == "__main__":
    demo()

