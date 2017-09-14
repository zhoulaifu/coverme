#define DEBUG_TYPE "hello"


#include "llvm/ADT/Statistic.h"
#include "llvm/IR/Function.h"
#include "llvm/Pass.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/InstIterator.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/Support/Debug.h"

#include "iostream"
#include "config.h"
#include  <fstream>
#include <string>
#include "llvm/Support/CommandLine.h"

using namespace llvm;


#ifndef FUNCNAME
 #define FUNCNAME foo_raw
#endif
long int config::helloCounter=0;

cl::opt<std::string> funcname("funcname", cl::desc("Specify function name"), cl::value_desc("funcname"));


struct Hello2: public ModulePass {
     static char ID; 
     Hello2() :
          ModulePass ( ID ) {
     }

     virtual bool runOnModule ( Module &M ) {
          ++config::helloCounter;

          Function* func;

          int brCount=0;
          
          std::ofstream myfile;
          myfile.open("output/brInfo.txt",          std::ofstream::out | std::ofstream::trunc);
               
          for ( Module::iterator I = M.begin(), E = M.end(); I != E; ++I ) {
               func = &*I;
               if (func->getName().equals(funcname.c_str()))
                    func->setName("foo_i");
               else
                    continue;
                    
                    
               for ( Function::iterator bbi = func->begin(), bbe = func->end(); bbi != bbe; ++bbi ) {
                    
                    BasicBlock* bb=&*bbi;
                    for ( BasicBlock::iterator I = bb->begin(),ie=bb->end(); I!=ie; ++I ) {

                         Instruction* inst= &*I;
                         
   
                         if ( isa<IndirectBrInst> ( inst ) ) {
                              errs() <<"***************WARNING. Maybe I should have considered IndirectBrInst: " <<*inst <<"\n";
                              continue;
                         }
                         if ( isa<SwitchInst> ( inst ) ) {
                              errs() <<"***************WARNING. Maybe I should have considered SwitchInst: " <<*inst <<"\n";
                              continue;
                         }

                         
                         CmpInst * cmpInst;
 

                         if (isa<BranchInst>(inst)){
                              BranchInst *BI=cast<BranchInst> ( inst );

                              if ( ! BI->isConditional() ) continue;

                              brCount++; //recording BranchInst that are conditional
//orignlal
                              cmpInst=cast<CmpInst> ( BI->getCondition() );

                               
                         }
                         else if (isa<SelectInst>(inst)){
                              SelectInst *SI=cast<SelectInst> ( inst );
                              cmpInst=cast<CmpInst> ( SI->getCondition());
                         }
                         else{
                              
                              continue;
                         }
                         
                         if ( !cmpInst ) {
                              errs() <<" I do not expect dealing with other form of comparison other than ICmpInst and FCmpInst" <<"\n";
                              continue;

                         }

                         Value* LHS=cmpInst->getOperand ( 0 );
                         Value* RHS=cmpInst->getOperand ( 1 );
                         std::vector<Value*> call_params;
                         IRBuilder<> builder ( inst );
                         if(isa<ICmpInst> (cmpInst)){

                              LHS=builder.CreateSIToFP(LHS,Type::getDoubleTy(M.getContext()),"__LHS");
                              RHS=builder.CreateSIToFP(RHS,Type::getDoubleTy(M.getContext()),"__RHS");
                         }      
                         
                         
                         
                         call_params.push_back ( LHS );
                         call_params.push_back ( RHS );
                         //stopHERE
                         //uint64_t x=42;
                         uint64_t initID = reinterpret_cast<uint64_t>(cmpInst);

                         int cmpID=cmpInst->getPredicate();
                         int isInt=isa<ICmpInst> (cmpInst);
                         std::string str;
                         llvm::raw_string_ostream rso(str);
                         inst->print(rso);
                         myfile<<initID<<"\t"<<cmpID<<"\t"<<isInt<<"\t"<< str<<"\n";
                         ConstantInt* const_int32_6 = ConstantInt::get(M.getContext(), APInt(64, initID,false)); 
                         ConstantInt* const_int32_7 = ConstantInt::get(M.getContext(), APInt(64, cmpID,false)); 
                         ConstantInt* const_int32_8 = ConstantInt::get(M.getContext(), APInt(64, isInt,false)); 
                         call_params.push_back(const_int32_6);  //instID
                         call_params.push_back(const_int32_7);  //instID
                         call_params.push_back(const_int32_8);  //instID
                         
                              std::vector<Type*>FuncTy_3_args;
                              FuncTy_3_args.push_back ( Type::getDoubleTy ( M.getContext() ) );
                              FuncTy_3_args.push_back ( Type::getDoubleTy ( M.getContext() ) );

                              FuncTy_3_args.push_back(Type::getInt64Ty(M.getContext()));
                              FuncTy_3_args.push_back(Type::getInt64Ty(M.getContext()));
                              FuncTy_3_args.push_back(Type::getInt64Ty(M.getContext()));
                              
                              FunctionType* FuncTy_3 = FunctionType::get (
                                                            /*Result=*/Type::getVoidTy ( M.getContext() ),
                                                            /*Params=*/FuncTy_3_args,
                                                            /*isVarArg=*/false );
                              Function* func___pen = M.getFunction ( "__pen" );
                              if ( !func___pen ) {
                                   func___pen = Function::Create (
                                                     /*Type=*/FuncTy_3,
                                                     /*Linkage=*/GlobalValue::ExternalLinkage,
                                                     /*Name=*/"__pen", &M ); 
                                   func___pen->setCallingConv ( CallingConv::C );
                              }
                              builder.CreateCall ( func___pen, call_params, "" );
                               //                             /*Result=*/Type::getVoidTy ( M.getContext() ),
                               //                             /*Params=*/FuncTy_3_args,
                               //                             /*isVarArg=*/false );
                              //Function* func___pen_int64 = M.getFunction ( "__pen_int64" );
                              //if ( !func___pen_int64 ) {
                              //     func___pen_int64 = Function::Create (
                              //                             /*Type=*/FuncTy_3,
                              //                             /*Linkage=*/GlobalValue::ExternalLinkage,
                              //                             /*Name=*/"__pen_int64", &M ); // (external, no body)
                              //     func___pen_int64->setCallingConv ( CallingConv::C );
                             // }
                             // builder.CreateCall ( func___pen_int64, call_params, "" );


//                         }
                         DEBUG ( errs() <<"++++++++step1+++++++\n"<<M<<"\n" );

//               builder.CreateStore(here, gvar_double___r, false);
                         /*
                                        CallInst* double_call = CallInst::Create(func___pen, double_call_params, "call", bb);
                                        double_call->setCallingConv(CallingConv::C);
                                        double_call->setTailCall(false);
                                        AttributeSet double_call_PAL;
                                        double_call->setAttributes(double_call_PAL);
                         */  //
                         //uncomment this if I want to see the results
                         DEBUG ( errs() <<"+++++step2++++++++++\n"<<M<<"\n" );

                    }
               }//end the two for
          }
          myfile.close();
          return false;

     };//end runonmodule


};//end struct

char Hello2::ID = 0;
static RegisterPass<Hello2> Y ( "hello2",
                                "Hello World Pass (with getAnalysisUsage implemented)" );

