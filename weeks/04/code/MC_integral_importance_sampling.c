#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double average(double *x, int n_points);
double average_sq(double *x, int n_points);
double x_with_p_distribution(void);
double p_distribution_value(double x);
double func(double x);

int main(int argc, char **argv){
  int n_points;
  double x,y;
  double *f;
  int i;
  double integral;
  
  n_points = atoi(argv[1]);
  srand48(n_points);
  
  if(!(f = malloc(n_points * sizeof(double)))){
    fprintf(stderr, "problem with f allocation\n");
    exit(1);    
  }
  
  for(i=0; i<n_points; i++){
    x = x_with_p_distribution();
    f[i] = func(x)/p_distribution_value(x);
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

double x_with_p_distribution(void){
  double x = drand48();
  return pow(x,(2.0/3.0));
}

double p_distribution_value(double x){
  return 2.0/3.0 * pow(x,-(1.0/3.0));
}

double func(double x){
  return pow(x,-(1.0/3.0)) + x/10.0;
}
