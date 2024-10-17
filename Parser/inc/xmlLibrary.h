#ifndef XMLLIBRARY_H
#define XMLLIBRARY_H

#include "pugixml.h"
#include "IXmlLibrary.h"

class XmlLibrary : public IXmlLibrary
{

public:
    pugi::xml_parse_result parse(std::ifstream &xmlFile) override;
};

#endif