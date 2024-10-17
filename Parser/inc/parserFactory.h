#ifndef PARSERFACTORY_H
#define PARSERFACTORY_H

#include "Iparser.h"
#include <string>

class ParserFactory
{
public:
    static IParser *createParser(const std::string &fileType);
};

#endif
