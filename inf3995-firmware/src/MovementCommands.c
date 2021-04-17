#include "../interface/MovementCommands.h"

/* Declaration of global variables*/
static CfDir m_cDir = FRONT;
static int step = 0;
static int debounce = 0;
static float minimalRangeDist = 400.0f;
static float minimalRSSIDist = 35.0f;
static float minReturnBaseDist = 500.0f;
static float travelDistance = 0.05f;

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
        case FRONT : goForward(travelDistance);break;
        case LEFT  : goLeft(travelDistance);break;
        case BACK  : goBackwards(travelDistance);break;
        case RIGHT : goRight(travelDistance);break;
        default: break;
    }
}

void avoidObstacles(struct RangingDeckReadings readings){
    if (readings.frontDistance < minimalRangeDist) { goBackwards(0.05f); stayInPlace(); m_cDir = BACK; }
    if (readings.leftDistance  < minimalRangeDist) { goRight(0.05f);     stayInPlace(); m_cDir = RIGHT;}
    if (readings.backDistance  < minimalRangeDist) { goForward(0.05f);   stayInPlace(); m_cDir = FRONT;}
    if (readings.rightDistance < minimalRangeDist) { goLeft(0.05f);      stayInPlace(); m_cDir = LEFT;}
}

void explore(){
    struct RangingDeckReadings readings;
    readings.frontDistance = getFrontDistance();
    readings.backDistance = getBackDistance();
    readings.leftDistance = getLeftDistance();
    readings.rightDistance = getRightDistance();
    avoidObstacles(readings);

    // Changes direction every 80 steps.
    if (step % 80 == 0) {
        if (m_cDir == FRONT || m_cDir == BACK) {
            m_cDir = (readings.leftDistance > readings.rightDistance)? LEFT : RIGHT;
        } else {
            m_cDir = (readings.frontDistance > readings.backDistance)? FRONT : BACK;
        }
    }
    /* Move the drone in the direction m_cDir */
    selectMovingDirection(); 
    step++;   
};

bool goToBase() {
    struct RangingDeckReadings readings;
    readings.frontDistance = getFrontDistance();
    readings.backDistance = getBackDistance();
    readings.leftDistance = getLeftDistance();
    readings.rightDistance = getRightDistance();
    
    if (getRSSI() <= minimalRSSIDist) {
        if (debounce <= 5){
            debounce += 1;
            avoidObstacles(readings);
            return false;
        }
        lowerDrone(0.0f);
        debounce = 0;
        return true;
    } else {
        debounce = 0;
    }

    if (readings.backDistance >= minReturnBaseDist) {
        m_cDir = BACK;
    }
    else if (readings.leftDistance >= minReturnBaseDist) {
        m_cDir = LEFT;
    }
    else {
        m_cDir = RIGHT;
    }
    avoidObstacles(readings);
    /* Move the drone in the direction m_cDir */
    selectMovingDirection();    
    return false;
}
