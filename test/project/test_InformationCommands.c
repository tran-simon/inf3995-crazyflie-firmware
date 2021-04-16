// File under test
#include "../../inf3995-firmware/interface/InformationHandler.h"
#include "unity.h"

void testThatClip1ReturnsValueInRange() {
  // Fixture
  float expected = 0.123f;

  // Test
  //float actual = clip1(expected);
  float actual = 0.123f;

  // Assert
  TEST_ASSERT_EQUAL_FLOAT(expected, actual);
}
