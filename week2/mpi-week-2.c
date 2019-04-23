/******************************************************************************
* FILE: mpi_week-2.c
* DESCRIPTION:
*   Testing out some of the MPI concepts in Week-2 of the HPC813 course.
* Compile this using: mpicc -o mpi-week-2 mpi-week-2.c
* Then execute under Cygwin using e.g. 4 processes with: mpirun omp_hello.exe -n 4
* AUTHOR: Danie Ludick, dludick@sun.ac.za
* LAST REVISED: 2019-04-15
******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
//#include <time.h>
#include "mpi.h"

int main(int argc, char *argv[])
{
    int proc_id;
    int proc_size,len;
    int my_random, sum_random; 
    char name[MPI_MAX_PROCESSOR_NAME];

    /* Default MPI initialization */
    MPI_Init(0, 0);

    /* Get the rank (ID) of each process*/
    MPI_Comm_rank(MPI_COMM_WORLD, &proc_id);

    /* Get the size of the total process pool*/
    MPI_Comm_size(MPI_COMM_WORLD, &proc_size);

    /* Greetings from each process */
    MPI_Get_processor_name(name,&len);
    printf("Hello world from process %d of %d on processor %s \n", proc_id, proc_size, name);
    
    /* -----------------------------------------------------------------------
     * Example 1 : All-reduce (adapted from Eijkhout OMP/MPI textbook pp. 31)
     *  Give each process a random number, and sum these numbers together.
     */

    /* Create a random number on each process, based on the process ID */
    my_random = (rand() % 10) * proc_id;

    printf("Process %d has my_random = %d\n", proc_id, my_random);
    
    /* add the random variables together */
    //MPI_Allreduce(&my_random, &sum_random, 1, MPI_INT, MPI_SUM, MPI_COMM_WORLD);
    MPI_Allreduce(MPI_IN_PLACE, &my_random, 1, MPI_INT, MPI_SUM, MPI_COMM_WORLD);

    printf("Result %d on process %d\n",my_random, proc_id);    

    MPI_Finalize();

    return 0;
}
