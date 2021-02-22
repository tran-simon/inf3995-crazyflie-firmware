#include "../interface/InformationHandler.h"

struct Information getStats(char command){
    struct Information response;
    setpoint_t setpoint;
    state_t state;

    switch (command)
    {
    case 'b':
        response.value = pmBatteryChargeFromVoltage(pmGetBatteryVoltage());
        response.type = 'b';
        break;
    
    case 'v':
        crtpCommanderHighLevelGetSetpoint(&setpoint, &state);
        if(!isnanf(state.velocity.x) && !isnanf(state.velocity.y) && !isnanf(state.velocity.z)) {
            response.value = sqrtf(powf(state.velocity.x, 2) + powf(state.velocity.y, 2) + powf(state.velocity.z, 2));
        }
        else{
            response.value = 0.0f;
        }
        response.type = 'v';
        break;

    default:
        break;
    };

    return response;
};
