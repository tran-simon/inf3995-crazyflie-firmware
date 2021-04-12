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
   };*/

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

void avoidObstacles(struct RangingDeckReadings readings);

void goBackwards(float distance);

void goLeft(float distance);

void goRight(float distance);

void stayInPlace();

void debug();

void test();

void init();

void p2pCallbackHandler(P2PPacket *p);

//void sendP2P();

//void receiveP2P();

//void receiveInfo(P2PPacket *p);