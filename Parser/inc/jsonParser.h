#ifndef JSONPARSER_H
#define JSONPARSER_H

#include "Iparser.h"
#include "json.h"
#include "IJsonLibrary.h"
#include <string>

class JsonParser : public IParser
{
private:
    nlohmann::json jsonData;
    IJsonLibrary *jsonLibrary;

public:
    JsonParser(IJsonLibrary *jsonLibrary);
    void parse(std::ifstream &jsonFile) override;
    void print() override;
};

#endif