#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "mpi.h"
#define PI 3.14159265358979323846264338327

int main(int argc, char **argv){
  long n_points;
  double x, y, r;
  double gauss_1, gauss_2;
  double *list;
  float mu, sigma;
  long long i;
  FILE *out;
  int rank, number;
  int n_points_proc;
  char filename[128];

  MPI_Init (&argc, &argv);
  MPI_Comm_rank (MPI_COMM_WORLD, &rank);
  MPI_Comm_size (MPI_COMM_WORLD, &number);

  n_points = atoi(argv[1]);
  mu = atof(argv[2]);
  sigma = atof(argv[3]);

  n_points_proc = n_points / number;

  if(!(list=malloc(n_points_proc * sizeof(double)))){
    fprintf(stderr, "Problema con la reserva de memoria\n");
    exit(1);
  }
   

  srand48(rank);
  for(i=0;i<n_points_proc;i++){    
      x = drand48();
      y = drand48();
      gauss_1 = sqrt(-2.0 * log(x)) * cos(2.0* PI * y);
      gauss_2 = sqrt(-2.0 * log(x)) * sin(2.0* PI * y);
      
      gauss_1 = gauss_1*sigma + mu;
      list[i] = gauss_1;
  }

  sprintf(filename, "sample_%d.dat", rank);
  if(!(out = fopen(filename, "w"))){
    fprintf(stderr, "Problema abriendo el archivo\n");
    exit(1);
  }
  
  for(i=0;i<n_points_proc;i++){
    fprintf(out, "%f\n", list[i]);
  }

  fclose(out);
  MPI_Barrier(MPI_COMM_WORLD);
  MPI_Finalize(); 
  return 0;
}
