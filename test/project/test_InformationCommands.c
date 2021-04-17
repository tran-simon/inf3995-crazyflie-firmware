// File under test
#include "InformationHandlerMock.h"
#include "SensorCommandsMock.h"
#include "unity.h"

void testThatgetStatsReturnsTheBatteryIfCommandIsb() {
  // Fixture
  struct Information expected = {BATTERY, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 'b'};

  // Test
  struct Information actual = getStats('b');

  // Assert
  TEST_ASSERT_EQUAL_FLOAT(expected.value1, actual.value1);
  TEST_ASSERT_EQUAL_FLOAT(expected.value2, actual.value2);
  TEST_ASSERT_EQUAL_FLOAT(expected.value3, actual.value3);
  TEST_ASSERT_EQUAL_FLOAT(expected.value4, actual.value4);
  TEST_ASSERT_EQUAL_FLOAT(expected.value5, actual.value5);
  TEST_ASSERT_EQUAL_FLOAT(expected.value6, actual.value6);
  TEST_ASSERT_EQUAL_UINT16((uint16_t)expected.type, (uint16_t)actual.type);
}

void testThatgetStatsReturnsTheSpeedIfCommandIsv() {
  // Fixture
  struct Information expected = {5.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 'v'};

  // Test
  struct Information actual = getStats('v');

  // Assert
  TEST_ASSERT_EQUAL_FLOAT(expected.value1, actual.value1);
  TEST_ASSERT_EQUAL_FLOAT(expected.value2, actual.value2);
  TEST_ASSERT_EQUAL_FLOAT(expected.value3, actual.value3);
  TEST_ASSERT_EQUAL_FLOAT(expected.value4, actual.value4);
  TEST_ASSERT_EQUAL_FLOAT(expected.value5, actual.value5);
  TEST_ASSERT_EQUAL_FLOAT(expected.value6, actual.value6);
  TEST_ASSERT_EQUAL_UINT16((uint16_t)expected.type, (uint16_t)actual.type);
}

void testThatgetStatsReturnsTheStateIfCommandIss() {
  // Fixture
  struct Information expected = {1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 's'};

  // Test
  struct Information actual = getStats('s');

  // Assert
  TEST_ASSERT_EQUAL_FLOAT(expected.value1, actual.value1);
  TEST_ASSERT_EQUAL_FLOAT(expected.value2, actual.value2);
  TEST_ASSERT_EQUAL_FLOAT(expected.value3, actual.value3);
  TEST_ASSERT_EQUAL_FLOAT(expected.value4, actual.value4);
  TEST_ASSERT_EQUAL_FLOAT(expected.value5, actual.value5);
  TEST_ASSERT_EQUAL_FLOAT(expected.value6, actual.value6);
  TEST_ASSERT_EQUAL_UINT16((uint16_t)expected.type, (uint16_t)actual.type);
}

void testThatgetStatsReturnsThePointsIfCommandIsm() {
  // Fixture
  struct Information expected = {POS_X, POS_Y, FRONT_SENSOR_VALUE, BACK_SENSOR_VALUE, LEFT_SENSOR_VALUE, RIGHT_SENSOR_VALUE, 'm'};

  // Test
  struct Information actual = getStats('m');

  // Assert
  TEST_ASSERT_EQUAL_FLOAT(expected.value1, actual.value1);
  TEST_ASSERT_EQUAL_FLOAT(expected.value2, actual.value2);
  TEST_ASSERT_EQUAL_FLOAT(expected.value3, actual.value3);
  TEST_ASSERT_EQUAL_FLOAT(expected.value4, actual.value4);
  TEST_ASSERT_EQUAL_FLOAT(expected.value5, actual.value5);
  TEST_ASSERT_EQUAL_FLOAT(expected.value6, actual.value6);
  TEST_ASSERT_EQUAL_UINT16((uint16_t)expected.type, (uint16_t)actual.type);
}
