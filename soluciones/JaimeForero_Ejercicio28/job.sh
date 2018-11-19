#PBS -l nodes=1:ppn=16,mem=1gb,walltime=00:10:00
#PBS -M je.forero@uniandes.edu.co
#PBS -m abe
#PBS -N ejercicio28


module load anaconda/python3
cd $PBS_O_WORKDIR # este es el directorio desde donde se ejecuto qsub
rm -f *.txt integral.x
mpicc integral.c -lm -o integral.x
mpirun -np 10 ./integral.x 1000 > data.txt
mpirun -np 10 ./integral.x 10000 >> data.txt
mpirun -np 10 ./integral.x 100000 >> data.txt
mpirun -np 10 ./integral.x 1000000 >> data.txt
mpirun -np 10 ./integral.x 10000000 >> data.txt
mpirun -np 10 ./integral.x 100000000 >> data.txt
