#include "../interface/MovementCommands.h"

/* Declaration of tha map */
static ExploreMap map;
static CfDir m_cDir = FRONT;

//static bool isP2PSender = false;
//static int counter = 0;
//static bool testing = false;
//static float previousDist = 0.0f;
static float minimalDist = 350.0f;

void debug(int del){
    for (int i=0; i< 20; ++i){
        ledSet(del, true);
        sleepus(1000);
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
    crtpCommanderHighLevelGoTo((-1.0f * distance), 0.0f, 0.0f, 0.0f, 0.2f, true);
}

void goLeft(float distance){
    crtpCommanderHighLevelGoTo(0.0f, distance, 0.0f, 0.0f, 0.2f, true);
}

void goRight(float distance){
    crtpCommanderHighLevelGoTo(0.0f, (-1.0f * distance), 0.0f, 0.0f, 0.2f, true);
}

void stayInPlace(){
    crtpCommanderHighLevelGoTo(0.0f, 0.0f, 0.0f, 0.0f, 0.1f, true);
}

void elevateDrone(float height){
    crtpCommanderHighLevelTakeoff(height, 0.1f);
};

void lowerDrone(float height){
    crtpCommanderHighLevelLand(height, 1.5f);
};

void selectMovingDirection() {
    switch (m_cDir) {
        case FRONT : goForward(0.05f);break;
        case LEFT  : goRight(0.05f);break;
        case BACK  : goForward(-0.05f);break;
        case RIGHT : goRight(-0.05f);break;
        default: break;
    }

    //sleepus(100000);
}

void avoidObstacles(struct RangingDeckReadings readings){
    if (readings.frontDistance < minimalDist) { goBackwards(0.05f); stayInPlace(); m_cDir = BACK; }
    if (readings.leftDistance  < minimalDist) { goRight(0.05f);     stayInPlace(); m_cDir = RIGHT;}
    if (readings.backDistance  < minimalDist) { goForward(0.05f);   stayInPlace(); m_cDir = FRONT;}
    if (readings.rightDistance < minimalDist) { goLeft(0.05f);      stayInPlace(); m_cDir = LEFT;}
}

void explore(){
    struct RangingDeckReadings readings;
    readings.frontDistance = getFrontDistance();
    readings.backDistance = getBackDistance();
    readings.leftDistance = getLeftDistance();
    readings.rightDistance = getRightDistance();

    /* Move the drone in the map */
    float xValue = 0.0f;
    float yValue = 0.0f;
    logVarId_t xID = logGetVarId("stateEstimate", "x");
    logVarId_t yID = logGetVarId("stateEstimate", "y");
    xValue = logGetFloat(xID);
    yValue = logGetFloat(yID);
    map.Move(&map, (int) (xValue * 100.0f), (int) (yValue * 100.0f));

    /* Add the sensor value to the map */
    map.AddData(&map,
                (int) (readings.leftDistance / 10),   /* left distance  in cm */
                (int) (readings.frontDistance / 10),  /* Front distance in cm */
                (int) (readings.rightDistance / 10),  /* right distance in cm */
                (int) (readings.backDistance / 10));  /* back distance  in cm */

    /* Get the best direction to explore, according to potential information gain */
    m_cDir = (CfDir) map.GetBestDir(&map, (MapExplorationDir) m_cDir);

    /* If the drone is too close to an obstacle, move away */
    avoidObstacles(readings);

    /* Move the drone in the direction m_cDir */
    selectMovingDirection();    
};

void goToBase() {
    struct RangingDeckReadings readings;
    readings.frontDistance = getFrontDistance();
    readings.backDistance = getBackDistance();
    readings.leftDistance = getLeftDistance();
    readings.rightDistance = getRightDistance();
    
    /* Move the drone in the map */
    float xValue = 0.0f;
    float yValue = 0.0f;
    logVarId_t xID = logGetVarId("stateEstimate", "x");
    logVarId_t yID = logGetVarId("stateEstimate", "y");
    xValue = logGetFloat(xID);
    yValue = logGetFloat(yID);
    map.Move(&map, (int) (xValue * 100.0f), (int) (yValue * 100.0f));

    if (map.distMap[map.mBase.x][map.mBase.y] == 0) {
        map.BuildFlow(&map);
    }

    if (getRSSI() <= 36) {
        lowerDrone(0.0f);
    }

    // We get the next direction
    m_cDir = (CfDir) map.NextNode(&map,  
                (int) (readings.leftDistance / 10),   /* left distance  in cm */
                (int) (readings.frontDistance / 10),  /* Front distance in cm */
                (int) (readings.rightDistance / 10),  /* right distance in cm */
                (int) (readings.backDistance / 10));  /* back distance  in cm */

    /* Move the drone in the direction m_cDir */
    selectMovingDirection();    
}

void test(){
    //if(!isP2PSender){p2pRegisterCB(p2pCallbackHandler);} // register a call back if you are not the sender
    struct RangingDeckReadings readings;
    readings.frontDistance = getFrontDistance();
    readings.backDistance = getBackDistance();
    readings.leftDistance = getLeftDistance();
    readings.rightDistance = getRightDistance();

    if(readings.frontDistance < 250.0f){
        goBackwards(0.05f);
    }

    if(readings.backDistance < 250.0f){
        goForward(0.05f);
    }

    if(readings.leftDistance < 250.0f){
        goRight(0.05f);
    }

    if(readings.rightDistance < 250.0f){
        goLeft(0.05f);
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
    //TODO: get the initial position of the drone
   	map.Construct(&map, (int) (5 * 100), (int) (5 * 100)); // Initial position of the drone, in cm
}

void p2pCallbackHandler(P2PPacket *p){
    // Do not make fonction too long ***
    // call drone avoidance with p->data
    //testing = true;
}