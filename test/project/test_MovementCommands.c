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