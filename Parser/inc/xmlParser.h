#ifndef XMLPARSER_H
#define XMLPARSER_H

#include "Iparser.h"
#include "pugixml.h"
#include "IXmlLibrary.h"
#include <string>

class XmlParser : public IParser
{
    pugi::xml_document xmlData;
     IXmlLibrary *xmlLibrary;

public:
    XmlParser(IXmlLibrary *XmlLibrary);
    void parse(std::ifstream &xmlFile) override;
    void print() override;
};

#endif