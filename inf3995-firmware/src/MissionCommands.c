#include "../interface/MissionCommands.h"

void takeOff(){
    init();
    sleepus(400000);
    elevateDrone(0.5f);
    sleepus(500000);
    //explore();
    //debug(4);
};

void land(){
    lowerDrone(0.0f);
    //debug(4);
};

void returnToBase(){
    //lowerDrone(0.0f);
    debug(4);
};

void exploration() {
    // Call explore function
    explore();
    //test();
}



