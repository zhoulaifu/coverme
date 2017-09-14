//===- Hello.cpp - Example code from "Writing an LLVM Pass" ---------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file implements two versions of the LLVM "Hello World" pass described
// in docs/WritingAnLLVMPass.html
//
//===----------------------------------------------------------------------===//

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
using namespace llvm;

//STATISTIC ( HelloCounter, "Counts number of functions greeted" );
/*
  namespace {
  // Hello - The first implementation, without getAnalysisUsage.
  struct Hello: public FunctionPass {
  static char ID; // Pass identification, replacement for typeid
  Hello() :
  FunctionPass(ID) {
  }

  virtual bool runOnFunction(Function &F) {
  ++HelloCounter;
  errs() << "Hello: ";
  errs().write_escaped(F.getName()) << '\n';
  return false;
  }
  };
  }

  char Hello::ID = 0;
  static RegisterPass<Hello> X("hello", "Hello World Pass");
*/
////////////////////////////
//namespace {
// Hello2 - The second implementation with getAnalysisUsage implemented.
struct Hello2: public ModulePass {
     static char ID; // Pass identification, replacement for typeid
     Hello2() :
          ModulePass ( ID ) {
     }

     virtual bool runOnModule ( Module &M ) {

   //       ++HelloCounter;
//          int index_atMostOne = 0;
          Function* func;
          //TODO 'foo' has to be a parameter
       /*
          func=M.getFunction("foo");

          
          if (! func){
               throw "Function foo not found!! If you use C++, then function name has to be demangled first.\n";
          }
*/
          //<<step one, retrieve Function*
        //  for ( Module::iterator I = M.begin(), E = M.end(); I != E; ++I ) {
   //            func = &*I;
         //      index_atMostOne++;
         // }
          //if ( index_atMostOne > 1 ) {
            //   errs() << "WARNING: Assumption failed: index_atMostOne = "
              //        << index_atMostOne<<"\n";
         //      throw "Assumption Failed ";
 //         }
//          errs() << func->getName() << "\n";

          // >>step one: F is a pointer to a Function instance


          //step two: add the global var.
//DB0426 It seems GlobalVar __r is not necessary.
//          GlobalVariable* gvar_double___r = new GlobalVariable ( /*Module=*/ M,
//                   /*Type=*/Type::getDoubleTy ( M.getContext() ),
//                   /*isConstant=*/false,
          //                  /*Linkage=*/GlobalValue::ExternalLinkage,
          //                 /*Initializer=*/0,
          //                /*Name=*/"__r" );


          // step 3 Function Definition: Type Definitions
          std::vector<Type*>FuncTy_3_args;
          FuncTy_3_args.push_back ( Type::getDoubleTy ( M.getContext() ) );
          FuncTy_3_args.push_back ( Type::getDoubleTy ( M.getContext() ) );
          FunctionType* FuncTy_3 = FunctionType::get (
                                        /*Result=*/Type::getVoidTy ( M.getContext() ),
                                        /*Params=*/FuncTy_3_args,
                                        /*isVarArg=*/false );

          //step 3bis Function Definition: Function Definitions

          Function* func___pen = M.getFunction ( "__pen" );
          if ( !func___pen ) {
               func___pen = Function::Create (
                                 /*Type=*/FuncTy_3,
                                 /*Linkage=*/GlobalValue::ExternalLinkage,
                                 /*Name=*/"__pen", &M ); // (external, no body)
               func___pen->setCallingConv ( CallingConv::C );
          }


          AttributeSet func___pen_PAL;
          {
               SmallVector<AttributeSet, 4> Attrs;
               AttributeSet PAS;
               {
                    AttrBuilder B;
                    PAS = AttributeSet::get ( M.getContext(), ~0U, B );
               }

               Attrs.push_back ( PAS );
               func___pen_PAL = AttributeSet::get ( M.getContext(), Attrs );

          }
          func___pen->setAttributes ( func___pen_PAL );

          //DB step two:

          int brCount=0;

          for ( Module::iterator I = M.begin(), E = M.end(); I != E; ++I ) {
                      func = &*I;
          //      index_atMostOne++;
          // }
          for ( Function::iterator bbi = func->begin(), bbe = func->end(); bbi != bbe; ++bbi ) {
               BasicBlock* bb=&*bbi;
               for ( BasicBlock::iterator I = bb->begin(),ie=bb->end(); I!=ie; ++I ) {
//          for ( inst_iterator I = inst_begin ( func ), E = inst_end ( func ); I != E; ++I ) {
                    Instruction* inst= &*I;

                    if (isa<SelectInst>(inst)){
                         errs()<<"***************WARNING. Maybe I should have considered SelectInst: " <<*inst <<"\n";
                         continue;
                    }
                    if (isa<IndirectBrInst>(inst)){
                         errs()<<"***************WARNING. Maybe I should have considered IndirectBrInst: " <<*inst <<"\n";
                         continue;
                    }
                    if (isa<SwitchInst>(inst)){
                         errs()<<"***************WARNING. Maybe I should have considered SwitchInst: " <<*inst <<"\n";
                         continue;
                    }
                    
                    if ( !isa<BranchInst> ( inst ) ) {
//		errs()<<"Untreated Instruction"<<*inst;
                         continue;
                    }
                    //Now we assume inst points to a BranchInst
                    BranchInst *BI=cast<BranchInst> ( inst );
                    //exclude the case where BI is a direct jump
                    if ( ! BI->isConditional() ) continue;
                    //now we assume inst is a conditional BranchInst
                    brCount++; //recording BranchInst that are conditional

                    if ( isa<ICmpInst> ( BI ) ) {
                         errs() <<"I don't deal with ICmpInst, yet"<<"\n";
                    }
                    //now assume that BI's condition  does not point to an ICmpInst. I assume it necessarily points to a FCmpInst.
                    FCmpInst *fCmpInst = cast<FCmpInst> ( BI->getOperand ( 0 ) );
                    /*
                    errs() << "["<<brCount<<"] = "<< *I << "\n";
                    for ( unsigned int i = 0; i < fCmpInst->getNumOperands(); i++ ) {
                         errs() << * fCmpInst-> getOperand ( i ) <<"\n";
                    }
                    */


                    Value* LHS= fCmpInst->getOperand ( 0 );
                    Value* RHS=fCmpInst->getOperand ( 1 );
                    std::vector<Value*> double_call_params;
                    double_call_params.push_back ( LHS );
                    double_call_params.push_back ( RHS );
                    IRBuilder<> builder ( inst );
                    builder.CreateCall ( func___pen, double_call_params, "" );
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
                   DEBUG  ( errs() <<"+++++step2++++++++++\n"<<M<<"\n" );

               }
          }//end the two for
          }
          return false;

     };//end runonmodule

     // We don't modify the program, so we preserve all analyses
     /*
           virtual void getAnalysisUsage(AnalysisUsage &AU) const {

     	AU.setPreservesAll();
           }
     */
//    };

};//end struct

char Hello2::ID = 0;
static RegisterPass<Hello2> Y ( "hello2",
                                "Hello World Pass (with getAnalysisUsage implemented)" );

