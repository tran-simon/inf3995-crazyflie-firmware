#ifndef _MOCK_MOVEMENT_COMMANDS_H
#define _MOCK_MOVEMENT_COMMANDS_H
#include <stdbool.h>


#define MINIMAL_RANGE_DIST 400.0f
#define MINIMAL_RSSI_DIST 35.0f
#define MIN_RETURN_TO_BASE_DIST 500.0f
#define TRAVEL_DISTANCE 0.05f

struct RangingDeckReadings{
      float frontDistance;
      float backDistance;
      float leftDistance;
      float rightDistance;
};

struct DroneMock{
    float posX;
    float posY;
    float posZ;
    struct RangingDeckReadings readings;
};

enum CfDir {FRONT, BACK, LEFT, RIGHT};

void goForward(float distance, struct DroneMock* drone);

void goBackwards(float distance, struct DroneMock* drone);

void goLeft(float distance, struct DroneMock* drone);

void goRight(float distance, struct DroneMock* drone);

void elevateDrone(float height, struct DroneMock* drone);

void lowerDrone(float height, struct DroneMock* drone);

void selectMovingDirection(enum CfDir dir, struct DroneMock* drone);

void avoidObstacles(struct RangingDeckReadings readings);

void explore();

bool goToBase();

void stayInPlace(struct DroneMock* drone);


#endif