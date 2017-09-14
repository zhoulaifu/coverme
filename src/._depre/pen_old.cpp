#include <set>
#include "config.h"
#include "math.h"
#include <utility>
#include <assert.h>
#include <map>

static std::set<uint64_t> coveredInstIDs={}; //cover means boundary reached
static std::set<uint64_t> stagedInstIDs={}; //staged

extern long int __d;
extern double __r;
extern std::pair<int,int> lastBr;
static inline double distance(double x,double y);
extern std::set<std::pair<int,int>> explored;
extern std::set<std::pair<int,int>> passed_for_one_sample;
extern "C" void print_explored();
std::set<std::pair<int,int>> abandoned;
extern std::map<std::pair<int,int>,int> passStaged;

extern "C" void print_abandoned(){
  int ii=0;
  for(std::set<std::pair<int,int>>::iterator iter=abandoned.begin(); iter!=abandoned.end();++iter){
    std::cout << (ii==0?"":", ")<<ii<<":"<<"("<<iter->first<<","<<iter->second<<")" ;
    ii++;
  }
  std::cout<<std::endl;

}
/*
  enum  	Predicate {
  FCMP_FALSE = 0, FCMP_OEQ = 1, FCMP_OGT = 2, FCMP_OGE = 3,
  FCMP_OLT = 4, FCMP_OLE = 5, FCMP_ONE = 6, FCMP_ORD = 7,
  FCMP_UNO = 8, FCMP_UEQ = 9, FCMP_UGT = 10, FCMP_UGE = 11,
  FCMP_ULT = 12, FCMP_ULE = 13, FCMP_UNE = 14, FCMP_TRUE = 15,
  FIRST_FCMP_PREDICATE = FCMP_FALSE, LAST_FCMP_PREDICATE = FCMP_TRUE, BAD_FCMP_PREDICATE = FCMP_TRUE + 1, ICMP_EQ = 32,
  ICMP_NE = 33, ICMP_UGT = 34, ICMP_UGE = 35, ICMP_ULT = 36,
  ICMP_ULE = 37, ICMP_SGT = 38, ICMP_SGE = 39, ICMP_SLT = 40,
  ICMP_SLE = 41, FIRST_ICMP_PREDICATE = ICMP_EQ, LAST_ICMP_PREDICATE = ICMP_SLE, BAD_ICMP_PREDICATE = ICMP_SLE + 1
  }
*/
static bool getTruth(double x,double y, int cmpID){
  //http://llvm.org/docs/doxygen/html/classllvm_1_1CmpInst.html    
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
  
  
  else{
    std::cerr  <<"\nWARNING !!!!!!!!!!!!!"<<"    cmpID = " << cmpID <<" not handled!\n\n";
  }
  
  return truth;
}
int i_pen=0;
static void inline penalty_branchCoverage(double x,double y, uint64_t instID,int cmpID, int isInt){
  double __r_previous=__r;
  std::pair<int,int> br1,br2;

  
  br1=std::make_pair<int,int>(instID,getTruth(x,y,cmpID));
  br2=std::make_pair<int,int>(instID,not getTruth(x,y,cmpID));


  bool thisExplored=explored.count(br1)>0
    || (passed_for_one_sample.count(br1)>0 ||
        passed_for_one_sample.count(br2)>0 );
  bool thatExplored=explored.count(br2)>0
    || (passed_for_one_sample.count(br1)>0 ||
        passed_for_one_sample.count(br2)>0 );

  assert(br1.second>=0 and br1.first>=0);
  passed_for_one_sample.insert(br1);
  //     if lastBr is not None:
  //     if thisExplored and thatExplored:
  //         explored.add(lastBr)
                        
  if (lastBr.second>0 && lastBr.second >0){
    if (thisExplored && thatExplored)
      explored.insert(lastBr);
  }                          

          
  int choice = -1;
  if (not thisExplored){
    choice=0;
    __r=0;
  }
  else if (thatExplored){ //I don t want to go to the other branch
    choice = 1;
    //early quite
    return;
    //    __r = __r;
  }
  else{ //I would like to go there with guidance
    choice=2;
    __r = distance(x,y);
  }

  assert(not hasNone());

    
  DB("\t"<<i_pen<<": "<<"with instID = "<<instID <<"\n"<<
     "\t |" << "__r (previous) = "<<__r_previous << "\n"<<
     "\t |" << "x, y  = "<< x <<","<< y<< "\n"<<
     "\t |" << "lastBr = ("<< lastBr.first<< ","<<lastBr.second<<")"<<"\n"<<
     "\t |" << "br1 = ("<< br1.first<< ","<<br1.second<<")"<<"\n"<<
     "\t |" << "br2 = ("<< br2.first<< ","<<br2.second<<")"<<"\n"<<
     "\t |" << "cmpID = "<<cmpID << "\n"<<
     "\t |" << "cmpType =" << (isInt?"Integer":"Floating Point") <<"\n" <<
     "\t |" << "choice = "<<choice<<"\n"<<
     "\t |" << "__r =" << __r<<"\n"
     );
#ifdef DEBUG
  print_explored();
#endif
  
  i_pen++;


  lastBr=std::make_pair(instID,getTruth(x,y,cmpID));

  passStaged[br1]+=1;
}

extern "C"
void __pen ( double x, double y , uint64_t instID,int cmpID, int isInt){
  //  penalty_min(x,y,instID);
  //    penalty_multiply(x,y,instID);
  penalty_branchCoverage(x,y,instID,cmpID,isInt);
}



//call at callBack time, do it before removeSingleSidedExploredBranch
extern "C" void addHardBranchAsExplored(){
  assert(not hasNone());
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
  if (explored.count(lastBr2)==0){
    assert(lastBr2.first>=0 and lastBr2.second>=0);
    explored_afterAdd.insert(lastBr2);
    abandoned.insert(lastBr2);
    DB("**Abandonned: Branch that are added to explored: "
       << " ("<< instID<< ","<<1-truth<<")"<<" \n");
  }
  explored=explored_afterAdd;
  assert(not hasNone());
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

