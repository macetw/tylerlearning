#include "Utils.h"

#include<iostream>

#include <gtest/gtest.h>

TEST(SumFrom1To, Simple) {
    EXPECT_EQ(SumFrom1To(1), 1);
    EXPECT_EQ(21, SumFrom1To(6));
}

TEST(SumFrom1To, InvalidInputs) {
    EXPECT_DEATH(SumFrom1To(-1), "Assertion .* failed.");
    EXPECT_DEATH(SumFrom1To(0), "Assertion .* failed.");
}
