#include "../interface/InformationHandler.h"


struct Information getStats(char command){
    struct Information response;
    //Get the actual setpoint and state of the drone
    setpoint_t setpoint;
    state_t state;
    crtpCommanderHighLevelGetSetpoint(&setpoint, &state);

    switch (command)
    {
    //Get the battery
    case 'b':
        response.value1 = getBattery();
        response.value2 = (float)0.0;
        response.value3 = (float)0.0;
        response.value4 = (float)0.0;
        response.value5 = (float)0.0;
        response.value6 = (float)0.0;
        response.type = 'b';
        break;
    
    //Get the speed
    case 'v':
        response.value1 = getSpeed(state);
        response.value2 = (float)0.0;
        response.value3 = (float)0.0;
        response.value4 = (float)0.0;
        response.value5 = (float)0.0;
        response.value6 = (float)0.0;
        response.type = 'v';
        break;

    //Get the state
    case 's':
        if(getSpeed(state) >= 0.02f) {
            response.value1 = 1.0f;
            
        }
        else {
            response.value1 = 0.0f;
        }
        response.value2 = (float)0.0;
        response.value3 = (float)0.0;
        response.value4 = (float)0.0;
        response.value5 = (float)0.0;
        response.value6 = (float)0.0;
        response.type = 's';
        break;

    //Temporary: get the point in front of the drone
    case 'p':
        //response.value1 = getPoint(state).x;
        response.value2 = (float)0.0;
        response.value3 = (float)0.0;
        response.value4 = (float)0.0;
        response.value5 = (float)0.0;
        response.value6 = (float)0.0;
        response.value1 = getRSSI();
        response.type = 'p';
        break;
    
    case 'm':;
        point_t position;
        estimatorKalmanGetEstimatedPos(&position);
        response.value1 = position.x;
        response.value2 = position.y;
        response.value3 = getFrontDistance();
        response.value4 = getBackDistance();
        response.value5 = getLeftDistance();
        response.value6 = getRightDistance();
        response.type = 'm';
        break;

    default:
        break;
    };

    return response;
};
