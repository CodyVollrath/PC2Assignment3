#include "FileLoader.h"
namespace datatier
{
FileLoader::FileLoader(const string& fileName)
{
    this->fileName = fileName;
}

FileLoader::~FileLoader()
{
    //dtor
}

void FileLoader::changeFileName(const string& newFileName)
{
    this->fileName = newFileName;
}

string FileLoader::getFileName() const
{
   return this->fileName;
}

string FileLoader::loadFile() const
{
    string fileData;
    string line;
    ifstream file(this->fileName);
    if (file.is_open()) {
        while (getline(file, line)) {
            fileData += line + "\n";
        }
    }
    return fileData;
}
}

