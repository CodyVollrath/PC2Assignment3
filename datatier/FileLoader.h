#ifndef FILELOADER_H
#define FILELOADER_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

namespace datatier
{
/**
* The FileLoader deals with reading from files
* @author CodyVollrath
*/
class FileLoader
{
    public:
        /**
        * Initialize the FileLoader class
        * @param fileName the file to be read from
        */
        FileLoader(const string& fileName);
        virtual ~FileLoader();

        /**
        * Changes the file to be read from
        * @param newFileName the new file to be read from
        * @post getFileName() == newFileName
        */
        void changeFileName(const string& newFileName);

        /**
        * Gets the contents of the file
        * @return the contents of the file if it exists.
        */
        string loadFile() const;

        /**
        * Get the file name
        * @return the file name
        */
        string getFileName() const;

    protected:

    private:
        string fileName;
};
}


#endif // FILELOADER_H
