#include "../interface/MissionCommands.h"

void takeOff(){
    elevateDrone(0.5f);
    sleepus(300000);
    explore();
};

void land(){
    lowerDrone(0.0f);
};

void returnToBase(){
    lowerDrone(0.0f);
};


