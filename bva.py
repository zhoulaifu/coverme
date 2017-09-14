#!/usr/bin/env python
import argparse
import ConfigParser
import sys
import subprocess


defaultMessage='[BVA] config and run ... '
parser = argparse.ArgumentParser(description=defaultMessage)
   
parser.add_argument('-v','--version' , help='print BVA version', required=False,action='store_true',default=False)
   
parser.add_argument('-r','--run', help='run src/mcmc.py', required=False, \
                       action="store_true", default=False);

parser.add_argument('-n','--niter', help='specify niter in scipy.optimize.basinhopping', required=False, \
                       type=int, default=False);
 
   
parser.add_argument ('--verbose', help='output the parsed options', required=False,action='store_true',default=False);

if len(sys.argv)==1:
    parser.print_help()
    sys.exit(1)

results = parser.parse_args()

   
if results.run:
   if results.niter==0:
      subprocess.call(['./src/mcmc.py'])
      sys.exit(0)
   else if results.niter>0:
##DB   
      subprocess.call(['./src/mcmc.py',niter])
      sys.exit(0)
   else:
      sys.exit(1)
   
if results.version:
   print "BVA version: v_D2a"

      
if results.verbose:
   print "results.run     =", results.run
   print "results.version =", results.version 
   

   
