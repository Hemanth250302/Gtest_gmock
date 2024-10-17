#include <gtest/gtest.h>
#include <fstream>
#include "utils.h"

TEST(GivenATestingGetFileExtension, WhenAGetFileExtentionFunctionCalledWithFilePath_thenItShouldReturnFileExtensionIfExists)
{
    std::string filePath = "testFile.csv";
    EXPECT_EQ("csv", getFileExtension(filePath));

    filePath = "testFile";
    EXPECT_EQ("", getFileExtension(filePath));
}

TEST(GivenATestingValidateCmdArgument, WhenAValidateCmdArgumentFunctionCalledWithNoOfArguments_thenItShouldReturnTrueIfNoOfArgumentsIs2)
{
    EXPECT_TRUE(validateCmdArgument(2));

    EXPECT_FALSE(validateCmdArgument(1));

    EXPECT_FALSE(validateCmdArgument(3));
}

TEST(GivenATestingFFileExists, WhenAFileExistsFunctionIsCalledWithValidFile_ThenItShouldReturnTrue)
{

    EXPECT_TRUE(fileExists("build/sampleFiles/sample.csv"));
}

TEST(GivenATestingFFileExists, WhenAFileExistsFunctionIsCalledWithInvalidFile_ThenItShouldReturnFalse)
{

    EXPECT_FALSE(fileExists("testInvalidFile.txt"));
}
