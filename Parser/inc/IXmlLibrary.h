#ifndef IXmlLibrary_H
#define IXmlLibrary_H

#include "pugixml.h"

class IXmlLibrary
{

public:
     virtual ~IXmlLibrary() = default;
     virtual  pugi::xml_parse_result parse(std::ifstream &xmlFile) = 0;
};

#endif