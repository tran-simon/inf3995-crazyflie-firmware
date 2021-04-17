#include "../interface/MissionCommands.h"

void takeOff(){
    elevateDrone(0.4f);
    sleepus(500000);
};

void land(){
    lowerDrone(0.0f);
};

bool returnToBase(){
    return goToBase();
};

void exploration() {
    explore();
}



