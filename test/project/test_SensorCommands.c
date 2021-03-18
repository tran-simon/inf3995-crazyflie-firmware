// File under test
#include "unity.h"
#include "../testSupport/SensorCommandsMock.h"

static struct sensors_data sensorsValues = {200.0f, 1000.0f, 1000.0f, 1000.0f, 40.0f, 80.0f};

void setUp(void) {

}

void testThatGetLeftDistanceReturnsTheLeftSensorValue() {
   // Fixture
  float  expected = sensorsValues.leftSensor;

  // Test
  float actual = getLeftDistance();

  // Assert
  TEST_ASSERT_EQUAL_FLOAT(expected, actual);
}

void testThatGetRightDistanceReturnsTheRightSensorValue() {
   // Fixture
  float  expected = sensorsValues.rightSensor;

  // Test
  float actual = getRightDistance();

  // Assert
  TEST_ASSERT_EQUAL_FLOAT(expected, actual);
}

void testThatGetFrontDistanceReturnsTheFrontSensorValue() {
   // Fixture
  float  expected = sensorsValues.frontSensor;

  // Test
  float actual = getFrontDistance();

  // Assert
  TEST_ASSERT_EQUAL_FLOAT(expected, actual);
}

void testThatGetBackDistanceReturnsTheBackSensorValue() {
   // Fixture
  float  expected = sensorsValues.backSensor;

  // Test
  float actual = getBackDistance();

  // Assert
  TEST_ASSERT_EQUAL_FLOAT(expected, actual);
}

void testThatGetBatteryReturnsTheBatteryValue() {
   // Fixture
  float  expected = sensorsValues.battery;

  // Test
  float actual = getBattery();

  // Assert
  TEST_ASSERT_EQUAL_FLOAT(expected, actual);
}

void testThatGetRSSIReturnsTheRSSISignalValue() {
   // Fixture
  float  expected = sensorsValues.RSSI;

  // Test
  float actual = getRSSI();

  // Assert
  TEST_ASSERT_EQUAL_FLOAT(expected, actual);
}

void testThatGetSpeedReturnsTheValidComputedSpeed() {
   // Fixture
  float  expected = 3.0f;
  state_t state;
  state.velocity.timestamp = 0;
  state.velocity.x = 2.0f;
  state.velocity.y = 2.0f;
  state.velocity.z = 1.0f;

  // Test
  float actual = getSpeed(state);

  // Assert
  TEST_ASSERT_EQUAL_FLOAT(expected, actual);
}

void testThatGetPointReturnsThePointInFrontOfTheDrone() {
   // Fixture
  point_t point;
  point.timestamp = 0;
  point.x = 10.0f + sensorsValues.frontSensor;
  point.y = 2.0f;
  point.z = 2.0f;
  vec3d expected = {point.x, point.y, point.z};

  state_t state;
  state.velocity.timestamp = 0;
  state.position.x = 10.0f;
  state.position.y = 2.0f;
  state.position.z = 2.0f;

  // Test
  point_t actualPoint = getPoint(state);
  vec3d actual = {actualPoint.x, actualPoint.y, actualPoint.z};


  // Assert
  TEST_ASSERT_EQUAL_FLOAT_ARRAY(expected, actual, vec3d_size);
}
