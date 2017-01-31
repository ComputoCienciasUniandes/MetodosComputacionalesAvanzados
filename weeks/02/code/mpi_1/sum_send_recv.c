#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
  int rank;
  int size;

  MPI_Init(NULL, NULL);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);

  srand48(rank);
  float number = drand48();
  fprintf(stderr, "my number is %f (proc %d)\n", number, rank);

  if (rank != 0) {
    MPI_Send(&number, 1, MPI_FLOAT, 0, 0, MPI_COMM_WORLD);
  } 
  else if (rank == 0) {
    int i;
    float sum = number;
    for(i=1;i<size;i++){
      MPI_Recv(&number, 1, MPI_FLOAT, i, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
      sum += number;
    }
    fprintf(stderr, "The sum is %f\n", sum);
  }
  MPI_Finalize();
}
