#ifndef _MOCK_INFORMATION_HANDLER_H
#define _MOCK_INFORMATION_HANDLER_H

#include "stabilizer_types.h"
#include "../../inf3995-firmware/interface/Info.h"
#include "SensorCommandsMock.h"
#include <math.h>

#define POS_X 10.0f
#define POS_Y 20.0f
#define CRASHED false


struct Information getStats(char command);



#endif