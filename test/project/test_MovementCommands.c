#include "MovementCommandsMock.h"
#include "SensorCommandsMock.h"
#include "unity.h"

void testThatgoForwardModifiesXPosition() {
  // Fixture
  float expected = 5.0f;
  struct RangingDeckReadings readings = {100.0f, 100.0f, 100.0f, 100.0f};
  struct DroneMock droneValues = {0.0f, 0.0f, 0.0f, readings};
  struct DroneMock* drone = &droneValues;

  // Test
  goForward(5.0f, drone);
  float actual = drone->posX;

  // Assert
  TEST_ASSERT_EQUAL_FLOAT(expected, actual);
}

void testThatgoBackwardsModifiesXPosition() {
  // Fixture
  float expected = -5.0f;
  struct RangingDeckReadings readings = {100.0f, 100.0f, 100.0f, 100.0f};
  struct DroneMock droneValues = {0.0f, 0.0f, 0.0f, readings};
  struct DroneMock* drone = &droneValues;

  // Test
  goBackwards(5.0f, drone);
  float actual = drone->posX;

  // Assert
  TEST_ASSERT_EQUAL_FLOAT(expected, actual);
}

void testThatgoLeftModifiesYPosition() {
  // Fixture
  float expected = 5.0f;
  struct RangingDeckReadings readings = {100.0f, 100.0f, 100.0f, 100.0f};
  struct DroneMock droneValues = {0.0f, 0.0f, 0.0f, readings};
  struct DroneMock* drone = &droneValues;

  // Test
  goLeft(5.0f, drone);
  float actual = drone->posY;

  // Assert
  TEST_ASSERT_EQUAL_FLOAT(expected, actual);
}

void testThatgoRightModifiesYPosition() {
  // Fixture
  float expected = -5.0f;
  struct RangingDeckReadings readings = {100.0f, 100.0f, 100.0f, 100.0f};
  struct DroneMock droneValues = {0.0f, 0.0f, 0.0f, readings};
  struct DroneMock* drone = &droneValues;

  // Test
  goRight(5.0f, drone);
  float actual = drone->posY;

  // Assert
  TEST_ASSERT_EQUAL_FLOAT(expected, actual);
}

void testThatstayInPlaceDoesntModifyPosition() {
  // Fixture
  float expected = 0.0f;
  struct RangingDeckReadings readings = {100.0f, 100.0f, 100.0f, 100.0f};
  struct DroneMock droneValues = {0.0f, 0.0f, 0.0f, readings};
  struct DroneMock* drone = &droneValues;

  // Test
  stayInPlace(drone);
  float actualX = drone->posX;
  float actualY = drone->posY;
  float actualZ = drone->posZ;

  // Assert
  TEST_ASSERT_EQUAL_FLOAT(expected, actualX);
  TEST_ASSERT_EQUAL_FLOAT(expected, actualY);
  TEST_ASSERT_EQUAL_FLOAT(expected, actualZ);
}

void testThatelevateDroneModifiesZPosition() {
  // Fixture
  float expected = 5.0f;
  struct RangingDeckReadings readings = {100.0f, 100.0f, 100.0f, 100.0f};
  struct DroneMock droneValues = {0.0f, 0.0f, 0.0f, readings};
  struct DroneMock* drone = &droneValues;

  // Test
  elevateDrone(5.0f, drone);
  float actual = drone->posZ;

  // Assert
  TEST_ASSERT_EQUAL_FLOAT(expected, actual);
}

void testThatlowerDroneModifiesZPosition() {
  // Fixture
  float expected = -5.0f;
  struct RangingDeckReadings readings = {100.0f, 100.0f, 100.0f, 100.0f};
  struct DroneMock droneValues = {0.0f, 0.0f, 0.0f, readings};
  struct DroneMock* drone = &droneValues;

  // Test
  lowerDrone(5.0f, drone);
  float actual = drone->posZ;

  // Assert
  TEST_ASSERT_EQUAL_FLOAT(expected, actual);
}

void testThatselectMovingDirectionMovesTheDroneInTheRightDirectionForFront() {
  // Fixture
  float expected = TRAVEL_DISTANCE;
  struct RangingDeckReadings readings = {100.0f, 100.0f, 100.0f, 100.0f};
  struct DroneMock droneValues = {0.0f, 0.0f, 0.0f, readings};
  struct DroneMock* drone = &droneValues;

  // Test
  selectMovingDirection(FRONT, drone);
  float actual = drone->posX;

  // Assert
  TEST_ASSERT_EQUAL_FLOAT(expected, actual);
}

void testThatselectMovingDirectionMovesTheDroneInTheRightDirectionForLeft() {
  // Fixture
  float expected = TRAVEL_DISTANCE;
  struct RangingDeckReadings readings = {100.0f, 100.0f, 100.0f, 100.0f};
  struct DroneMock droneValues = {0.0f, 0.0f, 0.0f, readings};
  struct DroneMock* drone = &droneValues;

  // Test
  selectMovingDirection(LEFT, drone);
  float actual = drone->posY;

  // Assert
  TEST_ASSERT_EQUAL_FLOAT(expected, actual);
}

void testThatselectMovingDirectionMovesTheDroneInTheRightDirectionForBack() {
  // Fixture
  float expected = -TRAVEL_DISTANCE;
  struct RangingDeckReadings readings = {100.0f, 100.0f, 100.0f, 100.0f};
  struct DroneMock droneValues = {0.0f, 0.0f, 0.0f, readings};
  struct DroneMock* drone = &droneValues;

  // Test
  selectMovingDirection(BACK, drone);
  float actual = drone->posX;

  // Assert
  TEST_ASSERT_EQUAL_FLOAT(expected, actual);
}

void testThatselectMovingDirectionMovesTheDroneInTheRightDirectionForRight() {
  // Fixture
  float expected = -TRAVEL_DISTANCE;
  struct RangingDeckReadings readings = {100.0f, 100.0f, 100.0f, 100.0f};
  struct DroneMock droneValues = {0.0f, 0.0f, 0.0f, readings};
  struct DroneMock* drone = &droneValues;

  // Test
  selectMovingDirection(RIGHT, drone);
  float actual = drone->posY;

  // Assert
  TEST_ASSERT_EQUAL_FLOAT(expected, actual);
}

void testThatselectMovingDirectionMovesTheDroneInTheRightDirectionForNone() {
  // Fixture
  float expected = 0.0f;
  struct RangingDeckReadings readings = {100.0f, 100.0f, 100.0f, 100.0f};
  struct DroneMock droneValues = {0.0f, 0.0f, 0.0f, readings};
  struct DroneMock* drone = &droneValues;

  // Test
  selectMovingDirection(4, drone);
  float actualX = drone->posX;
  float actualY = drone->posY;
  float actualZ = drone->posZ;

  // Assert
  TEST_ASSERT_EQUAL_FLOAT(expected, actualX);
  TEST_ASSERT_EQUAL_FLOAT(expected, actualY);
  TEST_ASSERT_EQUAL_FLOAT(expected, actualZ);
}

void testThatavoidObstaclesAvoidsFrontObstacles() {
  // Fixture
  float expected = -TRAVEL_DISTANCE;
  struct RangingDeckReadings readings = {100.0f, 500.0f, 500.0f, 500.0f};
  struct DroneMock droneValues = {0.0f, 0.0f, 0.0f, readings};
  struct DroneMock* drone = &droneValues;
  int dir = 0;
  enum CfDir* direction = &dir;

  // Test
  avoidObstacles(readings, drone, direction);
  float actual = drone->posX;

  // Assert
  TEST_ASSERT_EQUAL_FLOAT(expected, actual);
  TEST_ASSERT_EQUAL_INT16(1, *direction);
}

void testThatavoidObstaclesAvoidsLeftObstacles() {
  // Fixture
  float expected = -TRAVEL_DISTANCE;
  struct RangingDeckReadings readings = {500.0f, 500.0f, 100.0f, 500.0f};
  struct DroneMock droneValues = {0.0f, 0.0f, 0.0f, readings};
  struct DroneMock* drone = &droneValues;
  enum CfDir* direction;

  // Test
  avoidObstacles(readings, drone, direction);
  float actual = drone->posY;

  // Assert
  TEST_ASSERT_EQUAL_FLOAT(expected, actual);
  TEST_ASSERT_EQUAL_INT16(3, *direction);
}

void testThatavoidObstaclesAvoidsBackObstacles() {
  // Fixture
  float expected = TRAVEL_DISTANCE;
  struct RangingDeckReadings readings = {500.0f, 100.0f, 500.0f, 500.0f};
  struct DroneMock droneValues = {0.0f, 0.0f, 0.0f, readings};
  struct DroneMock* drone = &droneValues;
  int dir = 0;
  enum CfDir* direction = &dir;

  // Test
  avoidObstacles(readings, drone, direction);
  float actual = drone->posX;

  // Assert
  TEST_ASSERT_EQUAL_FLOAT(expected, actual);
  TEST_ASSERT_EQUAL_INT16(0, *direction);
}

void testThatavoidObstaclesAvoidsRightObstacles() {
  // Fixture
  float expected = TRAVEL_DISTANCE;
  struct RangingDeckReadings readings = {500.0f, 500.0f, 500.0f, 100.0f};
  struct DroneMock droneValues = {0.0f, 0.0f, 0.0f, readings};
  struct DroneMock* drone = &droneValues;
  enum CfDir* direction;

  // Test
  avoidObstacles(readings, drone, direction);
  float actual = drone->posY;

  // Assert
  TEST_ASSERT_EQUAL_FLOAT(expected, actual);
  TEST_ASSERT_EQUAL_INT16(2, *direction);
}

void testThatexploreChangesTheDirectionToLeftIfLeftDistanceIsHigherThanRight() {
  // Fixture
  int expected = 2;
  struct RangingDeckReadings readings = {500.0f, 500.0f, 600.0f, 500.0f};
  struct DroneMock droneValues = {0.0f, 0.0f, 0.0f, readings};
  struct DroneMock* drone = &droneValues;
  enum CfDir directionValue = FRONT;
  enum CfDir* direction = &directionValue;

  // Test
  explore(drone, 80, readings, direction);
  int actual = *direction;

  // Assert
  TEST_ASSERT_EQUAL_INT16(expected, actual);
}

void testThatexploreChangesTheDirectionToRightIfLeftDistanceIsLowerThanRight() {
  // Fixture
  int expected = 3;
  struct RangingDeckReadings readings = {500.0f, 500.0f, 400.0f, 500.0f};
  struct DroneMock droneValues = {0.0f, 0.0f, 0.0f, readings};
  struct DroneMock* drone = &droneValues;
  enum CfDir directionValue = BACK;
  enum CfDir* direction = &directionValue;

  // Test
  explore(drone, 80, readings, direction);
  int actual = *direction;

  // Assert
  TEST_ASSERT_EQUAL_INT16(expected, actual);
}

void testThatexploreChangesTheDirectionToFrontIfBackDistanceIsLowerThanFront() {
  // Fixture
  int expected = 0;
  struct RangingDeckReadings readings = {500.0f, 400.0f, 500.0f, 500.0f};
  struct DroneMock droneValues = {0.0f, 0.0f, 0.0f, readings};
  struct DroneMock* drone = &droneValues;
  enum CfDir directionValue = RIGHT;
  enum CfDir* direction = &directionValue;

  // Test
  explore(drone, 80, readings, direction);
  int actual = *direction;

  // Assert
  TEST_ASSERT_EQUAL_INT16(expected, actual);
}

void testThatexploreChangesTheDirectionToBackIfBackDistanceIsHigherThanFront() {
  // Fixture
  int expected = 1;
  struct RangingDeckReadings readings = {500.0f, 600.0f, 500.0f, 500.0f};
  struct DroneMock droneValues = {0.0f, 0.0f, 0.0f, readings};
  struct DroneMock* drone = &droneValues;
  enum CfDir directionValue = LEFT;
  enum CfDir* direction = &directionValue;

  // Test
  explore(drone, 80, readings, direction);
  int actual = *direction;

  // Assert
  TEST_ASSERT_EQUAL_INT16(expected, actual);
}

void testThatexploreDoesntChangeDirectionIfStepIsNotAMultipleOfDesiredInterval() {
  // Fixture
  int expected = 0;
  struct RangingDeckReadings readings = {500.0f, 500.0f, 500.0f, 500.0f};
  struct DroneMock droneValues = {0.0f, 0.0f, 0.0f, readings};
  struct DroneMock* drone = &droneValues;
  enum CfDir directionValue = FRONT;
  enum CfDir* direction = &directionValue;

  // Test
  explore(drone, 60, readings, direction);
  int actual = *direction;

  // Assert
  TEST_ASSERT_EQUAL_INT16(expected, actual);
}

void testThatgoToBaseSetsTheDirectionToBackIfBackDistanceIsHigherThanMinValue() {
  // Fixture
  int expected = 1;
  struct RangingDeckReadings readings = {400.0f, 600.0f, 400.0f, 400.0f};
  struct DroneMock droneValues = {0.0f, 0.0f, 0.0f, readings};
  struct DroneMock* drone = &droneValues;
  enum CfDir directionValue = FRONT;
  enum CfDir* direction = &directionValue;

  // Test
  goToBase(drone, readings, direction, 40.0f,0);
  int actual = *direction;

  // Assert
  TEST_ASSERT_EQUAL_INT16(expected, actual);
}

void testThatgoToBaseSetsTheDirectionToLeftIfLeftDistanceIsHigherThanMinValue() {
  // Fixture
  int expected = 2;
  struct RangingDeckReadings readings = {400.0f, 400.0f, 600.0f, 400.0f};
  struct DroneMock droneValues = {0.0f, 0.0f, 0.0f, readings};
  struct DroneMock* drone = &droneValues;
  enum CfDir directionValue = FRONT;
  enum CfDir* direction = &directionValue;

  // Test
  goToBase(drone, readings, direction, 40.0f,0);
  int actual = *direction;

  // Assert
  TEST_ASSERT_EQUAL_INT16(expected, actual);
}

void testThatgoToBaseSetsTheDirectionToRightIfLeftDistanceAndBackDistanceAreTooLow() {
  // Fixture
  int expected = 3;
  struct RangingDeckReadings readings = {400.0f, 400.0f, 400.0f, 400.0f};
  struct DroneMock droneValues = {0.0f, 0.0f, 0.0f, readings};
  struct DroneMock* drone = &droneValues;
  enum CfDir directionValue = FRONT;
  enum CfDir* direction = &directionValue;

  // Test
  goToBase(drone, readings, direction, 40.0f,0);
  int actual = *direction;

  // Assert
  TEST_ASSERT_EQUAL_INT16(expected, actual);
}

void testThatgoToBaseReturnsFalseIfRSSIValueIsLowAndDebounceIsLowerThanSix() {
  // Fixture
  bool expected = false;
  struct RangingDeckReadings readings = {400.0f, 400.0f, 400.0f, 400.0f};
  struct DroneMock droneValues = {0.0f, 0.0f, 0.0f, readings};
  struct DroneMock* drone = &droneValues;
  enum CfDir directionValue = FRONT;
  enum CfDir* direction = &directionValue;

  // Test
  bool actual = goToBase(drone, readings, direction, 35.0f,0);
  

  // Assert
  TEST_ASSERT_EQUAL_INT16(expected, actual);
}

void testThatgoToBaseReturnsTrueIfRSSIValueIsLowAndDebounceIsMoreThanFive() {
  // Fixture
  bool expected = true;
  struct RangingDeckReadings readings = {400.0f, 400.0f, 400.0f, 400.0f};
  struct DroneMock droneValues = {0.0f, 0.0f, 0.0f, readings};
  struct DroneMock* drone = &droneValues;
  enum CfDir directionValue = FRONT;
  enum CfDir* direction = &directionValue;

  // Test
  bool actual = goToBase(drone, readings, direction, 35.0f,6);
  

  // Assert
  TEST_ASSERT_EQUAL_INT16(expected, actual);
}