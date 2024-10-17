#include "utils.h"
#include <iostream>
#include <fstream>

bool fileExists(const std::string &filePath)
{
    bool fileExists = false;
    std::ifstream file(filePath);
    if (file)
    {
        fileExists = true;
    }
    return fileExists;
}

std::string getFileExtension(std::string &filePath)
{
    std::string extension = "";
    bool dotFound = false;

    for (int i = filePath.length() - 1; i >= 0; i--)
    {
        if (filePath[i] == '.')
        {
            dotFound = true;
            break;
        }
        extension = filePath[i] + extension;
    }
    return dotFound ? extension : "";
}

bool validateCmdArgument(int argc)
{
    bool isValid = true;
    if (argc < 2)
    {
        std::cout << "Please enter the file Path\n";
        isValid = false;
    }
    else if (argc > 2)
    {
        std::cout << "Invalid input!!!, Please enter only filePath\n";
        isValid = false;
    }
    return isValid;
}

std::ifstream openFile(const std::string &filePath)
{
    std::ifstream file(filePath);
    if (!file)
    {
        throw std::runtime_error("Failed to open the file.");
    }
    return file;
}
