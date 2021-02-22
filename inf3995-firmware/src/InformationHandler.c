#include "../interface/InformationHandler.h"


struct Information getStats(char command){
    struct Information response;
    setpoint_t setpoint;
    state_t state;
    float speed = 0.0f;

    crtpCommanderHighLevelGetSetpoint(&setpoint, &state);
    if(!isnanf(state.velocity.x) && !isnanf(state.velocity.y) && !isnanf(state.velocity.z)) {
        speed = sqrtf(powf(state.velocity.x, 2) + powf(state.velocity.y, 2) + powf(state.velocity.z, 2));
    }
    

    switch (command)
    {
    case 'b':
        response.value = pmBatteryChargeFromVoltage(pmGetBatteryVoltage());
        response.type = 'b';
        break;
    
    case 'v':
        response.value = speed;
        response.type = 'v';
        break;

    case 's':
        if(speed > 0.0f) {
            response.value = 1.0f;
        }
        else {
            response.value = 0.0f;
        }
        response.type = 's';
        break;


    default:
        break;
    };

    return response;
};
