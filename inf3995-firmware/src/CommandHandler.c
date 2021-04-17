#include "../interface/CommandHandler.h"

struct Information activateCommand(char command){
    struct Information response;

    switch (command)
    {
    //Take off
    case 't':
        takeOff();
        response.type = 't';
        response.value1 = 1.0f;
        response.value2 = 0.0f;
        response.value3 = 0.0f;
        response.value4 = 0.0f;
        response.value5 = 0.0f;
        response.value6 = 0.0f;
        break;
    //Explore
    case 'e':
        exploration();
        response.type = 't';
        response.value1 = 1.0f;
        response.value2 = 0.0f;
        response.value3 = 0.0f;
        response.value4 = 0.0f;
        response.value5 = 0.0f;
        response.value6 = 0.0f;
        break;
    // Land
    case 'l':
        land();
        response.type = 'l';
        response.value1 = 0.0f;
        response.value2 = 0.0f;
        response.value3 = 0.0f;
        response.value4 = 0.0f;
        response.value5 = 0.0f;
        response.value6 = 0.0f;
        break;

    // Return to base
    case 'r':
        response.type = 'r';
        response.value1 = returnToBase() ? 1.0f : 0.0f;
        response.value2 = 0.0f;
        response.value3 = 0.0f;
        response.value4 = 0.0f;
        response.value5 = 0.0f;
        response.value6 = 0.0f;
        break;

    default:
        break;
    };

    return response;
};