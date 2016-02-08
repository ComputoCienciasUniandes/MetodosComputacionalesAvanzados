#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double average(double *x, int n_points);
double average_sq(double *x, int n_points);
double func(double x);

int main(int argc, char **argv){
  int n_points;
  double x;
  double *f;
  int i;
  double integral;
  
  n_points = atoi(argv[1]);

  if(!(f = malloc(n_points * sizeof(double)))){
    fprintf(stderr, "problem with f allocation\n");
    exit(1);    
  }
  
  for(i=0; i<n_points; i++){
    x = drand48();
    f[i] = func(x);
  }

  integral = average(f, n_points);

  fprintf(stdout, "the integral is: %f\n", integral);
  return 0;
}

double average(double *x, int n_points){
  int i;
  double a;
  a = 0.0;
  for(i=0;i<n_points;i++){
    a += x[i];
  }
  a /= n_points;
  return a;
}

double average_sq(double *x, int n_points){
  int i;
  double a;
  a = 0.0;
  for(i=0;i<n_points;i++){
    a += x[i]*x[i];
  }
  a /= n_points;
  return a;
}

double func(double x){
  return exp(x);
}
