#include "CommandHandlerMock.h"

struct Information activateCommand(char command, bool returnToBase){
    struct Information response;

    switch (command)
    {
    //Take off
    case 't':
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
        response.type = 'l';
        response.value1 = 1.0f;
        response.value2 = 0.0f;
        response.value3 = 0.0f;
        response.value4 = 0.0f;
        response.value5 = 0.0f;
        response.value6 = 0.0f;
        break;

    // Return to base
    case 'r':
        response.value1 = returnToBase ? 1 : 0;
        response.value2 = 0.0f;
        response.value3 = 0.0f;
        response.value4 = 0.0f;
        response.value5 = 0.0f;
        response.value6 = 0.0f;
        response.type = 'r';
        break;

    default:
        break;
    };

    return response;

}