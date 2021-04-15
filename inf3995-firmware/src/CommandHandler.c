#include "../interface/CommandHandler.h"

struct Information activateCommand(char command){
    struct Information response;

    switch (command)
    {
    //Take off
    case 't':
        takeOff();
        response.type = 't';
        response.value1 = 1;
        break;
    //Explore
    case 'e':
        exploration();
        response.type = 't';
        response.value1 = 1;
        break;
    // Land
    case 'l':
        land();
        response.type = 'l';
        response.value1 = 0;
        break;

    // Return to base
    case 'r':
        response.value1 = returnToBase() ? 1 : 0;
        response.type = 'r';
        break;

    default:
        break;
    };

    return response;
};