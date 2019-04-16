#!/bin/bash

counter=1
until [ $counter -ge 9 ]; do
	sed -i 's/#azl = 0..*/#azl = '"$counter"'/g' /mnt/lustre/users/lradebe/HPC/week1/feko_parallel/tuning_parallel.pre  
	((counter++))
	qsub parallel_job.job
done

exit 0
