#PBS -q batch
#PBS -N test_scheduler
#PBS -l nodes=1:ppn=4
#PBS -M j.e.forero.romero@gmail.com
#PBS -m abe

module load openmpi/1.8.5
cd $PBS_O_WORKDIR
NPROCS=`wc -l < $PBS_NODEFILE`
mpiexec -v -n $NPROCS ./mpi_hello_world
