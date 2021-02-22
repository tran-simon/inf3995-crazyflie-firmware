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
    //setpoint_t setpoint;

    switch (command)
    {
    case 't':
        crtpCommanderHighLevelTakeoff(0.5f, 2.0f);
        response.type = 't';
        response.value = 1;
        break;
    
    case 'l':
        crtpCommanderHighLevelLand(0.0f, 2.0f);
        response.type = 'l';
        response.value = 0;
        break;

    default:
        break;
    };

    return response;
};