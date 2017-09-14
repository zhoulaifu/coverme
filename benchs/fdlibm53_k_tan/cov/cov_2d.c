#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

double foo_raw (double,double, int);

double randfrom(double min, double max){
  double range = (max - min);
  double div = RAND_MAX / range;
  return min + (rand() / div);
}

void bva(){

  FILE* f = fopen("../../../output/tests.txt", "r");
  double x  = 0;
  double y = 0;
  int z = 0;
  while( fscanf(f, "%lf,%lf,%d,\n", &x, &y, &z) > 0 ) // parse %d followed by ','
    {
      printf ("x=%lf, y=%lf, z=%d\n", x,y,z);
      foo_raw(x,y,z);
    }

    fclose(f);





}

void rt(){
  clock_t start, end;
  double cpu_time_used;
  double min=-1e307;
  double max=+1e307;
  int stop=0;
  long int iter=0;

  FILE* f = fopen("../../../output/time.txt", "r");
  double t_bva = -1;
  if (fscanf(f, "%lf", &t_bva)>0)
    printf ("I shall be running for %lf seconds\n", t_bva );
  else
    printf ("I cannot successfully obtain t_bva\n" );
  fclose(f);
  start = clock();

  while (!stop){
    iter++;
    double d = randfrom(min,max);
    double d2 = randfrom(min,max);
    double d3 = randfrom(min,max);
    int d3_int = (int)(floor(d3));
    foo_raw(d,d2,d3_int);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    if (cpu_time_used>t_bva) stop=1;
  }
  printf ("Random testing: nfev = %ld\n", iter);
}



int main(int argc, char *argv[]){

  if (argc <2){
    printf ("Pls provide one argument: 0 for bva, 1 for random testing\n");
    return -1;
  }
  int choice= atoi(argv[1]);
  if (choice ==0)
    bva();
  else
     rt();
  return 0;


    
}
  //gcc cov.c foo.c libm.a -fprofile-arcs -ftest-coverage -o cov
  //rm *.gcov *.cpp *.gcno *.gcda
