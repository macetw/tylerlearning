#pragma once

#include<string>
#include<vector>

class IOUtils
{
    virtual std::vector<std::string>
    getFiles(std::string& baseDir);

public:

    virtual ~IOUtils();

    virtual std::vector<std::string>
    list(std::string& baseDir,
         std::string& filter);

    virtual std::string
    tempDirectoryPath(const char* platform) const;
};
