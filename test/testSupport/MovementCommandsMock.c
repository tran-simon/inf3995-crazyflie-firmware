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

void avoidObstacles(struct RangingDeckReadings readings, struct DroneMock* drone, enum CfDir* dir){
    if (readings.frontDistance < MINIMAL_RANGE_DIST) { goBackwards(TRAVEL_DISTANCE, drone); stayInPlace(drone); *dir = BACK; }
    if (readings.leftDistance  < MINIMAL_RANGE_DIST) { goRight(TRAVEL_DISTANCE, drone);     stayInPlace(drone); *dir = RIGHT;}
    if (readings.backDistance  < MINIMAL_RANGE_DIST) { goForward(TRAVEL_DISTANCE, drone);   stayInPlace(drone); *dir = FRONT;}
    if (readings.rightDistance < MINIMAL_RANGE_DIST) { goLeft(TRAVEL_DISTANCE, drone);      stayInPlace(drone); *dir = LEFT;}
}

void explore(struct DroneMock* drone, int step, struct RangingDeckReadings readings, enum CfDir* dir){
    avoidObstacles(readings, drone, dir);

    // Changes direction every 80 steps.
    if (step % 80 == 0) {
        if (*dir == FRONT || *dir == BACK) {
            *dir = (readings.leftDistance > readings.rightDistance)? LEFT : RIGHT;
        } else {
            *dir = (readings.frontDistance > readings.backDistance)? FRONT : BACK;
        }
    }
    /* Move the drone in the direction m_cDir */
    selectMovingDirection(*dir, drone); 
};


bool goToBase(struct DroneMock* drone, struct RangingDeckReadings readings, enum CfDir* dir, float RSSI, int debounce) {
    if (RSSI <= MINIMAL_RSSI_DIST) {
        if (debounce <= 5){
            debounce += 1;
            avoidObstacles(readings, drone, dir);
            return false;
        }
        lowerDrone(0.0f, drone);
        debounce = 0;
        return true;
    } else {
        debounce = 0;
    }

    if (readings.backDistance >= MIN_RETURN_TO_BASE_DIST) {
        *dir = BACK;
    }
    else if (readings.leftDistance >= MIN_RETURN_TO_BASE_DIST) {
        *dir = LEFT;
    }
    else {
        *dir = RIGHT;
    }
    avoidObstacles(readings, drone, dir);
    /* Move the drone in the direction m_cDir */
    selectMovingDirection(*dir, drone);    
    return false;
}
