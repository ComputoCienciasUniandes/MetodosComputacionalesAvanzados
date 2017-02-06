/*
  Listing 12.4 from 'Introduction to Scientific and Technical Computing'
  Edited by F. T. Willmore, E. Jankowski and C. Colina (CRC Press).
 */
#include <stdio.h>
#include <mpi.h>

int main(int argc, char **argv){
  int rank, source, destination, in_number, out_number;
  MPI_Request send_request, recv_request;
  MPI_Status status;

  MPI_Init(NULL, NULL);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);

  if(rank==0){
    out_number = 42;
    destination = 1;
    source = 1;
    MPI_Irecv(&in_number, 1, MPI_INT, source, 0, MPI_COMM_WORLD, &recv_request);
    MPI_Isend(&out_number, 1, MPI_INT, destination, 0, MPI_COMM_WORLD, &send_request);
   

  }else if (rank==1){
    out_number = 24;
    destination = 0;
    source = 0;    
    MPI_Irecv(&in_number, 1, MPI_INT, source, 0, MPI_COMM_WORLD, &recv_request);
    MPI_Isend(&out_number, 1, MPI_INT, destination, 0, MPI_COMM_WORLD, &send_request);
  }

  MPI_Wait(&send_request, &status);
  MPI_Wait(&recv_request, &status);

  printf("proc %d sent %d (received by proc %d)\n", source, in_number, rank);

  MPI_Finalize();
  return 0;
}
