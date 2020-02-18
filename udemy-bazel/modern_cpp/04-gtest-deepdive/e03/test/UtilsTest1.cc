#include "Utils.h"

#include <gtest/gtest.h>

#include <tuple>
#include <vector>

using ::testing::tuple;
using ::testing::Bool;
using ::testing::Combine;
using ::testing::Range;
using ::testing::Values;
using ::testing::ValuesIn;
using ::testing::internal::ParamGenerator;

TEST(SumFrom1To, RangeParams) {
    // Range(begin, end [, step]) : Step is 1 by default
    // Range of values included : [start, end)
    const ParamGenerator<int> params = Range(1, 5);
    const int expectedSums[] = {1, 3, 6, 10};
    int offset = 0;
    for (auto it = params.begin(); it != params.end(); ++it, ++offset) {
        EXPECT_EQ(SumFrom1To(*it), expectedSums[offset]);
    }
}

TEST(SumFrom1To, ValuesParams) {
    // passing in var-args
    const ParamGenerator<int> params = Values(1, 5, 3, 7);
    const int expectedSums[] = {1, 15, 6, 28};
    int offset = 0;
    for (auto it = params.begin(); it != params.end(); ++it, ++offset) {
        EXPECT_EQ(SumFrom1To(*it), expectedSums[offset]);
    }
}

TEST(SumFrom1To, ValuesInParams) {
    const std::vector<int> inputs = {1, 5, 3, 7};
    // passing in a container / array
    // Can also specify interation range : ValuesIn(inputs.begin(), inputs.end() - 2);
    const ParamGenerator<int> params = ValuesIn(inputs);
    const int expectedSums[] = {1, 15, 6, 28};
    int offset = 0;
    for (auto it = params.begin(); it != params.end(); ++it, ++offset) {
        EXPECT_EQ(SumFrom1To(*it), expectedSums[offset]);
    }
}

TEST(Negate, BoolData) {
    const ParamGenerator<bool> params = Bool();
    for (auto it = params.begin(); it != params.end(); ++it) {
        EXPECT_EQ(Negate(*it), ! *it);
    }
}

TEST(CheckEvenOdd, CombineData) {
    // Following data is produced.
    // true, 1
    // false, 1
    // true, 2
    // false, 2
    // ...
    // true 4
    // false 4
    const ParamGenerator<tuple<bool, int>> params = Combine(Bool(), Range(1, 5));
    for (auto it = params.begin(); it != params.end(); ++it) {
        const tuple<bool, int> &pair = *it;
        bool checkEven = std::get<0>(pair);
        int data = std::get<1>(pair);
        bool result = CheckEvenOdd(checkEven, data);
        if (checkEven) {
            EXPECT_EQ(result, data % 2 == 0);
        } else {
            EXPECT_NE(result, data % 2 == 0);
        }
    }
}
