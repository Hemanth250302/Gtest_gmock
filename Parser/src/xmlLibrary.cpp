#include "pugixml.h"
#include "xmlLibrary.h"
#include <fstream>

pugi::xml_parse_result XmlLibrary::parse(std::ifstream &xmlFile)
{
    pugi::xml_document doc;
    return doc.load(xmlFile);
}
