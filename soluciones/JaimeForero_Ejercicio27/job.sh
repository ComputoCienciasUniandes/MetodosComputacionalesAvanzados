#PBS -l nodes=1:ppn=16,mem=1gb,walltime=00:10:00
#PBS -M je.forero@uniandes.edu.co
#PBS -m abe
#PBS -N ejercicio25


module load anaconda/python3
cd $PBS_O_WORKDIR # este es el directorio desde donde se ejecuto qsub
rm -f *.dat
mpicc sample.c -o sample.x
mpirun -np 10 ./sample.x 10000 0.0 1.0
