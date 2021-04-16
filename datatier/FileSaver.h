#ifndef FILESAVER_H
#define FILESAVER_H

#include <fstream>
#include <string>
using namespace std;

namespace datatier
{
/**
* The FileSaver deals with saving to a file
* @author CodyVollrath
*/
class FileSaver
{
    public:
        /**
        * Creates an instance FileSaver
        * @param file the filename that will act as the file to be saved to
        */
        FileSaver(const string& file);
        /**
        * Deconstructs the FileSaver
        */
        virtual ~FileSaver();

        /**
        * Writes to the file that was entered from the constructor
        * @param data the data to be written to the file
        */
        void write(const string& data);

    protected:

    private:
        string outfile;
};
}


#endif // FILESAVER_H
