import os
import sys
import unittest
import mcmc
import numpy as np
import ctypes
from ctypes import cdll


root_dir = os.path.split(os.path.abspath(os.path.dirname(__file__)))[0]
sys.path.append(root_dir)
import config



class mcmc_test(unittest.TestCase):
    def c2f(self,c):
        return float(ord(c))

    def setUp(self):
#        self.bench_name = config.bench_name()
#        lib=cdll.LoadLibrary(config.libr_so_dir())
#        self.foo_r=lib.foo_r
        pass

    def _test_KLEE_maze_while(self):
        lib=cdll.LoadLibrary(config.libr_so_dir())
        self.assertEqual(self.bench_name,"KLEE_maze_while")
        x=np.array([self.c2f('a'),self.c2f('b'),self.c2f('w')])
        self.assertEqual(mcmc.foo_py(x),0)

        with open(config.brInfo_dir()) as f:
            lines = f.read().splitlines()
        self.assertEqual(lib.nExplored(),1);
        repf=mcmc.repf()

        self.assertEqual(len(repf.getExplored()),1);
#        self.assertEqual(repf['explored'].pop()[1],True);

        x2=np.array([self.c2f('a'),self.c2f('b'),self.c2f('a')])
        self.assertEqual(mcmc.foo_py(x2),0)
        lib.print_explored()
        self.assertEqual(repf['nExplored'](),2)
        self.assertEqual(len(repf.getExplored()),2)
        self.assertEqual(repf.get_nExplored(),2)

        x3=np.array([self.c2f('a'),self.c2f('b'),self.c2f('u')])
        self.assertEqual(mcmc.foo_py(x3),0)

        self.assertEqual(repf.get_nExplored(),3)
        print repf.getExplored()

        self.assertEqual(mcmc.foo_py(x3),ord('w')-ord('b'))

        x4=np.array([self.c2f('a'),self.c2f('w'),self.c2f('u')])
        self.assertEqual(mcmc.foo_py(x4),0)
        self.assertEqual(repf.get_nExplored(),4)
        print repf.getExplored()



        self.assertEqual(mcmc.foo_py(x4),0)
        self.assertEqual(mcmc.foo_py(x4),ord('w')-ord('a'))
        self.assertEqual(len(repf.getExplored()),5)

        ############something wrong below

        x5=np.array([self.c2f('w'),self.c2f('w'),self.c2f('u')])
        self.assertEqual(mcmc.foo_py(x5),0)
        self.assertEqual(len(repf.getExplored()),6)

    def _test_s_sin(self):
        lib=cdll.LoadLibrary(config.libr_so_dir())
        self.assertEqual(config.bench_name(),"fdlibm53")
        print "000000000000000"
        x=np.array([1.0])
        mcmc.foo_py(x)
        self.assertTrue(mcmc.r.get_nExplored(),1)
        print mcmc.r.getExplored()
        print "1111111111111"
        mcmc.foo_py(np.array([np.inf]))
        self.assertTrue(mcmc.r.get_nExplored(),2)
        print mcmc.r.getExplored()

    def _test_write(self):
        endTime=100
        startTime=0.1
        x=[2,3]

        root_dir = os.path.split(os.path.abspath(os.path.dirname(__file__)))[0]
        sys.path.append(root_dir)
        import config

        print "process time = ", endTime-startTime,'seconds'
        with open(config.runningTime_dir(),'w') as f:
             f.write(str(endTime-startTime))
             f.write('\n')

    def test_passStaged(self):
        print "1:"
        lib=cdll.LoadLibrary(config.libr_so_dir())
        lib.print_passStaged()
        print "TODO: Check empty"

        print "2:"
        x=np.array([self.c2f('a'),self.c2f('b'),self.c2f('w')])
        mcmc.foo_py(x)
        #lib.print_passStaged()
        print "TODO: Check 2 elements"

        print "3:"
        x2=np.array([self.c2f('w'),self.c2f('w'),self.c2f('y')])
        mcmc.foo_py(x2)
        lib.print_passStaged()
        print "TODO: Check 6 elements"

        print "4:"
        lib.pushStaged()
        lib.print_nPass()
        print "TODO: Check 6 elements"
        print "5:"
        lib.print_passStaged()
        print "TODO Check empty"
        print "6:"
        mcmc.foo_py(x2)
        lib.print_passStaged()
        print "TODO Check 4 elements above "
        lib.print_nPass()
        print "TODO Check 6 elements above (value sum=6)"
        lib.print_passed_for_one_sample()
        print "TODO Check 4 elements above"
        lib.pushStaged()
        print "TODO Check 10 elements above"
        lib.print_passStaged()
        print "TODO Check empty"
        lib.print_nPass()
        print "6 elements, value sum = 10"

if __name__=="__main__":
    unittest.main()
