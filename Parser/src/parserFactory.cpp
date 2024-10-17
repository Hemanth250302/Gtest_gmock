#include "parserFactory.h"
#include "jsonParser.h"
#include "csvParser.h"
#include "xmlParser.h"
#include "csvLibrary.h"
#include "xmlLibrary.h"
#include "jsonLibrary.h"

IParser *ParserFactory::createParser(const std::string &fileType)
{
    if (fileType == "json")
    {
        IJsonLibrary *jsonLib=new JsonLibrary();
        return new JsonParser(jsonLib);
    }
    else if (fileType == "csv")
    {
        ICsvLibrary *csvLib = new CsvLibrary();
        return new CsvParser(csvLib);
    }
    else if (fileType == "xml")
    {
        IXmlLibrary *xmlLib = new XmlLibrary();
        return new XmlParser(xmlLib);
    }
    else
    {
        throw std::invalid_argument("unsupported Filetype:" + fileType);
    }
}