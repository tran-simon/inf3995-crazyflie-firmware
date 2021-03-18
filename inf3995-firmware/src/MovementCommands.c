#include "../interface/MovementCommands.h"
 static int state = FORWARD;
/*ledSet(0, true);
    sleepus(10000);
    ledSet(0, false);*/
//static float previousDist = 0.0f;

void rotate(float angle){
    crtpCommanderHighLevelGoTo(0.0f, 0.0f, 0.0f, angle, 0.1f, true);
}

void goForward(float distance){
    crtpCommanderHighLevelGoTo(distance, 0.0f, 0.0f, 0.0f, 0.1f, true);
}

void goBackwards(float distance){
    crtpCommanderHighLevelGoTo(-distance, 0.0f, 0.0f, 0.0f, 0.1f, true);
}

void goLeft(float distance){
    crtpCommanderHighLevelGoTo(0.0f, -distance, 0.0f, 0.0f, 0.1f, true);
}

void goRight(float distance){
    crtpCommanderHighLevelGoTo(0.0f, distance, 0.0f, 0.0f, 0.1f, true);
}

void elevateDrone(float height){
    crtpCommanderHighLevelTakeoff(height, 0.3f);
};

void lowerDrone(float height){
    crtpCommanderHighLevelLand(height, 1.5f);
};


void avoidObstacles(struct RangingDeckReadings readings){
    if(readings.frontDistance < 200.0f){
        goForward(-0.05f);
        //sleepus(100000);
    }
    if(readings.backDistance < 200.0f){
        goForward(0.05f);
        //sleepus(100000);
    }
    if(readings.leftDistance < 200.0f){
        goRight(-0.05f);
        //sleepus(100000);
    }
    if(readings.rightDistance < 200.0f){
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

    sleepus(100000);
    avoidObstacles(readings);
    
};