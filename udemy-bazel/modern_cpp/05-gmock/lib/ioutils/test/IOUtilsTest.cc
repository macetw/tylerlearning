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
using ::testing::_;

TEST(IOUtils, CaseInsensitiveRegexSearch)
{
  NiceMock<MockIOUtils> mockIOUtils;
  vector<string> fileList {
    "REJECT",
    "ACCEPT1",
    "accept2" };
  
  string path("BasePath");
  string pattern(".*cc.*");
  // To be called exactly once. 0 or > 1 call will lead to test failure.
  EXPECT_CALL(mockIOUtils, getFiles(_))
  .WillOnce(Return(fileList));

  // Needed when IOUtils::list method is private.
  ON_CALL(mockIOUtils, list(path, pattern))
  .WillByDefault(Invoke(&mockIOUtils, &MockIOUtils::delegatingList));

  vector<string> expected { "ACCEPT1", "accept2" };
  EXPECT_EQ(mockIOUtils.list(path, pattern), expected);
}

TEST(IOUtils, CaseInsensitiveRegexSearchBetter)
{
  NiceMock<MockIOUtils> mockIOUtils;
  vector<string> fileList {
    "REJECT",
    "ACCEPT1",
    "accept2" };
  
  string path("BasePath");
  string pattern(".*cc.*");

  EXPECT_CALL(mockIOUtils, getFiles(path))
  .Times(2)
  .WillRepeatedly(Return(fileList));

  ON_CALL(mockIOUtils, list(path, pattern))
  .WillByDefault(Invoke(&mockIOUtils, &MockIOUtils::delegatingList));

  // using Matchers EXPECT_THAT(Actual, Mather)
  // Ordering matters when using ElementsAre
  EXPECT_THAT(mockIOUtils.list(path, pattern), ElementsAre("ACCEPT1", "accept2"));

  // Ordering doesn't matter when using UnorderedElementsAre
  EXPECT_THAT(mockIOUtils.list(path, pattern), UnorderedElementsAre("accept2", "ACCEPT1"));
}

TEST(IOUtils, ListRegexes)
{
  NiceMock<MockIOUtils> mockIOUtils;
  ON_CALL(mockIOUtils, list)
  .WillByDefault(Invoke(&mockIOUtils, &MockIOUtils::delegatingList));
  
  vector<string> fileList1 { "PATH0", "PATH1", "PATH2", "PATH3", "PATH4" };
  string path1("BasePath1");
  EXPECT_CALL(mockIOUtils, getFiles(path1))
  .WillRepeatedly(Return(fileList1));

  vector<string> fileList2 { "BIGGER_PATH1", "NONEMPTY_PATH2" };
  string path2("BasePath2");
  EXPECT_CALL(mockIOUtils, getFiles(path2))
  .WillRepeatedly(Return(fileList2));

  string pattern1(".*path[1-3]");
  EXPECT_THAT(mockIOUtils.list(path1, pattern1), UnorderedElementsAre("PATH3", "PATH1", "PATH2"));

  string pattern2(".*at.*4");
  EXPECT_THAT(mockIOUtils.list(path1, pattern2), UnorderedElementsAre("PATH4"));

  string pattern3("");
  EXPECT_THAT(mockIOUtils.list(path2, pattern3), UnorderedElementsAre("NONEMPTY_PATH2", "BIGGER_PATH1"));
}
