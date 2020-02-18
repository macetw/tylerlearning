#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include "MockIOUtils.h"

#include <string>
#include <vector>

using std::string;
using std::vector;
using ::testing::Return;
using ::testing::Invoke;
using ::testing::ElementsAre;
using ::testing::UnorderedElementsAre;
using ::testing::NiceMock;
using ::testing::StrictMock;

TEST(CallStudy, CallReturnsWithoutExpectCall) {
    NiceMock<MockIOUtils> mockIOUtils;
    // When no expect setup is there, default return value is provided by the framework.
    EXPECT_EQ("", mockIOUtils.tempDirectoryPath(nullptr));

    vector<string> expected;
    string doesNotMatter("");
    EXPECT_EQ(mockIOUtils.list(doesNotMatter, doesNotMatter), expected);
}

TEST(CallStudy, CallReturnCount) {
    StrictMock<MockIOUtils> mockIOUtils;
    EXPECT_CALL(mockIOUtils, tempDirectoryPath("random"))
    .WillOnce(Return("Invalid platform. How about linux?"))
    .WillOnce(Return("Linux it is."))
    .WillRepeatedly(Return("Great news. You don't have to run this test again. You're fired!"));

    EXPECT_EQ(mockIOUtils.tempDirectoryPath("random"),
    "Invalid platform. How about linux?");
    EXPECT_EQ(mockIOUtils.tempDirectoryPath("random"), 
     "Linux it is.");
    for (int i = 0; i < 10; ++i) {
        EXPECT_EQ(mockIOUtils.tempDirectoryPath("random"),
        "Great news. You don't have to run this test again. You're fired!");
    }
}

TEST(CallStudy, RetiresOnSaturation) {
    StrictMock<MockIOUtils> mockIOUtils;
    // ordering should be in reverse
    for (int i = 2; i >= 0; --i) {
        string msg;
        if (i == 0) {
            msg = "1st message";
        } else if (i == 1) {
            msg = "2nd message";
        } else if (i == 2) {
            msg = "3rd message";
        }
        EXPECT_CALL(mockIOUtils, tempDirectoryPath("random"))
        .WillOnce(Return(msg))
        .RetiresOnSaturation();
    }
    EXPECT_EQ(mockIOUtils.tempDirectoryPath("random"), "1st message");
    EXPECT_EQ(mockIOUtils.tempDirectoryPath("random"), "2nd message");
    EXPECT_EQ(mockIOUtils.tempDirectoryPath("random"), "3rd message");
}
