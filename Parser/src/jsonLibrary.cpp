
#include "jsonLibrary.h"
#include <fstream>

nlohmann::json JsonLibrary::parse(std::ifstream &jsonFile)
{
    nlohmann::json jsonData;
    jsonFile >> jsonData;
    return jsonData;
}
