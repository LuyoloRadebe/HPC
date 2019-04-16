#!/bin/bash

counter=9
until [ $counter -ge 20 ]; do
        sed -i 's/#azl = 0..*/#azl = '"$counter"'/g' /mnt/lustre/users/lradebe/HPC/week1/feko_serial/tuning_serial.pre
        ((counter++))
        qsub serial_job.job
done

exit 0
