#!/bin/bash

nodes=1
#for nodes in {2..12..2}
#do
unknowns=2
        until [ $unknowns -ge 9 ]; do
        feko_filename="${unknowns}_unknowns_${nodes}_nodes.pre"
        job_filename="${unknowns}_unknowns_${nodes}_nodes.job"
        echo feko filename : $feko_filename
        echo job filename : $job_filename
        sed 's|#azl = .*|#azl = '"$unknowns"'|g' serial_job.pre > $feko_filename
        sed 's|#PBS -e .*|#PBS -e /mnt/lustre/users/lradebe/HPC/week1/feko_serial/serial_run_'"$unknowns"'_'"$nodes"'.sh.err|g' serial_job.job > $job_filename
        sed -i 's|#PBS -o .*|#PBS -o /mnt/lustre/users/lradebe/HPC/week1/feko_serial/serial_run_'"$unknowns"'_'"$nodes"'.sh.out|g' $job_filename
        sed -i 's|select.*|select='"$nodes"':ncpus=24:mpiprocs=24:nodetype=haswell_reg|g' $job_filename
        sed -i 's|runfeko .*|runfeko '"$feko_filename"' --use-job-scheduler|g' $job_filename
        ((unknowns++))
        qsub $job_filename
        done
#echo nodes: $nodes
#done

exit 0
