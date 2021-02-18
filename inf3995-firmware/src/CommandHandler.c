#include "../interface/CommandHandler.h"

void setHoverSetpoint(setpoint_t *setpoint, float vx, float vy, float z, float yawrate)
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
};


struct Information activateCommand(char command){
    struct Information response;
    setpoint_t setpoint;

    switch (command)
    {
    case 't':
        setHoverSetpoint(&setpoint, 0, 0, 0.5f, 0);
		commanderSetSetpoint(&setpoint, 3);
        response.type = 't';
        response.value = 1;
        break;
    
    case 'l':
        setHoverSetpoint(&setpoint, 0, 0, 0.0f, 0);
		commanderSetSetpoint(&setpoint, 3);
        response.type = 'l';
        response.value = 0;
        break;

    default:
        break;
    };

    return response;
};