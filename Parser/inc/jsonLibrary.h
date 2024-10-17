#ifndef JSONLIBRARY_H
#define JSONLIBRARY_H

#include "json.h"
#include "IJsonLibrary.h"

class JsonLibrary : public IJsonLibrary
{

public:
    nlohmann::json parse(std::ifstream &jsonFile) override;
};

#endif