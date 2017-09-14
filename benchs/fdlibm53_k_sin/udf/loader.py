import math
import numpy
def load(n,X):
    if n==0:
        return X[0]
    elif n==1:
        return X[1]
    elif n==2:
        return int(math.floor(X[2]))
    else:
        return "Something goes wrong! @loader.load"
        sys.exit(1)


def inputDim():
    return 3
