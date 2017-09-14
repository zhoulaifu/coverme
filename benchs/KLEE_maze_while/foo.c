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
  char a = program[0];
  /*
  if (a<=10){
      printf("IF\n");
      a++;
      if (a==5){
        printf("IN\n");
      }
  }
  */
  
  while (a<=10){
    printf("LOOP\n");
    a++;
    if (a==5){
      printf("IN a==5!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
    }
  }
  printf("   OUT\n");
  

  
}

