#!/bin/sh

# Órdenes para el sistema de colas:
# 1. Asigna al trabajo un nombre
# SBATCH --job-name=helloOMP
# 2. Asignar el trabajo a una cola (partición)
# SBATCH --partition=ac
# 2. Asignar el trabajo a un account
# SBATCH --account=ac

# Obtener información de las variables del entorno del sistema de colas:
echo "Id. usuario del trabajo: $SLURM_JOB_USER"
echo "Id. del trabajo: $SLURM_JOBID"
echo "Nombre del trabajo especificado por usuario: $SLURM_JOB_NAME"
echo "Directorio de trabajo (en el que se ejecuta el script): $SLURM_SUBMIT_DIR"
echo "Cola: $SLURM_JOB_PARTITION"
echo "Nodo que ejecuta este trabajo:$SLURM_SUBMIT_HOST"
echo "Nº de nodos asignados al trabajo: $SLURM_JOB_NUM_NODES"
echo "Nodos asignados al trabajo: $SLURM_JOB_NODELIST"
echo "CPUs por nodo: $SLURM_JOB_CPUS_PER_NODE"

# Instrucciones del script para ejecutar código:
printf "\n%s\n" "Ejecución SumaVectores varias veces con distinto nº de elementos:"


: $((componentes = 65536))

while [ "$componentes" -lt 67108865 ]; do
	srun -p ac -n1 ./SumaVectores "$componentes" && printf "\n"
	: $((componentes *= 2))
done
