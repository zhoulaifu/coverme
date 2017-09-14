#!/usr/bin/env python
import os
import sys
import time
import matplotlib
import numpy as np
import matplotlib.pyplot as plt
import scipy.optimize as op
import ctypes
from ctypes import cdll
import argparse
from ConfigParser import SafeConfigParser
import collections

class Verbose:
    Silent,Alert, Routine,Debug = range(4)

root_dir = os.path.split(os.path.abspath(os.path.dirname(__file__)))[0]
sys.path.append(root_dir)
import config

loader_dir=config.loader_dir()
sys.path.append(loader_dir)
import loader


bv_original = collections.OrderedDict()
bv = collections.OrderedDict()



lib=cdll.LoadLibrary(config.libr_so_dir())


lib.foo_r.restype = ctypes.c_double

DB=True
DB=False

from UserDict import UserDict
class repf(UserDict):

     def __init__(self):
          UserDict.__init__(self)
#          self.lib=cdll.LoadLibrary(config.libr_so_dir())
          self['nExplored']=lib.nExplored
          self['explored']=self.getExplored


     def getExplored(self):

          lib.explored_part1.restype=(ctypes.POINTER(ctypes.c_int))
          lib.explored_part2.restype=(ctypes.POINTER(ctypes.c_int))

          a = lib.explored_part1()
          b = lib.explored_part2()

          ret=set()
          for i in range(lib.nExplored()):
               ret.add((a[i], (b[i]==1)))
          return ret
     def get_nExplored(self):
          lib=cdll.LoadLibrary(config.libr_so_dir())

          return lib.nExplored()
     def get_nCovered(self):
          return lib.nCovered()
          
     def get_nConditionStatement(self):
          with open(config.brInfo_dir()) as f:
               return (sum(1 for _ in f))
     def exploredRatio(self):
          try:
               return self.get_nExplored()*1.0/ ( self.get_nConditionStatement()*2.0 )
          except ZeroDivisionError as detail:
               print 'No branches detected, considered as full coverage:'
               return 1
     def coverage(self):
          try:
               return self.get_nCovered()*1.0/ ( self.get_nConditionStatement()*2.0 )
          except ZeroDivisionError as detail:
               print 'No branches detected, considered as full coverage:'
               return 1

r=repf()

#input should be a numpy array
def foo_py(x):
     explored0=r.get_nExplored()

     x2=x.ctypes.data_as(ctypes.POINTER(ctypes.c_double))

     ret=lib.foo_r(x2)


     explored1=r.get_nExplored()
     if explored1>explored0:
          bv_original[tuple(x)]=ret
          y=[loader.load(n,x) for n in range(loader.inputDim())]
          bv[tuple(y)]=ret
     return ret


i_local=0

def callback_local(x):
     global i_local
     i_local+=1
     if args.verbose>=Verbose.Debug:
          print ("%d: XXXX Local CALLBACK, with passStaged() of the round:" %(i_local))
          lib.print_passStaged()
     lib.pushStaged()
     if args.verbose>=Verbose.Debug:
          print "nPass after pushStaged "
          lib.print_nPass()
          print "explored"
          print "lib.print_explored(): "
          lib.print_explored()
  
i_global=0
def callback_global(x,f,accepted):
     global i_global
     i_global+=1
     if args.verbose>=Verbose.Debug:
          print "%s -th @@@@@ Global CALLBACK  " %i_global
     if i_global % args.abandon==0:
          lib.addHardBranchAsExplored()


     #so we can stop earlier
     if r.exploredRatio()>=args.objective:
          return True



def demo(startPoint=10, niter=10,method='powell',stepSize=5):
    res=op.basinhopping(foo_py,startPoint,callback=callback_global,minimizer_kwargs={'method':method},niter=niter,stepsize=stepSize,niter_success=50)
#use minimizer_kwargs={'method':method,'callback':callback_local} for local_callback
###accept test

def mybounds(**kwargs):
    x_new = kwargs["x_new"]
    x_old = kwargs["x_old"]
    f_new = kwargs["f_new"]
    f_old = kwargs["f_old"]

    return True



if __name__ == "__main__":

    message='[BVA parameter parsing] ... '
    parser = argparse.ArgumentParser(description=message)

    parser.add_argument('--version' , help='BVA version', required=False,action='store_true',default=False)

    parser.add_argument('-P', '--pushStaged' , help='pushStaged activated', required=False,action='store_true', default=False)

    parser.add_argument('-n','--niter', help='Iteration number of BasinHopping', required=False, type=int, default=5);


    parser.add_argument('-m','--method', help='Local minimization procedure', required=False,  default='powell');

    parser.add_argument('--methods', help='list of applicable local minimization methods', required=False, action='store_true',  default=False);

    ## ['Powell', 'CG', 'BFGS', 'Anneal', 'L-BFGS-B', 'TNC',  'SLSQP', 'Nelder-Mead']
    parser.add_argument('--run', help='force running', required=False, action='store_true',  default=True);

    verboseInfo='0:Silent; 1:Alert; 2:Routine; 3:Debug'
    parser.add_argument ('-v', '--verbose', help=verboseInfo, action='store', required=False,type=int,default=Verbose.Routine);

    parser.add_argument ( '--stepSize', help='Step size', action='store', required=False,type=float,default=300.0);

    parser.add_argument ('-s', '--startPoint', nargs='*',help='start point', action='store',type=float,default=[0.0]);

    parser.add_argument ('-t', '--tol',help='tolerance', action='store',type=float,default=1e-10);

    ##TODO defalt value of 'success' should be the number of branch numbers
    parser.add_argument ('-N',  help='iteration times to start over', action='store', required=False,type=int,default=500,dest='startOver');


    parser.add_argument ('-S','--seed', help='random seed', action='store', type=int, required=False,default=None);

    parser.add_argument ('-i', '--inputDim', help='input dimension', action='store', required=False, default=loader.inputDim(), type=int);

    parser.add_argument ( '-a', '--abandon', help='how often you abandon hard branches', action='store', required=False, default=10, type=int);

    parser.add_argument('--rsse', dest='rsse', help="removeSingleSidedBranch enable", action='store_true')
    parser.add_argument('--no-rsse', dest='rsse', help="removeSingleSidedBranch disabled",action='store_false')
    parser.set_defaults(rsse=True)

    parser.add_argument ('-c','--objective', help='objective Coverage', action='store', required=False,type=float,default=1.0);



    args=parser.parse_args()

    if args.version:
        logo_dir=os.path.join(root_dir,'logo2.txt')
        logo = open (logo_dir,"r").read().strip('\n')
        print
        print  logo
        print
        print "BVA Deliverable D2b,  May 15 2015"
        print "Contributors: Zhoulai Fu and Zhendong Su"
        print "Copyright: University of California, Davis"
        args.run=False



    if args.methods:
        print "[BVA applicable local minimization procedure list (case-insensitive)]"
        methods=['Powell', 'CG', 'BFGS', 'Anneal' , 'L-BFGS-B', 'TNC', 'COBYLA','SLSQP','Nelder-Mead']
        print methods
        print "See more at http://docs.scipy.org/doc/scipy/reference/tutorial/optimize.html"
        args.run=False

    if len(args.startPoint)<args.inputDim:
        print "[BVA WARNING]: len(startPoint) = %s,  inputDim = %s" % (len(args.startPoint), args.inputDim)
        if len(args.startPoint)==1:
            args.startPoint=np.array(args.startPoint*args.inputDim)
            print "Your startPoint is tiled up to", args.startPoint
        else:
            print "Mismatch of len(startPoint) and inputDim"

    if not args.run: exit(0)
    if args.verbose>=Verbose.Routine: print "[BVA running]..."
    startTime=time.clock()
    kw={'method':args.method,'callback':callback_local}
    if args.seed is not None: np.random.seed(args.seed)
    sp=args.startPoint
    nfev=0
    from hypothesis.strategies import floats
    get_float = floats().example
    for i in range(args.startOver):
         if args.verbose>=Verbose.Routine:print "StartOver i =",i
         if args.verbose>=Verbose.Debug:print "startPoint =",sp
         res=op.basinhopping(foo_py,sp,callback=callback_global,minimizer_kwargs=kw,niter=args.niter,stepsize=args.stepSize,accept_test=mybounds)
         nfev+=res.nfev
         if args.verbose>=Verbose.Routine:
              print "Explored ratio so far =  ",'{percent:.2%}'.format(percent=r.exploredRatio())

         if r.exploredRatio() >= args.objective:
              if args.verbose>=Verbose.Routine: print "Stop now as the objective coverage has been reached"
              break
         if args.verbose>=Verbose.Debug:
              print "Abandonned:"
              lib.print_abandoned()
         sp=  np.array  ([get_float()]* args.inputDim)
         #sp=  np.array  ([np.random.uniform(-1e100,1e100)]* args.inputDim)
         lib.reset();
         if args.rsse:  lib.removeSingleSidedExploredBranch()
#         global i_global, i_local
#         i_global=0; i_local=0

    endTime=time.clock();
    with open(config.time_dir(),'w+') as f:
         f.write(str(endTime-startTime)); f.write('\n')
    with open(config.dimension_dir(),'w+') as f:
         f.write(str(loader.inputDim())); f.write('\n')
    if args.verbose>=Verbose.Routine: print "total nfev =", nfev
    with open(config.nfev_dir(),'w+') as f:
         f.write(str(nfev)); f.write('\n')
    with open(config.tests_dir(),'w+') as f:
         for x,_ in bv.items():
              if len(x) ==0 and args.verbose>=Verbose.Alert:
                   print ("WARING. Maybe change cov.c taking comma into account")
              for i in range(len(x)):
                   f.write (str(x[i]));f.write (',');f.write ('\n')


    if args.verbose>=Verbose.Routine:
        print "You will be using the folllowing basinhopping parameters:"
        print "[BVA config] args.niter      = ", args.niter
        print "[BVA config] args.method     = ", args.method
        print "[BVA config] args.stepSize   = ", args.stepSize
        print "[BVA config] args.startPoint = ", args.startPoint
        print "[BVA config] args.pushStaged = ", args.pushStaged
        print "[BVA config] args.startOver = ", args.startOver
        print "[BVA config] args.abandon = ", args.abandon
        print
        print "[BVA Summary]:"
        i=1
        print "%s: %-42s   %s" % ('#','x', 'f')
        print "--------------------------------------------------------------"
        for x, f in bv.items():
          print "%s: %-42s -> %s" % (i, list(x), f)
          i=i+1
        print "--------------------------------------------------------------"
        print "Explored:"
        lib.print_explored()
        

        print
        print "Total process time = ", endTime-startTime,'seconds'

        with open(config.brInfo_dir()) as f:
             nBr=(sum(1 for _ in f) *2.0 )
        try:
             c = len(r.getExplored())*1.0/ nBr

        except ZeroDivisionError:
             print 'No branches detected, considered as c=1:'
             c=1

        print "Explored ratio=  ",'{percent:.2%}'.format(percent=r.exploredRatio())

        if args.verbose>=Verbose.Debug:print res
    sys.exit(0)
