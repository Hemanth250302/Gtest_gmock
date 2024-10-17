#ifndef IJsonLibrary_H
#define IJsonLibrary_H

#include "json.h"

class IJsonLibrary
{

public:
     virtual ~IJsonLibrary() = default;
     virtual nlohmann::json parse(std::ifstream &jsonFile) = 0;
};

#endif