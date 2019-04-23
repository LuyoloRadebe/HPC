/******************************************************************************
* FILE: omp_hello.c
* DESCRIPTION:
*   In this simple example, the master thread forks a parallel region.
*   All threads in the team obtain their unique thread number and print it.
*   The master thread only prints the total number of threads. Two OpenMP
*   library routines are used to obtain the number of threads and each
*   thread's number.
* Compile this using: gcc -Wall -fopenmp -o omp_hello.exe omp_hello.c
* Then execute under Cygwin using: ./omp_hello.exe
* AUTHOR: Danie Ludick, dludick@sun.ac.za
* LAST REVISED: 2019-04-15
******************************************************************************/

#include <stdio.h>
#include "omp.h"

int main (int argc, char * argv[])
{

#pragma omp parallel
	{
	    printf ("I am %d of num_threads:%d\n", omp_get_thread_num(), omp_get_num_threads());
	}

    return 0;
}
