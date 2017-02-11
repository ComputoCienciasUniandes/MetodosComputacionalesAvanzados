#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
  int n_points, rank, size, i, j;
  float *data;
  FILE *out;
  MPI_Init(NULL, NULL);

  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);

  if(rank==0){
    out = fopen("file.dat", "w");
    fclose(out);
  }
  MPI_Barrier( MPI_COMM_WORLD );

  n_points = 5;
  data  = malloc(n_points * sizeof(float));
  for(i=0;i<n_points;i++){
    data[i] = rank;
  }
  MPI_Barrier( MPI_COMM_WORLD );
  
  for(i=0;i<size;i++){
    if(i==rank){
      out = fopen("file.dat", "a");
      for(j=0;j<n_points;j++){
	fprintf(out, "%f ", data[j]);
      }
      fprintf(out, "\n");
      fclose(out);
    }
    MPI_Barrier( MPI_COMM_WORLD );
  }
  
  MPI_Finalize();
  return 0;
}
