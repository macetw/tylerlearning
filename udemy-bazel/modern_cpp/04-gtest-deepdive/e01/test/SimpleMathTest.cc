#include <limits>

#include "gtest/gtest.h"

#include "SimpleMath.h"

TEST(SimpleMath, FactorialOneOutput) {
  SimpleMath simpleMath;
  EXPECT_EQ(simpleMath.Factorial(0), 1);
  EXPECT_EQ(simpleMath.Factorial(1), 1);
}

TEST(SimpleMath, FactorialOthers) {
  SimpleMath simpleMath;
  EXPECT_EQ(simpleMath.Factorial(2), 2);
  EXPECT_EQ(simpleMath.Factorial(3), 6);
  EXPECT_EQ(simpleMath.Factorial(4), 24);
}

TEST(SimpleMath, InvalidInputs) {
  SimpleMath simpleMath;
  EXPECT_DEATH(simpleMath.Factorial(-1), "Assertion .* failed.");
}
