#include "crtp_commander_high_level.h"
#include "../interface/SensorCommands.h"

/**
 * @brief Struct that represent the value read from the distance sensor.
 * 
 * @param frontDistance : represent the distance from the front sensor
 * @param backDistance  : represent the distance from the back sensor
 * @param leftDistance  : represent the distance from the left sensor
 * @param rightDistance : represent the distance from the right sensor
 */
struct RangingDeckReadings{
      float frontDistance;
      float backDistance;
      float leftDistance;
      float rightDistance;
};

/**
 * @brief Enum that represents in which state of direction the drone is in
 */
enum CfDir {FRONT, BACK, LEFT, RIGHT};

/**
 * @brief This function makes the drone move forward.
 * @param distance  distance of movement
 * @return void
 */
void goForward(float distance);

/**
 * @brief This function makes the drone move backward.
 * @param distance  distance of movement
 * @return void
 */
void goBackwards(float distance);

/**
 * @brief This function makes the drone move left.
 * @param distance  distance of movement
 * @return void
 */
void goLeft(float distance);

/**
 * @brief This function makes the drone move right.
 * @param distance  distance of movement
 * @return void
 */
void goRight(float distance);

/**
 * @brief This function makes the drone move upward on the z axis.
 * @param height  the height that the drone will reach
 * @return void
 */
void elevateDrone(float height);

/**
 * @brief This function makes the drone move downward on the z axis.
 * @param height  the height that the drone will reach
 * @return void
 */
void lowerDrone(float height);

/**
 * @brief This function call goForward, goBackwards, goLeft or goRight depending on m_cDir.
 * @return void
 */
void selectMovingDirection();

/**
 * @brief This function makes the drone avoid obstacle according to the sensor reading.
 * @param readings  struct that represent the value read by the distance sensor
 * @return void
 */
void avoidObstacles(struct RangingDeckReadings readings);

/**
 * @brief This function makes the drone explore the environment by changing the axis of mouvement every 80 steps
 * @return void
 */
void explore();

/**
 * @brief This function makes the drone go back to it's base 
 * @return bool whether the drone has landed or still returning to base
 */
bool goToBase();

/**
 * @brief This function stabilize the drone by making it stay in place.
 * @return void
 */
void stayInPlace();
