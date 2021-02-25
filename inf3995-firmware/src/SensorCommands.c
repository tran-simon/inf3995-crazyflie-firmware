#include "../interface/SensorCommands.h"

float getLeftDistance(){
    logVarId_t idLeft = logGetVarId("range", "left");
    return((float)logGetUint(idLeft));
}

float getRightDistance(){
    logVarId_t idRight = logGetVarId("range", "right");
    return((float)logGetUint(idRight));
}

float getFrontDistance(){
    logVarId_t idFront = logGetVarId("range", "front");
    return((float)logGetUint(idFront));
}

float getBackDistance(){
    logVarId_t idBack = logGetVarId("range", "back");
    return((float)logGetUint(idBack));
}

float getBattery(){
    return (pmBatteryChargeFromVoltage(pmGetBatteryVoltage()));
}

float getRSSI(){
    logVarId_t idRSSI = logGetVarId("radio", "rssi");
    return((float)logGetUint(idRSSI));
}


float getSpeed(state_t state){
    float speed = 0.0f;

    if(!isnanf(state.velocity.x) && !isnanf(state.velocity.y) && !isnanf(state.velocity.z)) {
        speed = sqrtf(powf(state.velocity.x, 2) + powf(state.velocity.y, 2) + powf(state.velocity.z, 2));
    }

    return speed;
}

point_t getPoint(state_t state){
    point_t point;

    point.x = state.position.x + getFrontDistance();
    point.y = state.position.y;
    point.z = state.position.z;
    point.timestamp = state.position.timestamp;

    return point;
}