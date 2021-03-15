#include "../interface/MovementCommands.h"
static int state = FORWARD;
static float previousDist = 0.0f;

void rotate(float angle){
    crtpCommanderHighLevelGoTo(0.0f, 0.0f, 0.0f, angle, 0.1f, true);
}

void goForward(float distance){
    crtpCommanderHighLevelGoTo(distance, 0.0f, 0.0f, 0.0f, 0.1f, true);
}

void elevateDrone(float height){
    crtpCommanderHighLevelTakeoff(height, 0.3f);
};

void lowerDrone(float height){
    crtpCommanderHighLevelLand(height, 1.5f);
};

void stop(){
    crtpCommanderHighLevelStop();
};

void explore(){
    struct RangingDeckReadings readings;
    readings.frontDistance = getFrontDistance();
    readings.backDistance = getBackDistance();
    readings.leftDistance = getLeftDistance();
    readings.rightDistance = getRightDistance();

    switch(state){
        case FORWARD: {
            if(readings.leftDistance > (1.5f * previousDist)){
                state = WALL_END;
                break;
            }
            if(readings.leftDistance < 200.0f) {
               state = AVOID_WALL;
            }
            if(readings.frontDistance < 300.0f) { 
                
               goForward(0.0f); // Stop any ongoing mvmt
               state = ROTATE;
               rotate(-((float)(M_PI)/2.0f));
               break;
            }
            goForward(0.05f);
            break;
        } 
        case WALL_END: {
            goForward(0.0f);
            state = ROTATE;
            rotate((float) M_PI/2.0f);
            break;
        }
        case AVOID_WALL:{
            rotate((float)-M_PI/8);
            break;
        }
        previousDist = readings.leftDistance;



    }

};