#include "config.h"
#include <cmath>
#include <utility>
#include <assert.h>
#include <map>
#include <set>

static std::set<uint64_t> coveredInstIDs={}; //cover means boundary reached
static std::set<uint64_t> stagedInstIDs={}; //staged


extern long int __d;
extern double __r;
extern std::pair<int,int> lastBr;
static inline double distance(double x,double y);
extern std::set<std::pair<int,int>> explored;
extern std::set<std::pair<int,int>> passed_for_one_sample;
extern "C" void print_explored();
extern std::set<std::pair<int,int>> abandoned;
extern std::map<std::pair<int,int>,int> passStaged;
extern std::map<std::pair<int,int>,int> nPass;
extern "C" void print_passed_for_one_sample();
std::ostream& operator<< (std::ostream& os, std::pair<int,int> br){
  os<<"("<<br.first<<","<<br.second<<")";
  return os;
}

extern "C" void print_abandoned(){
  int ii=0;
  for(std::set<std::pair<int,int>>::iterator iter=abandoned.begin(); iter!=abandoned.end();++iter){
    std::cout << (ii==0?"":", ")<<ii<<":"<<"("<<iter->first<<","<<iter->second<<")" ;
    ii++;
  }
  std::cout<<std::endl;

}

static bool getTruth(double x,double y, int cmpID){

  bool truth=false;
  if (cmpID==32 || cmpID==1)
    truth=x==y;
  else if (cmpID==41 ||cmpID==5 || cmpID == 37)
    truth=x<=y;
  else if (cmpID==39 || cmpID==3 || cmpID==35)
    truth=x>=y;
  else if (cmpID==40 || cmpID==36 || cmpID==4)
    truth=x<y;
  else if (cmpID==2 || cmpID==38 ||cmpID==34)
    truth=x>y;
  else if (cmpID==33)
    truth = x!=y;

  else
    std::cerr  <<"\nWARNING !!!!!!!!!!!!!"<<"    cmpID = " << cmpID <<" not handled!\n\n";

  return truth;
}

static bool branchIsNone(std::pair<int,int> br){
  return br.first<0 || br.second<0;
}
static double inline amplifier_0630(double x){

  if (std::isinf(x)) std::cerr<<"Warning!!"<<"x is infinite\n";
  return 42*std::pow(x,4)+1;
}
int i_pen=0;
static void inline penalty_branchCoverage(double x,double y, uint64_t instID,int cmpID, int isInt){
  double __r_previous=__r;
  std::pair<int,int> br,br2;

  br=std::make_pair<int,int>(instID,getTruth(x,y,cmpID));
  br2=std::make_pair<int,int>(instID,not getTruth(x,y,cmpID));

  bool thisExplored=explored.count(br)>0
    || (passed_for_one_sample.count(br)>0 ||
        passed_for_one_sample.count(br2)>0 );
  bool thatExplored=explored.count(br2)>0
    || (passed_for_one_sample.count(br)>0 ||
        passed_for_one_sample.count(br2)>0 );

  if (thisExplored && thatExplored){
    DB ("quite early beause both children of instID = "<<instID<< " are explored");
    return;
  }
  double fn = amplifier_0630(nPass[br]);

  int choice;

  if (not thisExplored){
    choice=0;
    __r=0;
  }
  // if (not thisExplored){
  //   choice=0;
  //   __r=0;
  // }
  // else if (thatExplored){ //I don t want to go to the other branch
  //   choice = 1;
  //   //early quite
  //   return;
  //   //    __r = __r;
  // }
  // else{ //I would like to go there with guidance
  //   choice=2;
  //   __r = distance(x,y);
  // }


  else if (thatExplored){ //I don t want to go to the other branch
    assert (not thisExplored);
    choice = 1;
    __r=__r; //do nothing
  }
  else{ //I would like to go there with guidance
    choice=2;
    __r = distance(x,y) * fn;
  }




  DB("\t"<<i_pen<<": "<<"with instID = "<<instID <<"\n"<<
     "\t |" << "fn = "<<fn << "\n"<<
     "\t |" << "lhs, rhs, dist(lhs,rhs)  = "<< x <<","<< y<<","<< distance(x,y)<<"\n"<<
     "\t |" << "br,br2 <-lastBr : "<<br<<","<< br2<< " <- " <<lastBr<<"\n"<<
     "\t |" << "cmpID = "<<cmpID << "\n"<<
     "\t |" << "choice = "<<choice<<"\n"<<
     "\t |" << "__r =" << __r<<"\n"
     );
#ifdef DEBUG
  print_explored();
#endif
  i_pen++;

  lastBr=br;

  assert(br.second>=0 and br.first>=0);
  passed_for_one_sample.insert(br);
}

extern "C"
void __pen ( double x, double y , uint64_t instID,int cmpID, int isInt){
  //  penalty_min(x,y,instID);
  //    penalty_multiply(x,y,instID);
  penalty_branchCoverage(x,y,instID,cmpID,isInt);
}


//call at callBack time, do it before removeSingleSidedExploredBranch
extern "C" void addHardBranchAsExplored(){

  int instID=lastBr.first;
  int truth = lastBr.second;
  //in the case where lastBr=None (ie -1,-1 here), do not add it
  //This is possible because we are now alomost real-mao.
  if (instID==-1){return;}
  assert(lastBr.first>=0 and lastBr.second>=0);
  std::pair<int,int> lastBr2 = std::make_pair(instID, 1-truth);
  DB("**Abandonned: Branch that are the candidate to addHardBranchExplored..: "
     << " ("<< instID<< ","<<1-truth<<")"<<" \n");
  std::set<std::pair<int,int>> explored_afterAdd(explored);
// std::cout<<"***lastBr2="<<lastBr2<<" nPass ="<<nPass[lastBr2] <<", explored.count="<<explored.count(lastBr2)<<std::endl;
//  if (nPass[lastBr2]==0){
         if (explored.count(lastBr2)==0){
    assert(lastBr2.first>=0 and lastBr2.second>=0);
    explored_afterAdd.insert(lastBr2);
    abandoned.insert(lastBr2);
    DB("**Abandonned: Branch that are added to explored: "
       << " ("<< instID<< ","<<1-truth<<")"<<" \n");
  }
  explored=explored_afterAdd;

}


static inline double distance(double x,double y){
  //return (x-y)*(x-y);
  return (x>=y)? x-y : y-x;
  /*
    if (x-y==0) return 0;
    double x_=x>0?x:-x;
    double y_=y>0?y:-y;
    double bigger=(x_<=y_)? y_:x_;
    DB("x,y,dist" << x<<","<<y<<","<<(x-y)*(x-y)/(bigger*bigger));
    return (x-y)*(x-y) / (bigger*bigger);
  */
}

