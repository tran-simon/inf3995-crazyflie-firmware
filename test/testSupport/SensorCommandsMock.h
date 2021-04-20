#ifndef _MOCK_SENSOR_COMMANDS_H
#define _MOCK_SENSOR_COMMANDS_H

#include "stabilizer_types.h"
#include <math.h>

#define LEFT_SENSOR_VALUE 200.0f
#define RIGHT_SENSOR_VALUE 1000.0f
#define FRONT_SENSOR_VALUE 1000.0f
#define BACK_SENSOR_VALUE 1000.0f
#define BATTERY 40.0f
#define RSSI_VALUE 80.0f


struct sensors_data {
    float leftSensor;
    float rightSensor;
    float frontSensor;
    float backSensor;
    float battery;
    float RSSI;
};


float getLeftDistance();

float getRightDistance();

float getFrontDistance();

float getBackDistance();

float getBattery();

float getRSSI();

float getSpeed();

#endif
