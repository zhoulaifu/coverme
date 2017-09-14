import math
import sys
def load(n,X):
    if n==0:
        return int(math.floor(X[0]))
    elif n==1:
        return int(math.floor(X[1]))
    elif n==2:
        return int(math.floor(X[2]))
    elif n==3:
        return int(math.floor(X[3]))
    elif n==4:
        return int(math.floor(X[4]))
    elif n==5:
        return int(math.floor(X[5]))

    else:
        return "Something goes wrong! @loader.load"
        sys.exit(1)

def rawDim():
    return 5

def inputDim():
    return 5
