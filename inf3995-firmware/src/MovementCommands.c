#include "../interface/MovementCommands.h"
 static int state = FORWARD;
 static bool isP2PSender = false;
 //static int counter = 0;
 static bool testing = false;
//static float previousDist = 0.0f;

void debug(int del){
    for (int i=0; i< 200; ++i){
        ledSet(del, true);
        sleepus(10000);
        ledSet(del, false);
    }  
}

void rotate(float angle){
    crtpCommanderHighLevelGoTo(0.0f, 0.0f, 0.0f, angle, 0.1f, true);
}

void goForward(float distance){
    crtpCommanderHighLevelGoTo(distance, 0.0f, 0.0f, 0.0f, 0.2f, true);
}

void goBackwards(float distance){
    crtpCommanderHighLevelGoTo(-distance, 0.0f, 0.0f, 0.0f, 0.2f, true);
}

void goLeft(float distance){
    crtpCommanderHighLevelGoTo(0.0f, -distance, 0.0f, 0.0f, 0.2f, true);
}

void goRight(float distance){
    crtpCommanderHighLevelGoTo(0.0f, distance, 0.0f, 0.0f, 0.2f, true);
}

void stayInPlace(){
    crtpCommanderHighLevelGoTo(0.0f, 0.0f, 0.0f, 0.0f, 0.1f, true);
}

void elevateDrone(float height){
    crtpCommanderHighLevelTakeoff(height, 0.3f);
};

void lowerDrone(float height){
    crtpCommanderHighLevelLand(height, 1.5f);
};


void avoidObstacles(struct RangingDeckReadings readings){
    if(readings.frontDistance < 350.0f){
        goForward(-0.05f);
        //sleepus(100000);
    }
    if(readings.backDistance < 350.0f){
        goForward(0.05f);
        //sleepus(100000);
    }
    if(readings.leftDistance < 350.0f){
        goRight(-0.05f);
        //sleepus(100000);
    }
    if(readings.rightDistance < 350.0f){
        goRight(0.05f);
        //sleepus(100000);
    }
}

void explore(){
    struct RangingDeckReadings readings;
    readings.frontDistance = getFrontDistance();
    readings.backDistance = getBackDistance();
    readings.leftDistance = getLeftDistance();
    readings.rightDistance = getRightDistance();

    switch(state){
        case FORWARD:{
            // Check if wall is too close
            if(readings.frontDistance < 500.0f){
                goForward(-0.01f);
                stayInPlace();
                sleepus(100000);
                state = RIGHT;
                break;
            }
            goForward(0.02f);
            break;
        }
        case BACKWARD:{
            // Check if wall is too close
            if(readings.backDistance < 500.0f){
                goForward(0.01f);
                stayInPlace();
                sleepus(100000);
                state = LEFT;
                break;
            }
            goForward(-0.02f);
            break;
        }
        case LEFT:{
            //rand
            // Check if wall is too close
            if(readings.leftDistance < 500.0f){
                goRight(-0.01f);
                stayInPlace();
                sleepus(100000);
                state = FORWARD;
                break;
            }
            goRight(0.02f);
            break;
        }
        case RIGHT:{
            // Check if wall is too close
            if(readings.rightDistance < 500.0f){
                goRight(0.01f);
                stayInPlace();
                sleepus(100000);
                state = BACKWARD;
                break;
            }
            goRight(-0.02f);
            break;
        }
    }

    sleepus(100000);
    avoidObstacles(readings);
    
};

void test(){
    if(!isP2PSender){p2pRegisterCB(p2pCallbackHandler);} // register a call back if you are not the sender
    struct RangingDeckReadings readings;
    readings.frontDistance = getFrontDistance();
    readings.backDistance = getBackDistance();
    readings.leftDistance = getLeftDistance();
    readings.rightDistance = getRightDistance();

    if(readings.frontDistance < 100.0f){
        debug(0);
        if(isP2PSender){
        static P2PPacket pk;
        pk.port = 0x00;
        pk.size = 11;
        memcpy(&pk.data, "Hello World", 11);
        radiolinkSendP2PPacketBroadcast(&pk);
    }
    }

    if(readings.backDistance < 100.0f){
        debug(2);
    }

    if(readings.leftDistance < 100.0f){
        debug(3);
    }

    if(readings.rightDistance < 100.0f){
        debug(4);
    }

    if(testing){
        debug(4);
        testing = false;
    }
};

void init(){
    uint64_t address = configblockGetRadioAddress();
    uint8_t id = (uint8_t) ((address) & 0x00000000ff);
    if(id == 1){
        isP2PSender = true;
        debug(4);
    }
}

void p2pCallbackHandler(P2PPacket *p){
    // Do not make fonction too long ***
    // call drone avoidance with p->data
    testing = true;
}