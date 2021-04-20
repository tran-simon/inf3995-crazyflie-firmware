#include "MovementCommands.h"
#include "sleepus.h"
/**
 * @brief Take off drone
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
 * @return bool whether the drone has landed or still returning to base
 */
bool returnToBase();

/**
 * @brief Drone starts exploring
 * 
 * @return void
 */
void exploration();