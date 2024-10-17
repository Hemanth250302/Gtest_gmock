#ifndef CSVPARSER_H
#define CSVPARSER_H

#include "Iparser.h"
#include "rapidCsv.h"
#include "ICsvLibrary.h"
#include <string>

class CsvParser : public IParser
{
    rapidcsv::Document csvData;
    ICsvLibrary *csvLibrary;

public:
    CsvParser(ICsvLibrary *csvLibrary);
    void parse(std::ifstream &csvFile) override;
    void print() override;
};

#endif