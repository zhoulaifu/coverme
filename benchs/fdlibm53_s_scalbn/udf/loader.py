import math
import numpy
def load(n,X):
    if n==0:
        return X[0]
    elif n==1:
        return int(math.floor(X[1]))
    else:
        return "Something goes wrong! @loader.load"
        sys.exit(1)


def inputDim():
    return 2
