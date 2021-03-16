#include "../interface/MissionCommands.h"

void takeOff(){
    //elevateDrone(0.5f);
    ledSet(0, false);
    sleepus(300000);
    char command;
    while(true){
        appchannelReceivePacket(&command, sizeof(command), 100);
        if(command == 'l' || command == 'r'){
            break;
        } else {
            //dell light
            ledSet(0, true);
            sleepus(300000);
            ledSet(0, false);
            sleepus(300000);
        }
        
    }
   // explore();
};

void land(){
    lowerDrone(0.0f);
};

void returnToBase(){
    //lowerDrone(0.0f);
    ledSet(1, false);
};


