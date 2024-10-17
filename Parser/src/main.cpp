#include "parserFactory.h"
#include "utils.h"
#include <iostream>
#include <fstream>
#include <string>
#include <gtest/gtest.h>

int main(int argc, char *argv[])
{
    std::string filePath;

    if (validateCmdArgument(argc))
    {
        filePath = argv[1];

        if (!fileExists(filePath))
        {
            std::cout << "Error :File doesnot exist: " << filePath << '\n';
        }
        else
        {
            std::string fileType = getFileExtension(filePath);

            try
            {
                IParser *parser = ParserFactory::createParser(fileType);
                std::ifstream file=openFile(filePath);
                parser->parse(file);
                parser->print();
                delete parser;
            }
            catch (std::exception &exception)
            {
                std::cout << "Error: " << exception.what() << '\n';
            }
        }
    }

    return 0;
}
