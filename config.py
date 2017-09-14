#!/usr/bin/env python
import argparse
import os
import sys
from ConfigParser import SafeConfigParser

def this_dir():
    return os.path.abspath(os.path.dirname(__file__));

def root_dir():
    root_file_dir=os.path.join(this_dir(),'root.txt')
    root_file_content = open (root_file_dir,"r").read().strip('\n')
    if  not root_file_content==this_dir():
        print "Something wrong! \nroot_file_content = %s, but this_dir() = %s" %(root_file_content, this_dir())
        sys.exit(1)
    return root_file_content

def src_dir():
    res=os.path.join(root_dir(),'src')
    if not os.path.isdir(res):
        print "Something wrong! `%s` is not a directory" % res
        sys.exit(1)
    return res

def benchs_dir():
    res=os.path.join(root_dir(),'benchs')
    if not os.path.isdir(res):
        print "Something wrong! `%s` is not a directory" % res
        sys.exit(1)
    return res


def output_dir():
    res=os.path.join(root_dir(),'output')
    if not os.path.isdir(res):
        print "Something wrong! `%s` is not a directory" % res
        sys.exit(1)
    return res




def config_dir():
    res=os.path.join(root_dir(),'config')
    if not os.path.isdir(res):
        print "Something wrong! `%s` is not a directory" % res
        sys.exit(1)
    return res


def pp_ini_dir():
    res=os.path.join(config_dir(),'pp.ini')
    if not os.path.isfile(res):
        print "Something wrong! `%s` is not a file" % res
        sys.exit(1)
    return res

def bench_name():
    theBench_txt_dir=os.path.join(root_dir(),'theBench.txt')
    if not os.path.isfile(theBench_txt_dir):
        print "Something wrong (001)! `%s` is not a directory" % res
        sys.exit(1)

    res = open (theBench_txt_dir,"r").read().strip('\n')
    return res

def bench_dir():
    res=os.path.join(benchs_dir(),bench_name())
    if not os.path.isdir(res):
        print "Something wrong (002)! `%s` is not a directory" % res
        sys.exit(1)
    return res

def loader_dir():
    res=os.path.join(root_dir(), 'build')
    if not os.path.isdir(res):
        print "Something wrong! `%s` is not a directory" % res
        sys.exit(1)
    return res

def libr_so_dir():
    res = os.path.join (root_dir(), 'build','libr.so')
    if not os.path.isfile(res):
        print "Something wrong! `%s` is not a file" % res
        sys.exit(1)
    return res


def brInfo_dir():
    res = os.path.join (output_dir(), 'brInfo.txt')
    if not os.path.isfile(res):
        print "Something wrong! `%s` is not a file" % res
        sys.exit(1)
    return res

def time_dir():
    res = os.path.join (output_dir(), 'time.txt')
    return res

def tests_dir():
    res = os.path.join (output_dir(), 'tests.txt')
    return res

def dimension_dir():
    res = os.path.join (output_dir(), 'dimension.txt')
    return res

def nfev_dir():
    res = os.path.join (output_dir(), 'nfev.txt')
    return res


if __name__ == "__main__":

    message='[BVA config setting] ... '


    print this_dir()
    print root_dir()
    print src_dir()
    print benchs_dir()
    print pp_ini_dir()
    print bench_name()
    print bench_dir()
    print loader_dir()
    print libr_so_dir()
    print "loader_dir =", loader_dir()
