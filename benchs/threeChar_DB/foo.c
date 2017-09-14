#include<stdio.h>
static const int ITERS=3;
void foo_raw ( char* program){
  /*  
  if (program[0]=='a')
      printf("Getting into w1\n");
  if (program[1]=='b')
    printf("Getting into w2\n");
  if (program[2]=='c')
      printf("Getting into w3\n");
  */

  /*  
  if (program[0]=='w'){

    if (program[1]=='w'){
          printf("  L2\n");
          if (program[2]=='w')
            printf("Getting into w3\n");
    }
  }
   if (program[0]=='a' )
    printf("PARALLE\n");
  */

  if (program[0]=='w'){
    printf("Getting into w1\n");
      if (program[1]=='w'){ 
           printf("  L2\n");
                if (program[2]=='w') 
                      printf("Getting into w3\n"); 
     } 
   } 


   if (program[0]=='a' ) 
     printf("PARALLE\n"); 


   

  
}

