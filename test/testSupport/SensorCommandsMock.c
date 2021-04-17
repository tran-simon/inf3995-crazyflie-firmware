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

float getSpeed(){
    float speed = 0.0f;
    float vx = 4.0f;
    float vy = 3.0f;
    
    speed = sqrt(powf(vx, 2) + powf(vy, 2));

    return speed;
}
