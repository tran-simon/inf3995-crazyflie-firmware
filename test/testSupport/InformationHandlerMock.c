#include "InformationHandlerMock.h"

struct Information getStats(char command) {
    struct Information response;
    switch(command){
        //Get the battery
    case 'b':
        response.value1 = getBattery();
        response.value2 = (float)0.0;
        response.value3 = (float)0.0;
        response.value4 = (float)0.0;
        response.value5 = (float)0.0;
        response.value6 = (float)0.0;
        response.type = 'b';
        break;

    //Get the speed
    case 'v':
        response.value1 = getSpeed();
        response.value2 = (float)0.0;
        response.value3 = (float)0.0;
        response.value4 = (float)0.0;
        response.value5 = (float)0.0;
        response.value6 = (float)0.0;
        response.type = 'v';
        break;

    //Get the state
    case 's':
        if(getSpeed() >= 0.01f) {
            response.value1 = 1.0f;
        }
        else {
            response.value1 = 0.0f;
        }
        if(CRASHED){
            response.value1 = 2.0f;
        }
        response.value2 = (float)0.0;
        response.value3 = (float)0.0;
        response.value4 = (float)0.0;
        response.value5 = (float)0.0;
        response.value6 = (float)0.0;
        response.type = 's';
        break;
    
    case 'm':
        response.value1 = POS_X;
        response.value2 = POS_Y;
        response.value3 = getFrontDistance();
        response.value4 = getBackDistance();
        response.value5 = getLeftDistance();
        response.value6 = getRightDistance();
        response.type = 'm';
        break;

    default:
        break;
    };

    return response;
}