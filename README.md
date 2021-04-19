# INF3995-crazyflie-firmware
Ce projet est un fork de [crazyflie-firmware.](https://github.com/bitcraze/crazyflie-firmware)

Le répertoire inf3995-firmware contient notre code personnalisé.

Le répertoire server contient le code du serveur node permettant la mise-à-jour à distance

Utilisez le docker-compose du répertoire inf3995-main pour compiler le firmware. Voir le README

---

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