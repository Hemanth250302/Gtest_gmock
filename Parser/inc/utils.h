#ifndef UTILS_H
#define UTILS_H

#include <string>

bool fileExists(const std::string &filePath);
std::string getFileExtension(std::string &filePath);
bool validateCmdArgument(int argc);
std::ifstream openFile(const std::string &filePath);


#endif