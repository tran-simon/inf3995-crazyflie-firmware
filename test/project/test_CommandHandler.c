#include "CommandHandlerMock.h"
#include "unity.h"


void testThatactivateCommandReturnsRightTypeIfCommandIst() {
  // Fixture
  struct Information expected = {1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 't'};

  // Test
  struct Information actual = activateCommand('t', false);

  // Assert
  TEST_ASSERT_EQUAL_FLOAT(expected.value1, actual.value1);
  TEST_ASSERT_EQUAL_FLOAT(expected.value2, actual.value2);
  TEST_ASSERT_EQUAL_FLOAT(expected.value3, actual.value3);
  TEST_ASSERT_EQUAL_FLOAT(expected.value4, actual.value4);
  TEST_ASSERT_EQUAL_FLOAT(expected.value5, actual.value5);
  TEST_ASSERT_EQUAL_FLOAT(expected.value6, actual.value6);
  TEST_ASSERT_EQUAL_UINT16((uint16_t)expected.type, (uint16_t)actual.type);
}

void testThatactivateCommandReturnsRightTypeIfCommandIse() {
  // Fixture
  struct Information expected = {1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 't'};

  // Test
  struct Information actual = activateCommand('e', false);

  // Assert
  TEST_ASSERT_EQUAL_FLOAT(expected.value1, actual.value1);
  TEST_ASSERT_EQUAL_FLOAT(expected.value2, actual.value2);
  TEST_ASSERT_EQUAL_FLOAT(expected.value3, actual.value3);
  TEST_ASSERT_EQUAL_FLOAT(expected.value4, actual.value4);
  TEST_ASSERT_EQUAL_FLOAT(expected.value5, actual.value5);
  TEST_ASSERT_EQUAL_FLOAT(expected.value6, actual.value6);
  TEST_ASSERT_EQUAL_UINT16((uint16_t)expected.type, (uint16_t)actual.type);
}

void testThatactivateCommandReturnsRightTypeIfCommandIsl() {
  // Fixture
  struct Information expected = {1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 'l'};

  // Test
  struct Information actual = activateCommand('l', false);

  // Assert
  TEST_ASSERT_EQUAL_FLOAT(expected.value1, actual.value1);
  TEST_ASSERT_EQUAL_FLOAT(expected.value2, actual.value2);
  TEST_ASSERT_EQUAL_FLOAT(expected.value3, actual.value3);
  TEST_ASSERT_EQUAL_FLOAT(expected.value4, actual.value4);
  TEST_ASSERT_EQUAL_FLOAT(expected.value5, actual.value5);
  TEST_ASSERT_EQUAL_FLOAT(expected.value6, actual.value6);
  TEST_ASSERT_EQUAL_UINT16((uint16_t)expected.type, (uint16_t)actual.type);
}

void testThatactivateCommandReturnsRightTypeIfCommandIsrWithReturnToBase() {
  // Fixture
  struct Information expected = {1, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 'r'};

  // Test
  struct Information actual = activateCommand('r', true);

  // Assert
  TEST_ASSERT_EQUAL_FLOAT(expected.value1, actual.value1);
  TEST_ASSERT_EQUAL_FLOAT(expected.value2, actual.value2);
  TEST_ASSERT_EQUAL_FLOAT(expected.value3, actual.value3);
  TEST_ASSERT_EQUAL_FLOAT(expected.value4, actual.value4);
  TEST_ASSERT_EQUAL_FLOAT(expected.value5, actual.value5);
  TEST_ASSERT_EQUAL_FLOAT(expected.value6, actual.value6);
  TEST_ASSERT_EQUAL_UINT16((uint16_t)expected.type, (uint16_t)actual.type);
}

void testThatactivateCommandReturnsRightTypeIfCommandIsrWithNoReturnToBase() {
  // Fixture
  struct Information expected = {0, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 'r'};

  // Test
  struct Information actual = activateCommand('r', false);

  // Assert
  TEST_ASSERT_EQUAL_FLOAT(expected.value1, actual.value1);
  TEST_ASSERT_EQUAL_FLOAT(expected.value2, actual.value2);
  TEST_ASSERT_EQUAL_FLOAT(expected.value3, actual.value3);
  TEST_ASSERT_EQUAL_FLOAT(expected.value4, actual.value4);
  TEST_ASSERT_EQUAL_FLOAT(expected.value5, actual.value5);
  TEST_ASSERT_EQUAL_FLOAT(expected.value6, actual.value6);
  TEST_ASSERT_EQUAL_UINT16((uint16_t)expected.type, (uint16_t)actual.type);
}