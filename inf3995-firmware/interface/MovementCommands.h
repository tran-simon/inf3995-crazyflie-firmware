#include "crtp_commander_high_level.h"
#include "../interface/SensorCommands.h"
enum CfExplorationState {
      FORWARD,
      WALL_END,
      ROTATE,
      DEBOUNCE,
      AVOID_WALL
   };

   enum CfExplorationDir {
      LEFT_WALL,
      RIGHT_WALL
   };
   
   enum CfState {
      STATE_START,
      STATE_TAKE_OFF,
      STATE_EXPLORE,
      STATE_GO_TO_BASE,
      STATE_LAND
   };

   struct RangingDeckReadings{
       float frontDistance;
       float backDistance;
       float leftDistance;
       float rightDistance;
   };
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


void elevateDrone(float height);

void lowerDrone(float height);

void explore();

void stop();