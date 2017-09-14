#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

double FUNC (double);


/* generate a random floating point number from min to max */

double randfrom(double min, double max){
  double range = (max - min);
  double div = RAND_MAX / range;
  return min + (rand() / div);
}

void bva(){
  FILE* f = fopen(ROOT "/output/tests.txt", "r");
  double x  = 0;
  while( fscanf(f, "%lf,\n", &x) > 0 ) // parse %d followed by ','
    {
      printf ("x = %f\n",x);
    FUNC(x);
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

  FILE* f = fopen("../output/time.txt", "r");
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

    FUNC(d);
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
