#include "ioutils/IOUtils.h"

#include<filesystem>
#include <iostream>
#include <regex>

using std::vector;
using std::string;
using std::cout;

IOUtils::~IOUtils() {}

vector<string>
IOUtils::getFiles(string& baseDir)
{
    auto results = vector<string>();
    for(auto dirEntry : std::filesystem::recursive_directory_iterator(baseDir)) {
        results.push_back(dirEntry.path().string());
    }
    return results;
}

vector<string>
IOUtils::list(string& baseDir,
         string& filter)
{
    auto results = vector<string>();
    std::regex pattern(filter, std::regex_constants::icase);
    for (auto fileName : getFiles(baseDir)) {
        if (std::regex_search(fileName, pattern)) {
            results.push_back(fileName);
        }
    }
    return results;
}

std::string
IOUtils::tempDirectoryPath(const char* platform) const
{
    return std::filesystem::temp_directory_path();
}
