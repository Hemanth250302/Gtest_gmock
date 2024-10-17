#include <gmock/gmock.h>
#include "IJsonLibrary.h"

class MockJsonLibrary : public IJsonLibrary
{
public:
    MOCK_METHOD(nlohmann::json, parse, (std::ifstream &), (override));
};