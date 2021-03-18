#include "SensorCommandsMock.h"

float getLeftDistance(){
    return LEFT_SENSOR_VALUE;
}

float getRightDistance(){
    return RIGHT_SENSOR_VALUE;
}

float getFrontDistance(){
    return FRONT_SENSOR_VALUE;
}

float getBackDistance(){
    return BACK_SENSOR_VALUE;
}

float getBattery(){
    return BATTERY;
}

float getRSSI(){
    return RSSI_VALUE;
}

float getSpeed(state_t state){
    float speed = 0.0f;

    if(!isnan(state.velocity.x) && !isnan(state.velocity.y) && !isnan(state.velocity.z)) {
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