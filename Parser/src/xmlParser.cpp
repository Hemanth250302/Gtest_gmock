#include "xmlParser.h"
#include "xmlLibrary.h"
#include <iostream>
#include <fstream>
#include <stdexcept>

XmlParser::XmlParser(IXmlLibrary *xmlLibrary) : xmlLibrary(xmlLibrary) {}

void XmlParser::parse(std::ifstream &xmlFile)
{
    pugi::xml_parse_result result = xmlLibrary->parse(xmlFile);
    if (!result)
    {
        throw std::runtime_error("error while parsing XML file: " + std::string(result.description()));
    }

}

void XmlParser::print()
{
    std::cout << "XML Contents: " << std::endl;

    pugi::xml_node employeesNode = xmlData.child("employees");
    for (pugi::xml_node employee = employeesNode.child("employee"); employee; employee = employee.next_sibling("employee"))
    {
        std::cout << "Name: " << employee.child("name").text().as_string() << '\n';
        std::cout << "Age: " << employee.child("age").text().as_int() << '\n';
        std::cout << "Occupation: " << employee.child("occupation").text().as_string() << '\n';
        std::cout << "Salary: " << employee.child("salary").text().as_int() << '\n';
        std::cout << '\n' << '\n';
    }
}
