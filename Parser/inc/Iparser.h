#ifndef IPARSER_H
#define IPARSER_H

#include <string>

class IParser
{
public:
   // virtual std::ifstream openFile(const std::string &filePath) = 0;
    virtual void parse(std::ifstream &fileIn) = 0;
    virtual void print() = 0;
    virtual ~IParser() = default;
};

#endif