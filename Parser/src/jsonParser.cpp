#include "jsonParser.h"
#include <iostream>
#include <fstream>
#include <stdexcept>

JsonParser::JsonParser(IJsonLibrary *jsonLibrary) : jsonLibrary(jsonLibrary) {}

void JsonParser::parse(std::ifstream &jsonFile)
{
    try
    {
      jsonData = jsonLibrary->parse(jsonFile);
    }
    catch (const std::exception &exception)
    {
        std::cout << " Error while parsing jsonFile: ";
        throw;
    }
}

void JsonParser::print()
{
    std::cout << "JSON file Contents:\n\n";
    for (const nlohmann::json &employee : jsonData["employees"])
    {
        std::cout << "Name: " << employee["name"] << "\n";
        std::cout << "Age: " << employee["age"] << "\n";
        std::cout << "Occupation: " << employee["occupation"] << "\n";
        std::cout << "Salary: $" << employee["salary"] << "\n";
        std::cout << '\n' << '\n';
    }
}
