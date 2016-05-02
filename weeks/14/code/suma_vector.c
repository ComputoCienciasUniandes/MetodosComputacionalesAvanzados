#include <stdio.h>
#include <stdlib.h>
#include "omp.h"

/*
  Basado en el tutorial:
  http://openmp.org/mp-documents/omp-hands-on-SC08.pdf
*/

void suma(double *A, double *B, double *C, int n_points);
double *reserva(int n_points);
void print(double *x, int n_points);
void main (){ 
  double *A, *B, *C;
  int n_points = 100000;

  A = reserva(n_points);
  B = reserva(n_points);
  C = reserva(n_points);

  suma(A, B, C, n_points);

  print(C,10);
}

void print(double *x, int n_points){
  int i;
  for(i = 0 ; i < n_points ; i++){
    fprintf(stdout, "%f\n", x[i]);
  }
}

void suma(double *A, double *B, double *C, int n_points){
  int i, j;
#pragma omp parallel for private(j), shared(A,B,C)
  for (i = 0 ; i < n_points; i++){  
    C[i] = 0.0;
    for(j=0;j<50000;j++){
      C[i] += A[i] + B[i];
    } 
  } 
}
 

double *reserva(int n_points){
  double *x;
  int i;
  if(!(x=malloc(sizeof(double) * n_points))){
    printf("malloc problem\n");
    exit(1);
}
  for(i=0;i<n_points;i++){
    x[i] = 1.0;
  }
  return x;
}
