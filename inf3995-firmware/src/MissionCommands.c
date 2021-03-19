#include "../interface/MissionCommands.h"

void takeOff(){
    elevateDrone(0.5f);
    sleepus(400000);
    char command;
    while(true){
        appchannelReceivePacket(&command, sizeof(command), 100);
        if(command == 'l' || command == 'r'){
            break;
        } else {
            explore();
        }
        
    }
};

void land(){
    lowerDrone(0.0f);
};

void returnToBase(){
    lowerDrone(0.0f);
    //ledSet(1, false);
};


