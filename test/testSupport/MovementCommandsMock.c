#include "MovementCommandsMock.h"

void goForward(float distance, struct DroneMock* drone){
    drone->posX = drone->posX + distance;
}

void goBackwards(float distance, struct DroneMock* drone){
    drone->posX = drone->posX - distance;
}

void goLeft(float distance, struct DroneMock* drone){
    drone->posY = drone->posY + distance;
}
void goRight(float distance, struct DroneMock* drone){
    drone->posY = drone->posY - distance;
}

void stayInPlace(struct DroneMock* drone){
    drone->posY = drone->posY;
    drone->posX = drone->posX;
    drone->posZ = drone->posZ;
}

void elevateDrone(float height, struct DroneMock* drone){
    drone->posZ = drone->posZ + height;
}

void lowerDrone(float height, struct DroneMock* drone){
    drone->posZ = drone->posZ - height;
}

void selectMovingDirection(enum CfDir dir, struct DroneMock* drone) {
    switch (dir) {
        case FRONT : goForward(TRAVEL_DISTANCE, drone);break;
        case LEFT  : goLeft(TRAVEL_DISTANCE, drone);break;
        case BACK  : goBackwards(TRAVEL_DISTANCE, drone);break;
        case RIGHT : goRight(TRAVEL_DISTANCE, drone);break;
        default: break;
    }
}
