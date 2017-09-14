#include <limits>
#include <sstream>
#include <iostream>
#include "config.h"
#include <utility>
#include <set>
#include <map>


double __r;
double __d;
std::pair<int,int> lastBr;
std::set<std::pair<int,int>> passed_for_one_sample;
std::set<std::pair<int,int>> explored;
std::map<std::pair<int,int>,int> passStaged;
std::map<std::pair<int,int>,int> nPass;
std::set<std::pair<int,int>> abandoned;

extern "C" void print_passStaged(){
  for ( auto& b2i: passStaged){
    auto br = b2i.first;
    int n  = b2i.second;
    std::cout<<br.first<<","<<br.second<<"->"<<n<<std::endl;
  }
}
extern "C" void print_nPass(){
  for ( auto& b2i: nPass){
    auto br = b2i.first;
    int n  = b2i.second;
    std::cout<<br.first<<","<<br.second<<"->"<<n<<std::endl;
  }
}
extern "C" void print_pass_for_one_sample(){
  for ( auto& br: passed_for_one_sample){
    std::cout<<br.first<<","<<br.second<<std::endl;
  }
}



void foo(double*);
static std::string toString(double* array,long int n);

extern "C" int lastBr_id(){
  return lastBr.first;
}
extern "C" int lastBr_truth(){
  return lastBr.second;
}
extern "C" void print_explored(){
  int ii=0;
  for(std::set<std::pair<int,int>>::iterator iter=explored.begin(); iter!=explored.end();++iter){
    std::cout << (ii==0?"":", ")<<ii<<":"<<"("<<iter->first<<","<<iter->second<<")" ;
    ii++;
  }
  std::cout<<std::endl;

}
extern "C" void print_passed_for_one_sample(){
  int ii=0;
  for(std::set<std::pair<int,int>>::iterator iter=passed_for_one_sample.begin(); iter!=passed_for_one_sample.end();++iter){
    std::cout << (ii==0?"":", ")<<ii<<":"<<"("<<iter->first<<","<<iter->second<<")" ;
    ii++;
 }

}

extern "C" int nExplored(){
  return explored.size();
}
extern "C" int nCovered(){
  return nPass.size();
}

extern "C" int* explored_part1(){
  int* res=new int[explored.size()];
  int ii=0;
  for(std::set<std::pair<int,int>>::iterator iter=explored.begin(); iter!=explored.end();++iter){
    res[ii]=iter->first;
    ii++;
  }
  return res;
}
extern "C" int* explored_part2(){
  int* res=new int[explored.size()];
  int ii=0;
  for(std::set<std::pair<int,int>>::iterator iter=explored.begin(); iter!=explored.end();++iter){
    res[ii]=iter->second;
    ii++;
  }
  return res;
}



static int i_foo_r=0;
extern "C" double foo_r ( double* x ){
  passed_for_one_sample.clear();

  lastBr=std::make_pair(-1,-1);

  DB( i_foo_r<<": x = "<<x[0]<<","<<x[1]);
  i_foo_r++;

  __d=0L;

  __r= config::INIT__r;

  if (config::REDIRECT) freopen ( "/tmp/newstdout", "w", stdout );
  foo ( x );
  if (config::REDIRECT) freopen ( "/dev/tty","w",stdout );




  if (not(lastBr.first==-1 or lastBr.second==-1))
    explored.insert(lastBr);



  for (auto & b2i : passed_for_one_sample){

    passStaged[b2i]++;
  }


  return __r;
}

//tricky. Seems working for powell, but not necessarily on the others.
//Do this at local or global callback time.
extern "C" void removeSingleSidedExploredBranch(){
  std::set<std::pair<int,int>> explored_afterRemoval;
  for (auto br: explored){
    int instID = br.first;
    int truth =br.second;

    //std::pair<int,int> br2{instID, 1-truth};
    std::pair<int,int> br2 = std::make_pair(instID, 1-truth);

    if (explored.count(br2)>0)
      explored_afterRemoval.insert(br);
    else
      DB("**Tricky: Branch that is not added to explored_afterRemoval: "
         << " ("<< instID<< ","<<truth<<")"<<" \n");

  }

  explored=explored_afterRemoval;

}

extern "C" void pushStaged(){
  for (auto b2i:passStaged){
    auto br = b2i.first;
    int n  = b2i.second;
    nPass[br]+=n;
}
  passStaged.clear();
}
extern "C" void reset(){

 lastBr=std::make_pair(-1,-1);
 passed_for_one_sample.clear();
 // explored.clear();
 // removeSingleSidedExploredBranch();
 passStaged.clear();
 nPass.clear();
 abandoned.clear();


}
