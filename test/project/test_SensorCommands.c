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
  float  expected = 5.0f;

  // Test
  float actual = getSpeed();

  // Assert
  TEST_ASSERT_EQUAL_FLOAT(expected, actual);
}

