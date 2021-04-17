# Crazyflie Firmware  [![CI](https://github.com/bitcraze/crazyflie-firmware/workflows/CI/badge.svg)](https://github.com/bitcraze/crazyflie-firmware/actions?query=workflow%3ACI)

This project contains the source code for the firmware used in the Crazyflie range of platforms, including
the Crazyflie 2.X and the Roadrunner.

# INF3995 - Projet de conception d'un systeme informatique 

Uniquement les fichiers situés dans inf3995-firmware est le code que nous avons écrit dans le cadre de ce cours. Le code du firmware est copié lors du docker build

Vue que nous avons changé les addresses des drones, il a été nécessaire de modifier le firmware fournie par Bitcraze afin de connecter plusieurs crazyflie. Par conséquent, on doit include le firmware dans notre répo git et non seulement le clone directement dans le conteneur docker. 

# Dépendance 

Toutes dépendance sont installée directement dans le conteneur docker à l'aide du Dockerfile

# Compilation

Afin de mettre le code du Firmware dans les drones il faut d'abord batir le conteneur Docker et par la suite faire make cload:

```bash 
sudo ./script.sh
cd ..
cd inf3995-firmware
make cload
```

# Testing 

Les tests peuvent être executé à l'aide du script de test:

```bash
./run_test.sh
```