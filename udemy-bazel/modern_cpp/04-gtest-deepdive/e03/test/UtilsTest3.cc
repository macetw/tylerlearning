#include "Utils.h"

#include <gtest/gtest.h>

#include <cassert>
#include <tuple>

using ::testing::tuple;
using ::testing::Values;
using ::testing::Range;
using ::testing::internal::ParamGenerator;
using ::testing::TestWithParam;

// Using factory to generate data. This is useful when removing legacy code
class OldCode
{
public:
    // legacy code.
    int
    SumFrom1To(int n)
    {
        assert(n > 0);
        int sum = 0;
        for ( ; n > -1; --n) {
            sum += n;
        }
        return sum;
    }
    const ParamGenerator<int> testData = Range(1, 30);
};

typedef OldCode *FactoryFunction();

OldCode *OldCodeFactory() {
    return new OldCode;
}

class FactoryParameterizedTest : public TestWithParam<FactoryFunction *> {
protected:
    void SetUp() override
    {
        oldCode = (*GetParam())();
    }

    void TearDown() override
    {
        delete oldCode;
        oldCode = nullptr;
    }
    OldCode *oldCode;
};

// Separating data and test code.
TEST_P(FactoryParameterizedTest, CheckingAgainstOldCode) {
    const ParamGenerator<int> &params = oldCode->testData;
    for (auto it = params.begin(); it != params.end(); ++it) {
        EXPECT_EQ(SumFrom1To(*it), oldCode->SumFrom1To(*it));
    }
}

INSTANTIATE_TEST_SUITE_P(ExternalData,
                        FactoryParameterizedTest,
                        Values(&OldCodeFactory));
