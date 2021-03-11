#include "../interface/MissionCommands.h"

void takeOff(){
    elevateDrone(0.5f);
};

void land(){
    lowerDrone(0.0f);
};

void returnToBase(){
    lowerDrone(0.0f);
};


