import math
import sys
def load(n,X):
    if n==0:
        return int(math.floor(X[0]))
    elif n==1:
        return X[1]
    else:
        return "Something goes wrong! @loader.load"
        sys.exit(1)

def rawDim():
    return 2
