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


void appMain()
{
	paramVarId_t paramIdCommanderEnHighLevel = paramGetVarId("commander", "enHighLevel");
  	paramSetInt(paramIdCommanderEnHighLevel, 1);

	char command;
	struct Information response;
	char state = 'w';

	while(1){
		if (appchannelReceivePacket(&command, sizeof(command), 100)) {
			if(command != 't' && command != 'l' && command != 'f' && command != 'r'){
				// send info 
				response = getStats(command);
				appchannelSendPacket(&response, sizeof(response));
			}
			else if(command == 't'){
				state = 't';
			}
			else{
				state = 'w';
				response = activateCommand(command);
			}
		}

		switch(state){
			case 't': {
				activateCommand('t');
				break;
			}
			case 'w': {
				break;
			}
		}
	}
}
