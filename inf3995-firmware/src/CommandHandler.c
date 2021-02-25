#include "../interface/CommandHandler.h"

struct Information activateCommand(char command){
    struct Information response;
    float battery;

    switch (command)
    {
    case 't':
        battery = getBattery();
        if(battery > 30.0f) {
            crtpCommanderHighLevelTakeoff(0.5f, 1.0f);
        }
        response.type = 't';
        response.value = 1;
        break;
    
    case 'l':
        crtpCommanderHighLevelLand(0.0f, 2.0f);
        response.type = 'l';
        response.value = 0;
        break;

    case 'r':
        goForward(0.1f);
        response.type = 'r';
        response.value = 1;
        break;

    default:
        break;
    };

    return response;
};