#include <stdio.h>
#include <stdlib.h>
#include <gsl/gsl_rng.h>

/* gcc gsl_mersenne_twister.c -lgsl -lcblas */

int main(int argc, char **argv){
  const gsl_rng_type * T;
  gsl_rng * r;
  int i, n_points;
  double x;

  T = gsl_rng_mt19937;
  r = gsl_rng_alloc (T);

  n_points  = atoi(argv[1]);
  for(i=0;i<n_points;i++){
    x = gsl_rng_uniform(r);
    fprintf(stdout, "%f\n", x);
  }

  return 0;
}
