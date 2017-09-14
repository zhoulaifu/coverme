# Goal: solve the pb of when calculate the branches.
# This version is based on shen3_loop_DB, ie, the  unfolded loop version.

import scipy.optimize as op
import operator
import time
import math
import numpy as np
import pdb

delta=1e-15
initR=1

DB=True
passStaged=dict()
nPass=dict()
maoStaged=set()
mao=set()
maoCandidate={-1}

exploredLeaf=set()

dead=set()
deadStaged=set()

explored=set()
lastBr=None
abandoned=set()
abandonCandidate=None
passStaged_per_global=dict()

i_pen=0
i_pen_supersimple=0

i_local=0
def callback_local(x):
    global  i_local
    i_local+=1
    if DB:
        print "%s-th :  LOCAL callback time " %(i_local)

    for br in passStaged_per_global:
        nPass[br]=passStaged_per_global.get(br,0)+nPass.get(br,0)
    passStaged_per_global.clear()


i_global=0
abandonFrequence=5
def callback_global(l,f,accepted):
#    assert passed #ie, not empty
    global i_global
    i_global+=1
    print "%s-th : @GlobalL callback " %(i_global)

    if i_global % abandonFrequence !=0:
        return
    print "@Callback_global"

    if DB:
        print "explored before= ",explored
    if lastBr is not None:
        lastBr2=(lastBr[0],not lastBr[1])
    else:
        lastBr2=None
    if lastBr2 is not None:
        if nPass.get(lastBr2,0)==0: #####!!!
            explored.add(lastBr2)
            abandoned.add(lastBr2)
            if DB:
                print "abandoned branch added to explored",lastBr2

    if DB:
        print "explored after= ",explored

i_foo_r=0


i_foo_AND_int=0


def amplifier_0630(x):
    assert not math.isinf(x)
#    return np.exp(x/100.0)
    return 42*x**8+1


##this one works for "infeasible "
def pen_0630(r,lhs,rhs,op=operator.eq, instID=0):
    global lastBr
    global i_pen
###    global abandonCandidate
    i_pen+=1
    br=(instID,op(lhs,rhs))
    br2=(instID, not op(lhs,rhs))
    thisExplored=br in explored or (br in passStaged or br2 in passStaged)
    thatExplored=br2 in explored or (br2 in passStaged or br in passStaged)
    ret=-1
    dist=abs(lhs-rhs) ##TODO

    if br in abandoned: ##TODO
        print "WWWWWWWWWWWWWWWWAAAAAAAAAAAAAAAAARRRRRRRRRRRRRRRNNNNNNNNNNNING. Revive an abandoned        I suppose this is impossible. br = ", br
        abandoned.remove(br)

    if thisExplored and thatExplored:
        if DB:
            print "quit early because both children",br,br2, "are explored"
        return r

#    fn=amplifier_0630(nPass.get(br,0)- nPass.get(br2,0))
    fn=amplifier_0630(nPass.get(br,0))

    if thatExplored:
        choice=1
        assert not thisExplored
        ret = r
    else:
        choice=2

        ret=dist * fn
    ###    abandonCandidate=br2




    if DB:
        print "  %d): PENALTY (pen_0630)" %i_pen
        print "     | br,br2<-lastBr = (%s, %s <- %s)" %(br,br2,lastBr)
        print "     | choice = %s" %(choice)

        print "     | explored = %s" %(explored)
        print "     | this,that = (%s, %s)" %(thisExplored,thatExplored)
        print "     | lhs,rhs = %.16e,%.16e" %(lhs,rhs)
        print "     | nPass.get(br,0), nPass.get(br2,0) = %d,%d" %(nPass.get(br,0), nPass.get(br2,0))
        print "     | fn = %.2e" %fn


        print "     | ret = %.16e" %ret



    lastBr=br

    passStaged[br]=passStaged.get(br,0)+1

    return ret



def threeChar_DB(program):

#    f2c=lambda x: np.uint8(math.floor(x))
    f2c=lambda x: int(math.floor(x))
    a=f2c(program[0])
    b=f2c(program[1])
    c=f2c(program[2])

    r=1
    global i_foo_r
    i_foo_r+=1

    global lastBr
    lastBr=None
    pen=pen_0630

    if DB:
        print "%d: ENTERIRING foo_r with x = %s" %(i_foo_r,program)
        print


    r = pen(r, a,97,operator.eq, 3)
    if (a==97):
        print("a=97 Branch\n")
        r = pen(r, a,119,operator.eq, 4)#*1e80
        if (a==119):
            print("  L4 (impossible)\n")


    r = pen(r, a,119,operator.eq, 0)#*1e80
    if (a==119):
        print("  L1\n")
        pass
        r = pen(r, ,1119,operator.eq, 1)#*1e50
        if (a==1119):
            pass
            print("  L2\n")
            r = pen(r, c,119,operator.eq, 2)
            if (c==119):
                pass
                print("Getting into w3\n")


    if DB:
        print "  LEAVING foo_r with r = %.20e" %(r)
        print

    if lastBr is not None:

        explored.add(lastBr)

    for br in passStaged:
        passStaged_per_global[br]=passStaged.get(br,0)+passStaged_per_global.get(br,0)

    passStaged.clear()



    return r


start=[-500,500,500]
test= threeChar_DB

def demo( niter=10, stepsize=50,debug=True, seed=-1):
    if seed >=0:
        np.random.seed(seed)
    global DB
    DB=debug
    try:
        if nPass:
            print "WARNING: At start time, 'passed' is defined and not empty!! \n passed =  %s" % nPass
    except NameError:
        print "Checking whether 'passed' is undefined in the beginning... OK"

#    explored={[4,True],[4,False]}
    kw={'method':'powell','callback':callback_local}
    #    kw={'method':'powell'}
#    test=lambda X:0
    res=op.basinhopping(test,start,minimizer_kwargs=kw,niter=niter,stepsize=stepsize,callback=callback_global,disp=DB)#,accept_test=MyBounds())
    print "++++++++++++++"


    print res

    print "nPass:"
    print nPass
    print
    print "explored number = ", len(explored),":"
    print explored
    print
    print "abandoned:"
    print abandoned
