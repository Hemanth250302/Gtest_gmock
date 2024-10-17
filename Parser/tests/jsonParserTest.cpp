#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <fstream>
#include "jsonParser.h"
#include <json.h>
#include "IJsonLibrary.h"
#include "mockJsonLibrary.h"

using ::testing::Return;
using ::testing::Throw;

class GivenATestingJsonParser : public ::testing::Test
{
protected:
    MockJsonLibrary mockJsonLibrary;
    JsonParser *jsonParser;

    void SetUp() override
    {
        jsonParser = new JsonParser(&mockJsonLibrary);
    }

    void TearDown() override
    {
        delete jsonParser;
    }
};

TEST_F(GivenATestingJsonParser, WhenParseFunctionIsCalledWithValidJsonFile_ThenItSholudNotThrowError)
{
    std::ifstream jsonFile("build/sampleFiles/sample.json");

    nlohmann::json jsonData;

    EXPECT_CALL(mockJsonLibrary, parse(::testing::_))
        .WillOnce(Return(jsonData));

    EXPECT_NO_THROW(jsonParser->parse(jsonFile));
}

TEST_F(GivenATestingJsonParser, WhenParseFunctionIsCalledWithInvalidCsvFile_ThenItSholudThrowError)
{
    std::ifstream JsonFile("build/InvalidFiles/invalid.json");

    EXPECT_CALL(mockJsonLibrary, parse(::testing::_))
        .WillOnce(Throw(std::runtime_error("Parse error")));

    EXPECT_THROW(jsonParser->parse(JsonFile), std::runtime_error);
}
