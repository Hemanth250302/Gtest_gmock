#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "IXmlLibrary.h"
#include "xmlParser.h"
#include "mockXmlLibrary.h"
#include <fstream>

class GivenATestingXmlParserTest : public testing::Test
{
protected:
    MockXmlLibrary mockXmlLibrary;
    XmlParser *xmlParser;

    void SetUp() override
    {
        xmlParser = new XmlParser(&mockXmlLibrary);
    }

    void TearDown() override
    {
        delete xmlParser;
    }
};

using testing::Return;
using testing::Throw;

TEST_F(GivenATestingXmlParserTest, WhenParseFunctionIsCalledWithValidXmlFile_ThenItSholudNotThrowError)
{
    std::ifstream xmlFile("build/sampleFiles/sample.xml");
    pugi::xml_parse_result parseResult;
    parseResult.status = pugi::status_ok;

    EXPECT_CALL(mockXmlLibrary, parse(testing::_))
        .WillOnce(Return(parseResult));

    EXPECT_NO_THROW(xmlParser->parse(xmlFile));
}

TEST_F(GivenATestingXmlParserTest, WhenParseFunctionIsCalledWithInvalidXmlFile_ThenItSholudNotThrowError)
{
    std::ifstream xmlFile("build/InvalidFiles/invalid.xml");

    EXPECT_CALL(mockXmlLibrary, parse(::testing::_))
        .WillOnce(Throw(std::runtime_error("Parse error")));

    EXPECT_THROW(xmlParser->parse(xmlFile), std::runtime_error);
}