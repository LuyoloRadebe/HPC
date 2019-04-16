!/bin/bash

counter=1
until [ $counter -ge 9 ]; do
        sed -i 's/#azl = 0..*/#azl = 0.'"$counter"'/g' /mnt/lustre/users/lradebe/HPC/week1/feko_serial/tuning_serial.pre
        ((counter++))
        qsub serial_job.job
done

exit 0
