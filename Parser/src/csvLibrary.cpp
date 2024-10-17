#include "csvLibrary.h"

rapidcsv::Document CsvLibrary::parse(std::ifstream &csvFile)
{
    return rapidcsv::Document(csvFile, rapidcsv::LabelParams(-1, -1));
}
