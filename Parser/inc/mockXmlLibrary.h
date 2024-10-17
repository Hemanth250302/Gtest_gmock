#include <gmock/gmock.h>
#include "IXmlLibrary.h"

class MockXmlLibrary : public IXmlLibrary
{
public:
    MOCK_METHOD(pugi::xml_parse_result, parse, (std::ifstream &), (override));
};
