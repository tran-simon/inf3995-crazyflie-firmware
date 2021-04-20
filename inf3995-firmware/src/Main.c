#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#include "app.h"

#include "commander.h"
#include "debug.h"
#include "app_channel.h"
#include "log.h"
#include "param.h"
#include "../interface/InformationHandler.h"
#include "../interface/CommandHandler.h"
#include "../interface/SensorCommands.h"
#include "led.h"

#define VBAT_30 3.75f

void appMain()
{
	/****************************************/
	/*           Initialization             */
	/****************************************/
	paramVarId_t paramIdCommanderEnHighLevel = paramGetVarId("commander", "enHighLevel");
  	paramSetInt(paramIdCommanderEnHighLevel, 1);

	char command;
	struct Information response;
	char state = 'o';

	/****************************************/
	/*             Maint Loop               */
	/****************************************/
	while(1){
		if (appchannelReceivePacket(&command, sizeof(command), 100)) {
			if (command != 't' && command != 'l' && command != 'f' && command != 'r'){
				// send info
				response = getStats(command);
				appchannelSendPacket(&response, sizeof(response));
			}
			else if (command == 't') {
				// The drone take off only if it has enough battery
				if (getBattery() < VBAT_30) {
					ledSet(2, true);
				} else {
					activateCommand('t');
					// switch to explore state
					state = 'e';
				}
			}
			else if (command == 'r') {
				// switch to return to base state
				state = 'r';
			}
			else {
				// switch to other state
				state = 'o';
				response = activateCommand(command);
			}
		}
		switch (state){
			case 'e': {
				// If the drone is under 30%, switch to return to base
				if (getBattery() < VBAT_30) {
					state = 'r';
				} else {
					// explore state
					activateCommand('e');
				}
				break;
			}
			case 'r': {
				// return to base state
				if (activateCommand('r').value1) {
					state = 'o';
				}
				break;
			}
			case 'o': {
				//other state -- Do nothing
				break;
			}
		}
	}
}
