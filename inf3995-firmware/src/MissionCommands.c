#include "../interface/MissionCommands.h"

void takeOff(){
    //elevateDrone(0.5f);
    //sleepus(400000);
    init();
    char command;
    while(true){
        appchannelReceivePacket(&command, sizeof(command), 100);
        if(command == 'l' || command == 'r'){
            break;
        }
        else {
            //explore();
            test();
        }
        
    }
};

void land(){
    //lowerDrone(0.0f);
    debug(4);
};

void returnToBase(){
    //lowerDrone(0.0f);
    debug(4);
};


