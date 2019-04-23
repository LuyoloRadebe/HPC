#!/bin/bash


nodes=2
for nodes in {2..10..2}
do
	sed -i 's|#PBS -e .*|#PBS -e /mnt/lustre/users/lradebe/HPC/week2/optnodes_'"$nodes"'.sh.err|g' bsort_job.job
 	sed -i 's|#PBS -o .*|#PBS -o /mnt/lustre/users/lradebe/HPC/week2/optnodes_'"$nodes"'.sh.out|g' bsort_job.job
	sed -i 's|select.*|select='"$nodes"':ncpus=24:mpiprocs=24:nodetype=haswell_reg|g' bsort_job.job
	sed -i 's|mpirun.*|mpirun -np '"$nodes"' bsort largebsort.txt large_out.txt|g' bsort_job.job 
	qsub bsort_job.job
done
