#include "commander.h"
#include "Info.h"
#include "crtp_commander_high_level.h"

void setHoverSetpoint(setpoint_t *setpoint, float vx, float vy, float z, float yawrate);

struct Information activateCommand(char command);