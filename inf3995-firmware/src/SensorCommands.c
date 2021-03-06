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
    logVarId_t idbatt = logGetVarId("pm", "vbat");
    return(logGetFloat(idbatt));
}

float getRSSI(){
    logVarId_t idRSSI = logGetVarId("radio", "rssi");
    return(logGetFloat(idRSSI));
}

float getSpeed(){
    float speed = 0.0f;
    logVarId_t idVx = logGetVarId("stateEstimate", "vx");
    logVarId_t idVy = logGetVarId("stateEstimate", "vy");
    float vx = logGetFloat(idVx);
    float vy = logGetFloat(idVy);

    // Calculate the average speed by combining speed in x and y
    speed = sqrtf(powf(vx, 2) + powf(vy, 2));
    return speed;
}
