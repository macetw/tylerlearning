#pragma once

#include "gmock/gmock.h"

#include <string>
#include <vector>

#include "ioutils/IOUtils.h"

class MockIOUtils : public IOUtils
{
public:
  MOCK_METHOD((std::vector<std::string>), getFiles, (std::string&), (override));

  // Need this since IOUtils::getFiles is private
  MOCK_METHOD((std::vector<std::string>), list, (std::string&, std::string&), (override));

  MOCK_METHOD((std::string), tempDirectoryPath, (const char*), (const, override));

  std::vector<std::string>
  delegatingList(std::string baseDir, std::string filter)
  {
    return IOUtils::list(baseDir, filter);
  }
};
