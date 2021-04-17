#include "Info.h"
#include <math.h>
#include "../interface/SensorCommands.h"
#include "estimator_kalman.h"
#include "sitaw.h"

/**
 * @brief Retrieve information bassed on the char command given in param
 * 
 * @return Information requested
 */
struct Information getStats(char command);