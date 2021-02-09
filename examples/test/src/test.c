#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#include "app.h"

#include "FreeRTOS.h"
#include "task.h"

#include "debug.h"
#include "led.h"
#include "app_channel.h"
#include "pm.h"

void appMain()
{
	int value = 0;
	float battery = 0.0;
	char command;

	ledSet(0, 0);

	while(1){
		if (appchannelReceivePacket(&command, sizeof(command), 100)) {
			if(command == 'l'){
				value = value ^ 1;
				ledSet(0, value);
			}

			else if (command == 'b'){
				battery = pmBatteryChargeFromVoltage(pmGetBatteryVoltage());
				appchannelSendPacket(&battery, sizeof(battery));
			}
		}
	}
}
