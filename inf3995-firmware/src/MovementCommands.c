#include "../interface/MovementCommands.h"

/* Declaration of tha map */
static ExploreMap map;
static CfDir m_cDir = FRONT;

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
    crtpCommanderHighLevelGoTo(-1 * distance, 0.0f, 0.0f, 0.0f, 0.2f, true);
}

void goLeft(float distance){
    crtpCommanderHighLevelGoTo(0.0f, distance, 0.0f, 0.0f, 0.2f, true);
}

void goRight(float distance){
    crtpCommanderHighLevelGoTo(0.0f, -1 * distance, 0.0f, 0.0f, 0.2f, true);
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

    /* Move the drone in the map */
    //TODO: get the position of the drone
    map.Move(&map, (int) (10 * 100), (int) (10  * 100));

    /* Add the sensor value to the map */
    // TODO: chage to make y_pos concorde to the right dir, ...
    map.AddData(&map,
                (int) (readings.frontDistance / 10),  /* Front distance in cm */
                (int) (readings.leftDistance / 10),   /* left distance  in cm */
                (int) (readings.backDistance / 10),   /* back distance  in cm */
                (int) (readings.rightDistance / 10)); /* right distance in cm */

    /* If the drone is too close to an obstacle, move away */
    float minimalDist = 500;
    if (readings.frontDistance < minimalDist) { debug(1); /*goBackwards(0.01f); stayInPlace();*/ }
    if (readings.leftDistance  < minimalDist) { debug(2); /*goRight(0.01f);     stayInPlace();*/ }
    if (readings.backDistance  < minimalDist) { debug(3); /*goForward(0.01f);   stayInPlace();*/ }
    if (readings.rightDistance < minimalDist) { debug(4); /*goLeft(0.01f);      stayInPlace();*/ }

    /* Get the best direction to explore, according to potential information gain */
    m_cDir = (CfDir) map.GetBestDir(&map, (MapExplorationDir) m_cDir);

    switch (m_cDir) {
        case FRONT : debug(1); /*goForward(0.02f);  */ break;
        case LEFT  : debug(2); /*goLeft(0.02f);     */ break;
        case BACK  : debug(3); /*goBackwards(0.02f);*/ break;
        case RIGHT : debug(4); /*goRight(0.02f);    */ break;
        default: break;
    }

    sleepus(100000);
    
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
    /*uint64_t address = configblockGetRadioAddress();
    uint8_t id = (uint8_t) ((address) & 0x00000000ff);
    if(id == 1){
        isP2PSender = true;
        debug(4);
    }*/

    /* Initialization of the map */
	ExploreMapNew(&map);
   	map.Construct(&map, (int) (10 * 100), (int) (10 * 100)); // Initial position of the drone, in cm
}

void p2pCallbackHandler(P2PPacket *p){
    // Do not make fonction too long ***
    // call drone avoidance with p->data
    testing = true;
}