#ifndef ICsvLibrary_H
#define ICsvLibrary_H

#include "rapidCsv.h"

class ICsvLibrary
{

public:
     virtual ~ICsvLibrary() = default;
     virtual rapidcsv::Document parse(std::ifstream &csvFile) = 0;
};

#endif