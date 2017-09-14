import numpy 
import sys
import math

# TODO: do a better one. This is a clumsy solution!! 
def load(n,X):
    if n==0:
        return chr(numpy.uint8(int(math.floor(X[0]))))
    elif n==1:
        return chr(numpy.uint8(int(math.floor(X[1]))))
    else:
        return "Something goes wrong! @loader.load"
        sys.exit(1)

def rawDim():
    return 2

def inputDim():
    return 2
