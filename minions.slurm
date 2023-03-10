#!/bin/bash
#SBATCH --job-name=minions
#SBATCH --output=minions.out
#SBATCH --partition=Centaurus
#SBATCH --error=minions.err
#SBATCH --ntasks=1
#SBATCH --nodes=1
#SBATCH --tasks-per-node=1
#SBATCH --time=00:02:00

# run the code with 5 minions
./minions 5

rm minions

# run the code with 13 minions
./minions 13

rm minions

# run the code with 29 minions
./minions 29

rm minions

# run the code with 200 minions
./minions 200

rm minions
