#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#include "app.h"

#include "FreeRTOS.h"
#include "task.h"
#include "commander.h"
#include "debug.h"
#include "led.h"
#include "app_channel.h"
#include "pm.h"
#include "../interface/test.h"
#include "log.h"
#include "param.h"


static void setHoverSetpoint(setpoint_t *setpoint, float vx, float vy, float z, float yawrate)
{
  setpoint->mode.z = modeAbs;
  setpoint->position.z = z;


  setpoint->mode.yaw = modeVelocity;
  setpoint->attitudeRate.yaw = yawrate;


  setpoint->mode.x = modeVelocity;
  setpoint->mode.y = modeVelocity;
  setpoint->velocity.x = vx;
  setpoint->velocity.y = vy;

  setpoint->velocity_body = true;
}

void appMain()
{
	static setpoint_t setpoint;

	int value = 0;
	float battery = 0.0;
	char command;
	struct Information response;

	ledSet(0, 0);

	while(1){
		if (appchannelReceivePacket(&command, sizeof(command), 100)) {
			if(command == 'l'){
				value = value ^ 1;
				ledSet(0, value);
				setHoverSetpoint(&setpoint, 0, 0, 0.5f, 0);
				commanderSetSetpoint(&setpoint, 3);
			}

			else if (command == 'b'){
				battery = pmBatteryChargeFromVoltage(pmGetBatteryVoltage());
				response.value = battery;
				response.type = 'b';
				appchannelSendPacket(&response, sizeof(response));
			}
		}
	}
}
