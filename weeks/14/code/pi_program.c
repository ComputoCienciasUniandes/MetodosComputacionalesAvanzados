#include <stdio.h>
#include "omp.h"

/*
  Basado en el tutorial:
  http://openmp.org/mp-documents/omp-hands-on-SC08.pdf
*/

void main (){ 
  int i; 
  double x, pi, step, sum = 0.0;
  int num_steps = 10000;

  step = 1.0/(double) num_steps;
#pragma omp parallel for reduction ( + : sum )  
  for (i = 0 ; i < num_steps; i++){
    x =  i * step;
    sum = sum + 4.0/(1.0+x*x);
  }
  
  pi = step * sum;
  printf("Pi: %f\n",pi);  
}

