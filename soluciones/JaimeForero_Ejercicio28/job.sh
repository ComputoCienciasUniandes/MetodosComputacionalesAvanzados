#PBS -l nodes=1:ppn=16,mem=1gb,walltime=00:10:00
#PBS -M je.forero@uniandes.edu.co
#PBS -m abe
#PBS -N ejercicio25


module load anaconda/python3
cd $PBS_O_WORKDIR # este es el directorio desde donde se ejecuto qsub
rm -f *.dat
mpicc integral.c -o integral.x
mpirun -np 10 ./integral.x 1E3 > data_3.txt
mpirun -np 10 ./integral.x 1E4 > data_4.txt
