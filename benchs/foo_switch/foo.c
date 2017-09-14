
#include <stdio.h>

double foo_raw(double x)
{
  char grade = (char)x+100;



  switch(grade)
    {
    case 'A' :
      printf("Excellent!\n" );
      break;
    case 'B' :
    case 'C' :
      printf("Well done\n" );
      break;
    case 'D' :
      printf("You passed\n" );
      //      break;
    case 'F' :
      printf("Better try again\n" );
      break;
    default :
      printf("Invalid grade\n" );
    }
  printf("Your grade is  %c\n", grade );
 
  
  return 0;
}

