import numpy 
import sys
import math

N=2
M=2
# TODO: do a better one. This is a clumsy solution!! 
def load(n,X):
    if n>N*M:
        return "Something goes wrong! @loader.load"
        sys.exit(1)
    (i,j)=divmod(n, M)
    return chr(numpy.uint8(int(math.floor(X[i*M+j]))))


def rawDim():
    return 4

def inputDim():
    return 4

if __name__=='__main__':
    X=[77,78,79.8,80.2]
    for i in range(4):
        print load(i,X)
