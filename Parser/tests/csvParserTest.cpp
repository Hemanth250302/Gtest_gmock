#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "csvParser.h"
#include "ICsvLibrary.h"
#include "mockCsvLibrary.h"

using testing::_;
using testing::Return;
using testing::Throw;

class GivenATestingCsvParser : public testing::Test
{
protected:
    MockCsvLibrary mockLibrary;
    CsvParser *csvParser;

    void SetUp() override
    {
        csvParser = new CsvParser(&mockLibrary);
    }

    void TearDown() override
    {
        delete csvParser;
    }
};

// When...Than....
TEST_F(GivenATestingCsvParser, WhenParseFunctionIsCalledWithValidCsvFile_ThenItSholudNotThrowError)
{
    std::ifstream csvFile("build/sampleFiles/sample.csv");

    EXPECT_CALL(mockLibrary, parse(_))
        .WillOnce(Return(rapidcsv::Document()));

    EXPECT_NO_THROW(csvParser->parse(csvFile));
}

TEST_F(GivenATestingCsvParser, WhenParseFunctionIsCalledWithInvalidCsvFile_ThenItSholudThrowError)
{
    std::ifstream csvFile("build/InvalidFiles/invalid.csv");

    EXPECT_CALL(mockLibrary, parse(_))
        .WillOnce(Throw(std::runtime_error("Parse error")));

    EXPECT_THROW(csvParser->parse(csvFile), std::exception);
}
