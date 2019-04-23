/******************************************************************************
* FILE: mpi_hello.c
* DESCRIPTION: norm
******************************************************************************/
#include <stdio.h>
#include <math.h>
#include "mpi.h"


int main(int argc, char ** argv)
{
    int rank;
    int size;
    int I,J,K;
    double square, sum_square;
     int n;
  int * data = NULL;
  int c, s;
  int * chunk;
  int o;
  int * other;
  int step;
  int p, id;
  MPI_Status status;
  double elapsed_time;
  FILE * file = NULL;
  int i;

    MPI_Init(&argc, 0);
     
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (rank == 0) 
  {
    // read size of data
    file = fopen(argv[1], "r");
    fscanf(file, "%d", &n);
    // compute chunk size
    c = n/p; if (n%p) c++;
    // read data from file
    data = (int *)malloc(p*c * sizeof(int));
    for (i = 0; i < n; i++)
      fscanf(file, "%d", &(data[i]));
    fclose(file);
    // pad data with 0 -- doesn't matter
    for (i = n; i < p*c; i++)
      data[i] = 0;
  }

    square = (*argc[rank])^2;
    printf("Process %d has squared value = %f\n", rank, square);
    MPI_Allreduce(&square, &sum_square, 1, MPI_INT, MPI_SUM, MPI_COMM_WORLD); 
    square = sqrt(sum_square);
    printf("Norm is = %f",square);

    MPI_Finalize();
    return 0;
}
