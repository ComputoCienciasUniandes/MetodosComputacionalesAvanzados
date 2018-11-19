#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "mpi.h"
#define PI 3.14159265358979323846264338327

int main(int argc, char **argv){
  int n_points;
  float mu, sigma;
  int i;
  int j;
  int deg=10;
  int rank, number;
  int n_points_proc;
  char filename[128];
  double sum, myintegral, integral;

  MPI_Init (&argc, &argv);
  MPI_Comm_rank (MPI_COMM_WORLD, &rank);
  MPI_Comm_size (MPI_COMM_WORLD, &number);

  n_points = atoi(argv[1]);
  myintegral = 0.0;
  srand48(rank);
  n_points_proc = n_points/number;
  for(i=0;i<n_points_proc;i++){    
   sum = 0.0;
    for(j=0;j<deg;j++){
      sum += drand48();
    }
    sum = pow(sum,2);
    myintegral +=sum;
  }
  myintegral /= n_points_proc;

  MPI_Reduce(&myintegral, &integral, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
 if(rank==0){
   integral /= number;
   fprintf(stdout, "%d %e %e\n", n_points, integral, fabs(integral - 155.0/6.0));
 }
 MPI_Finalize(); 
  return 0;
}
