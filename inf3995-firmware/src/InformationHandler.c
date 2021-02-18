#include "../interface/InformationHandler.h"

struct Information getStats(char command){
    struct Information response;

    switch (command)
    {
    case 'b':
        response.value = pmBatteryChargeFromVoltage(pmGetBatteryVoltage());
        response.type = 'b';
        break;
    
    default:
        break;
    };

    return response;
};
