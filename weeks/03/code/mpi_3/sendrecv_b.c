/*
  Listing 12.4 from 'Introduction to Scientific and Technical Computing'
  Edited by F. T. Willmore, E. Jankowski and C. Colina (CRC Press).
 */
#include <stdio.h>
#include <mpi.h>

int main(int argc, char **argv){
  int rank, source, destination, in_number, out_number;


  printf("asdfasdf");
  MPI_Init(NULL, NULL);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  out_number = 42;
  printf("%d\n", rank);
  if(rank==0){
    destination = 1;
    source = 1;
    MPI_Send(&out_number, 1, MPI_INT, destination, 0, MPI_COMM_WORLD);
    //    MPI_Recv(&in_number, 1, MPI_INT, source, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

    //    printf("process %d sent %d received by %d\n", source, number, rank);
  }else if (rank==1){
    destination = 0;
    source = 0;

    //    MPI_Send(&out_number, 1, MPI_INT, destination, 0, MPI_COMM_WORLD);
    MPI_Recv(&in_number, 1, MPI_INT, source, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

    printf("process %d sent %d received by %d\n", source, number, rank);
  }
  MPI_Finalize();
  return 0;
}
