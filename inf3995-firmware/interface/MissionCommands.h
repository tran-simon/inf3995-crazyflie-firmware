#include "MovementCommands.h"
#include "sleepus.h"
#include "led.h"
#include "app_channel.h"
/**
 * @brief Take off drone and start exploring
 * 
 * @return void
 */
void takeOff();

/**
 * @brief Land the drone at it's current position
 * 
 * @return void
 */
void land();

/**
 * @brief Land the drone at the base of operations
 *
 * @return bool whether the drone is landing
 */
bool returnToBase();

void exploration();