#include "crtp_commander_high_level.h"
#include "../interface/SensorCommands.h"

/**
 * @brief Rotate the drone to his left
 *
 * @param angle     angle of rotation in radian
 * 
 * @return void
 */
void rotate(float angle);

/**
 * @brief Move the drone forward
 *
 * @param distance  distance of movement
 * 
 * @return void
 */
void goForward(float distance);