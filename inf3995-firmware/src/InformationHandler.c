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
        response.value = getBattery();
        response.type = 'b';
        break;
    
    //Get the speed
    case 'v':
        response.value = getSpeed(state);
        response.type = 'v';
        break;

    //Get the state
    case 's':
        if(getSpeed(state) >= 0.02f) {
            response.value = 1.0f;
        }
        else {
            response.value = 0.0f;
        }
        response.type = 's';
        break;

    //Temporary: get the point in front of the drone
    case 'p':
        response.value = getPoint(state).x;
        response.type = 'p';
        break;

    default:
        break;
    };

    return response;
};
