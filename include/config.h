#ifndef CONFIG_H
#define CONFIG_H
#include <iostream>

#ifdef DEBUG
#define DB(  var ) \
  std::cerr<< var <<"\t(" << __FILE__  <<" "<< __func__<<":"<<__LINE__  << ")"<<std::endl
  //    std::cerr<< "ENTERING" << __FILE__ << " (" << __func__<<":"<<__LINE__ << ") \n"<<  var  << std::endl


#else
#define DB(var)
#endif



namespace config{
  /*
  enum INPUT_KIND { TyInt,TyDouble } ;
  INPUT_KIND TyInput=TyDouble;
  */
  const bool REDIRECT=false;

  //STOPHERE. Also look at ATGMO  for the modif, main part is ok.
  extern long int helloCounter;

  const double TOL=1e-12;
  const double TOL_PUSHSTAGED=1e-40;

  //for penalty_min
  //const double INIT__r=1e7;


  const double INIT__r=1;

}


#endif
