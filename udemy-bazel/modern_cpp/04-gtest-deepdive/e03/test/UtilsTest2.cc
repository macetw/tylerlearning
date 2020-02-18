#include "Utils.h"

#include <gtest/gtest.h>

#include <tuple>

using ::testing::tuple;
using ::testing::Values;
using ::testing::internal::ParamGenerator;
using ::testing::TestWithParam;

class From1ToNParameterizedTest : public TestWithParam<tuple<int, int>> {};

// Separating data and test code.
TEST_P(From1ToNParameterizedTest, ValuesInParams) {
    const tuple<int, int> params = GetParam();
    EXPECT_EQ(SumFrom1To(std::get<1>(params)), std::get<0>(params));
}

INSTANTIATE_TEST_SUITE_P(ExternalData,
                        From1ToNParameterizedTest,
                        Values(
                            std::make_tuple(1, 1),
                            std::make_tuple(15, 5),
                            std::make_tuple(21, 6)
                        ));
