#include <exception>
#include <limits>

#include "gtest/gtest.h"

#include "Calculator.h"

TEST(Calculator, AdditionTest) {
  Calculator calculator;
  EXPECT_EQ(calculator.plus(2, 3), 5);
  EXPECT_EQ(calculator.plus(2.1, 3.5), 5.6);
}

TEST(Calculator, MultiplyTest) {
  Calculator calculator;
  EXPECT_EQ(calculator.multiply(1, 1), 1.0);
  EXPECT_EQ(calculator.multiply(2, 3), 6);
  EXPECT_EQ(calculator.multiply(0, 1), 0);
}

TEST(Calculator, DivideTest) {
  Calculator calculator;
  EXPECT_EQ(calculator.divide(1, 2), 0.5);
  EXPECT_EQ(calculator.divide(4, 2), 2.0);
  // EXPECT_EQ(calculator.divide(4, 0), std::numeric_limits<double>::infinity());
  // EXPECT_EQ(calculator.divide(-4, 0), -std::numeric_limits<double>::infinity());

  // Expects some error to be thrown
  // EXPECT_ANY_THROW(calculator.divide(4, 0));
  EXPECT_THROW(calculator.divide(4, 0), std::exception);

  // Good practice to use EXPECT_THROW along with the specific class of exception
  EXPECT_THROW(calculator.divide(-4, 0), std::exception);


  EXPECT_NEAR(calculator.divide(1, 3), 0.33, 0.0034);
  // This would fail
  // EXPECT_NEAR(calculator.divide(1, 3), 0.4, 0.01);
}
