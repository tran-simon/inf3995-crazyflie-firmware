#include "crtp_commander_high_level.h"
#include "../interface/SensorCommands.h"
#include "sleepus.h"
#include "led.h"
#include "radiolink.h"
#include "configblock.h"
#include "explore_map.h"
#include "node_array.h"
#include "estimator_kalman.h"

/*enum CfExplorationState {
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
};*/

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
 * @brief Enum that represent drone direction of mouvement.
 * 
 * @param FRONT = X_POS = 0
 * @param LEFT  = Y_NEG = 3
 * @param BACK  = X_NEG = 1
 * @param RIGHT = Y_POS = 2
 * @param STOP  = NONE  = 4
 */
typedef enum {
   FRONT = X_POS,
   LEFT  = Y_NEG,
   BACK  = X_NEG,
   RIGHT = Y_POS,
   STOP  = NONE
} CfDir;

/**
 * @brief Rotate the drone to his left
 *
 * @param angle     angle of rotation in radian
 * 
 * @return void
 */
void rotate(float angle);

/**
 * @brief This function makes the drone moves forward.
 * @param distance  distance of movement
 * @return void
 */
void goForward(float distance);

/**
 * @brief This function makes the drone moves backward.
 * @param distance  distance of movement
 * @return void
 */
void goBackwards(float distance);

/**
 * @brief This function makes the drone moves left.
 * @param distance  distance of movement
 * @return void
 */
void goLeft(float distance);

/**
 * @brief This function makes the drone moves right.
 * @param distance  distance of movement
 * @return void
 */
void goRight(float distance);

/**
 * @brief This function makes the drone moves upward.
 * @param height  the height that the drone will reach
 * @return void
 */
void elevateDrone(float height);

/**
 * @brief This function makes the drone moves downward.
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
 * @brief This function makes the drone explore the environment by selecting the direction
 * where the more information could be gained, by using the map.
 * @return void
 */
void explore();

/**
 * @brief This function makes the drone go back to its base by selecting the next direction that
 * could make the drone closer to the base.
 * @return void
 */
void goToBase();

/**
 * @brief This function stabilize the drone by making it stay in place.
 * @return void
 */
void stayInPlace();

void debug();

void test();

void init();

void p2pCallbackHandler(P2PPacket *p);

//void sendP2P();

//void receiveP2P();

//void receiveInfo(P2PPacket *p);