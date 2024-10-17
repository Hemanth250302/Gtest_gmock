#include <gmock/gmock.h>
#include "ICsvLibrary.h"

class MockCsvLibrary : public ICsvLibrary
{
public:
    MOCK_METHOD(rapidcsv::Document, parse, (std::ifstream & csvFile), (override));
};