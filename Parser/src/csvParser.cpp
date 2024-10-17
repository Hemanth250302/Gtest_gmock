#include "csvParser.h"
#include <iostream>
#include <stdexcept>

CsvParser::CsvParser(ICsvLibrary *csvLibrary) : csvLibrary(csvLibrary) {}

void CsvParser::parse(std::ifstream &csvFile)
{
    try
    {
        csvData = csvLibrary->parse(csvFile);
    }
    catch (const std::exception &exception)
    {
        std::cout << "Error while parsing CSV file:" << exception.what();
        throw;
    }
}

void CsvParser::print()
{
    std::cout << "CSV File Contents:\n";
    int rows = csvData.GetRowCount();
    int cols = csvData.GetColumnCount();
    
        for (int row = 0; row < rows; row++)
        {
            for (int col = 0; col < cols; col++)
            {
                std::cout << csvData.GetCell<std::string>(col, row) << '\t';
            }

            std::cout << '\n';
        }
    
}