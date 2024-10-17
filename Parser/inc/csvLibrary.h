#ifndef CSVLIBRARY_H
#define CSVLIBRARY_H

#include "rapidCsv.h"
#include "ICsvLibrary.h"

class CsvLibrary : public ICsvLibrary
{

public:
    rapidcsv::Document parse(std::ifstream &csvFile)override;
};

#endif
