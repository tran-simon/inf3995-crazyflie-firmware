#include "../interface/CommandHandler.h"

struct Information activateCommand(char command){
    struct Information response;

    switch (command)
    {
    //Take off
    case 't':
        takeOff();
        response.type = 't';
        response.value = 1;
        break;
    //Explore
    case 'e':
        exploration();
        response.type = 't';
        response.value = 1;
        break;
    // Land
    case 'l':
        land();
        response.type = 'l';
        response.value = 0;
        break;

    // Return to base
    case 'r':
        returnToBase();
        response.type = 'r';
        response.value = 0;
        break;

    default:
        break;
    };

    return response;
};