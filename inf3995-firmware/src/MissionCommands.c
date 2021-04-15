#include "../interface/MissionCommands.h"

void takeOff(){
    init();
    sleepus(400000);
    elevateDrone(0.4f);
    sleepus(500000);
    //explore();
    //debug(4);
};

void land(){
    lowerDrone(0.0f);
    //debug(4);
};

bool returnToBase(){
    return goToBase();
    //debug(4);
};

void exploration() {
    // Call explore function
    explore();
    //test();
}



