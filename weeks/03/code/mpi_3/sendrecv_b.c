/*
  Listing 12.4 from 'Introduction to Scientific and Technical Computing'
  Edited by F. T. Willmore, E. Jankowski and C. Colina (CRC Press).
 */
#include <stdio.h>
#include <mpi.h>

int main(int argc, char **argv){
  int rank, source, destination, number;
  number = 0;
  source = 0;
  destination = 1;


  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  if(rank==0){
    destination = 1;
    source = 1;
    MPI_Recv(&number, 1, MPI_INT, source, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    MPI_Send(&number, 1, MPI_INT, destination, 0, MPI_COMM_WORLD);
    printf("process %d sent %d received by %d\n", source, number, rank);
  }else if (rank==1){
    destination = 0;
    source = 0;
    MPI_Recv(&number, 1, MPI_INT, source, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    MPI_Send(&number, 1, MPI_INT, destination, 0, MPI_COMM_WORLD);
    printf("process %d sent %d received by %d\n", source, number, rank);
  }
  MPI_Finalize();
  return 0;
}
